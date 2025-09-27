#include <string>					
#include <iostream>					
using namespace std;

struct DoublyLinkedList;

struct DoublyNode
{
	int score;												// element score;
	DoublyNode* next;										// pointer to the next item in the list
	DoublyNode* prev;										// pointer to the previous item in the list
	DoublyLinkedList* down;									// pointer to the doubly linked list node of sub level
};

struct DoublyLinkedList
{
	DoublyNode* header;										// pointer to the header of list
	DoublyNode* trailer;									// pointer to the trailer of list
	DoublyNode* up;											// pointer to the upper node that has down pointer
	int n;

	DoublyLinkedList();

	void		insertOrdered(const int& i);
	int			hNextScr(int);
	DoublyNode* downPtr(int);
};

DoublyLinkedList::DoublyLinkedList()
{
	header = new DoublyNode;
	trailer = new DoublyNode;
	header->score = 0;
	trailer->score = 0;

	DoublyNode* downNode = new DoublyNode;
	downNode->score = -1;
	downNode->down = NULL;

	downNode->prev = header;
	downNode->next = trailer;

	header->next = downNode;
	trailer->prev = downNode;

	up = NULL;
	n = 0;
}

void DoublyLinkedList::insertOrdered(const int& i)
{
	DoublyNode* newNode = new DoublyNode;
	newNode->score = i;

	DoublyNode* downNode = new DoublyNode;
	downNode->score = -1;
	downNode->down = NULL;

	DoublyNode* current = header->next->next;
	while (current != trailer)
	{
		if (newNode->score >= current->score)
			current = current->next->next;
		else
			break;
	}

	// newNode -> downNode -> current 
	newNode->next = downNode;
	downNode->prev = newNode;

	current->prev->next = newNode;
	newNode->prev = current->prev;

	downNode->next = current;
	current->prev = downNode;

	n++;
}

int DoublyLinkedList::hNextScr(int e)
{
	if (e == 1) return header->next->next->score;

	if (e == 2) return header->next->next->next->next->score;

	if (e == 3) return header->next->next->next->next->next->next->score;
}

DoublyNode* DoublyLinkedList::downPtr(int e)
{
	if (e == 1) return header->next;

	if (e == 2) return header->next->next->next;

	if (e == 3) return header->next->next->next->next->next;

	if (e == 4) return header->next->next->next->next->next->next->next;
}


struct Tree_234
{
	DoublyLinkedList* root;									// pointer to the root

	Tree_234();												// constructor
	void insert(int e);
	void remove(DoublyNode* p, int e);						// Eklenecek ...
	void inorder(DoublyLinkedList* v) const;				// inorder traversal of 2-3-4 Tree
};

void Tree_234::insert(int i)
{
	DoublyLinkedList* p;

	if (root == NULL)
	{
		root = new DoublyLinkedList;
		root->insertOrdered(i);
		return;
	}

	p = root;
	DoublyLinkedList* parent = NULL;

	while (true)
	{
		if (p->n == 3)	// Eğer 3 eleman varsa parçala
		{
			DoublyLinkedList* pLeft = new DoublyLinkedList;
			pLeft->insertOrdered(p->hNextScr(1));

			DoublyLinkedList* pRight = new DoublyLinkedList;
			pRight->insertOrdered(p->hNextScr(3));

			if (p->downPtr(1)->down != NULL)	// H->[*]->[(1)]->[*]->[(2)]->[*]->[(3)]->[*]->T
			{									//     v
				pLeft->downPtr(1)->down = p->downPtr(1)->down;
				pLeft->downPtr(1)->down->up = pLeft->downPtr(1);
			}

			if (p->downPtr(2)->down != NULL)	// H->[*]->[(1)]->[*]->[(2)]->[*]->[(3)]->[*]->T
			{									//                 v
				pLeft->downPtr(2)->down = p->downPtr(2)->down;
				pLeft->downPtr(2)->down->up = pLeft->downPtr(2);
			}

			if (p->downPtr(3)->down != NULL)	// H->[*]->[(1)]->[*]->[(2)]->[*]->[(3)]->[*]->T
			{									//                             v                  
				pRight->downPtr(1)->down = p->downPtr(3)->down;
				pRight->downPtr(1)->down->up = pRight->downPtr(1);
			}

			if (p->downPtr(4)->down != NULL)	// H->[*]->[(1)]->[*]->[(2)]->[*]->[(3)]->[*]->T
			{									//                                         v
				pRight->downPtr(2)->down = p->downPtr(4)->down;
				pRight->downPtr(2)->down->up = pRight->downPtr(2);
			}

			if (p->up == NULL)	// 3 elemanlı olan root ise yukarıya DoublyLinkedList ekle
			{
				DoublyLinkedList* pUpper = new DoublyLinkedList;			// pUpper : DoublyLinkedList'e pointer
				pUpper->insertOrdered(p->hNextScr(2));						// 3 elemanlı listeden ortadakini (2.) yukarıdaki listeye ekle
				root = pUpper;

				pUpper->downPtr(1)->down = pLeft;
				pLeft->up = pUpper->downPtr(1);

				pUpper->downPtr(2)->down = pRight;
				pRight->up = pUpper->downPtr(2);

				DoublyLinkedList* temp = p;
				if (i < pUpper->hNextScr(1))
					p = pLeft;
				else
					p = pRight;

				delete temp;
			}
			else  // 3 elemanlı olan root değilse yukarıya DoublyNode ekle
			{
				parent->insertOrdered(p->hNextScr(2));						// 3 elemanlı listeden ortadakini (2.) yukarıdaki listeye ekle

				DoublyNode* pUpper = p->up;									// pUpper : DoublyNode'a pointer						

				pUpper->down = pLeft;						// Ortadaki yukarıya çıkınca pUpper onun solundaki (down pointerı tutan) boş düğüme işaret eder. 						
				pLeft->up = pUpper;						// Örnek : insert(1) ve insert(9) için insertOrdered(4) ve insertOrdered(12)'ye bakınız:
				// insert(1) : H->[*pUpper]->[4]->[*]->[8]->[*]->T,  insert(9) : H->[*]->[4]->[*]->[8]->[*pUpper]->[12]->[*]->T
				pUpper->next->next->down = pRight;						// Yukarı çıkanın sağındaki (down pointerı tutan) boş düğüm (insertOrdered() 55. satıra bakınız).
				pRight->up = pUpper->next->next;

				DoublyLinkedList* temp = p;
				if (i < pUpper->next->score)
					p = pLeft;
				else
					p = pRight;

				delete temp;
			}
		}
		else	// 3 eleman yoksa i'nin ekleneceği yeri aramaya devam et.
		{
			DoublyNode* temp = p->header->next;

			while ((i > temp->next->score) && (temp->next != p->trailer))
				temp = temp->next->next;

			parent = p;

			if (temp->down != NULL)
				p = temp->down;
			else
			{
				p->insertOrdered(i);
				return;
			}
		}
	}
}

// remove() fonksiyonu uzun süre Serbest Ödev olarak kaldı.
// 2023-2024 Güz'de, öğrencimiz Ertuğrul TURAN ödevi yaptı. 
void Tree_234::remove(DoublyNode* p, int e)       //p root'tun header'ına işaret eder. p = root->header;
{
	//
	// 2 - 3 - 4 Ağacından Düğüm Silme Algoritması
	//
	// • Çocuksuz ise direkt sil.
	// • Çocuklu  ise KBEK (veya KKEB) düğümü yerine yaz ve sil.
	// 2 durumda da silinecek düğümü ararken (root hariç) 1 elemanlı düğüm 
	// için “sırasıyla” aşağıdaki kurallardan birini uygulamaya çalış :
	//   • Rule 1 : Kardeşten ödünç almaya çalış.
	//   • Rule 2 : Babadan ödünç almaya çalış ve 
	//		        [kardeş, babadan 1, kendin] 3 elemanlı bir düğüm oluştur.
	//   • Rule 3 : Baba tek elemanlı root ve kardeş de tek elemanlı ise
	//	            [kardeş, root, kendin] 3 elemanlı bir root düğüm oluştur. 
	//		        Bu durumda ağacın seviyesi 1 azalır.

	DoublyLinkedList* list = root;
	DoublyLinkedList* parent = root;  //list'in işaret ettiğinin babası.

	if (root == NULL || root->n == 0) cout << "2-3-4 Tree is empty!" << endl;
	else
	{
		p = p->next->next;
		while (true)
		{
			for (int i = 0; i < list->n; i++)                 //  ----> KBEK ugulanırken p nin NULL olmaması için.
			{                                                 // |
				if (p->score == e) { break; }                 // |
				else if (p->score < e && p != list->trailer && p != parent->trailer) p = p->next->next;
				else
				{
					parent = list;
					list = p->prev->down; if (list == NULL) break;  //Eğer düğüm bulunamazsa
					p = list->header->next->next;
				}
			}
			if (list == NULL) { cout << endl << endl << e << " not found!" << endl; break; }

			if (list != root && list->n == 1)
			{
				DoublyLinkedList* temp1 = NULL;   //Left child.
				DoublyLinkedList* temp2 = NULL;   //Right child.

				//Rule 1
				if (list->up->prev != parent->header && list->up->prev->prev->down != NULL && list->up->prev->prev->down->n > 1) //Sol kardeşi var mı ve eleman sayısı > 1 mi?
				{
					DoublyNode* temp = list->up->prev->prev->down->downPtr(list->up->prev->prev->down->n)->next; //Sol kardeşin max düğümü.
					temp1 = list->downPtr(1)->down;

					list->insertOrdered(list->up->prev->score);

					list->up->prev->score = temp->score;

					list->downPtr(1)->down = temp->next->down;  //Eğer temp'in sağ çocuğu varsa kardeşinin sol çocuğu olacak.
					if (temp->next->down != NULL) temp->next->down->up = list->downPtr(1);

					list->downPtr(2)->down = temp1; if (temp1 != NULL) temp1->up = list->downPtr(2);  //insertOrdered esnasında down pointerı kaydığından 

					list->up->prev->prev->down->downPtr(list->up->prev->prev->down->n)->next = list->up->prev->prev->down->trailer;
					list->up->prev->prev->down->trailer->prev = list->up->prev->prev->down->downPtr(list->up->prev->prev->down->n);

					delete temp->next;
					delete temp;

					list->up->prev->prev->down->n--;
				}
				else if (list->up->next != parent->trailer && list->up->next->next->down != NULL && list->up->next->next->down->n > 1) //Sağ kardeşi var mı ve eleman sayısı > 1 mi?
				{
					DoublyNode* temp = list->up->next->next->down->downPtr(1)->next; //Sağ kardeşin min düğümü.

					list->insertOrdered(list->up->next->score);

					list->up->next->score = temp->score;

					list->downPtr(3)->down = temp->prev->down;  //Eğer temp'in sol çocuğu varsa kardeşinin sağ çocuğu olacak.
					if (temp->prev->down != NULL) temp->prev->down->up = list->downPtr(3);

					list->up->next->next->down->header->next = list->up->next->next->down->downPtr(2);
					list->up->next->next->down->downPtr(1)->prev = list->up->next->next->down->header;

					delete temp->prev;
					delete temp;

					list->up->next->next->down->n--;
				}
				//Rule 2
				else if (parent->n > 1)  //Babasının eleman sayısı > 1 mi?
				{
					if (list->up == parent->downPtr(1) || list->up == parent->downPtr(2))
					{
						temp1 = parent->downPtr(1)->down;  //Left child.
						temp2 = parent->downPtr(2)->down;  //Right child.

						list = new DoublyLinkedList;

						list->insertOrdered(temp1->hNextScr(1));
						list->insertOrdered(parent->hNextScr(1));
						list->insertOrdered(temp2->hNextScr(1));

						list->downPtr(1)->down = temp1->downPtr(1)->down; if (temp1->downPtr(1)->down != NULL) temp1->downPtr(1)->down->up = list->downPtr(1);
						list->downPtr(2)->down = temp1->downPtr(2)->down; if (temp1->downPtr(2)->down != NULL) temp1->downPtr(2)->down->up = list->downPtr(2);
						list->downPtr(3)->down = temp2->downPtr(1)->down; if (temp2->downPtr(1)->down != NULL) temp2->downPtr(1)->down->up = list->downPtr(3);
						list->downPtr(4)->down = temp2->downPtr(2)->down; if (temp2->downPtr(2)->down != NULL) temp2->downPtr(2)->down->up = list->downPtr(4);

						parent->header->next = temp2->up;
						temp2->up->prev = parent->header;
						temp2->up->down = list;
						list->up = temp2->up;
						parent->n--;
					}
					else
					{
						temp1 = parent->trailer->prev->prev->prev->down;  //Left child.
						temp2 = parent->trailer->prev->down;              //Right child.

						list = new DoublyLinkedList;

						list->insertOrdered(temp1->hNextScr(1));
						list->insertOrdered(parent->trailer->prev->prev->score);
						list->insertOrdered(temp2->hNextScr(1));

						list->downPtr(1)->down = temp1->downPtr(1)->down; if (temp1->downPtr(1)->down != NULL) temp1->downPtr(1)->down->up = list->downPtr(1);
						list->downPtr(2)->down = temp1->downPtr(2)->down; if (temp1->downPtr(2)->down != NULL) temp1->downPtr(2)->down->up = list->downPtr(2);
						list->downPtr(3)->down = temp2->downPtr(1)->down; if (temp2->downPtr(1)->down != NULL) temp2->downPtr(1)->down->up = list->downPtr(3);
						list->downPtr(4)->down = temp2->downPtr(2)->down; if (temp2->downPtr(2)->down != NULL) temp2->downPtr(2)->down->up = list->downPtr(4);

						parent->trailer->prev = temp1->up;
						temp1->up->next = parent->trailer;
						temp1->up->down = list;
						list->up = temp1->up;
						parent->n--;
					}

					if (!(parent->n > 1 && (p->score == parent->hNextScr(1) || p->score == parent->hNextScr(2)))) //Eğer 'e' parent'ın ilk ya da son elemanı ise p yeni oluşturlmuş list'e inmeli.
						p = list->header->next->next;                                                             //Değilse inemez. Çünkü Rule 2 sonucunda (varsa) orta eleman hala yukarıdadır.

					delete temp1;
					delete temp2;
				}
				//Rule 3
				else if (parent == root && parent->downPtr(1)->down->n == 1 && parent->downPtr(2)->down->n == 1)
				{
					p = list->header;

					DoublyNode* temp1 = parent->downPtr(1)->down->downPtr(1)->next;    //Left child.
					DoublyNode* temp2 = parent->downPtr(2)->down->header->next->next;  //Right child.

					parent->insertOrdered(temp1->score);
					parent->insertOrdered(temp2->score);

					parent->downPtr(1)->down = temp1->prev->down; if (temp1->prev->down != NULL) temp1->prev->down->up = parent->downPtr(1);
					parent->downPtr(2)->down = temp1->next->down; if (temp1->next->down != NULL) temp1->next->down->up = parent->downPtr(2);
					parent->downPtr(3)->down = temp2->prev->down; if (temp2->prev->down != NULL) temp2->prev->down->up = parent->downPtr(3);
					parent->downPtr(4)->down = temp2->next->down; if (temp2->next->down != NULL) temp2->next->down->up = parent->downPtr(4);

					list = parent;
					p = list->header->next->next;

					delete temp1;
					delete temp2;
				}
			}
			if (p->score == e)  //Artık e değeri silinebilir.
			{
				if (p->prev->down != NULL || p->next->down != NULL) //Çocuklu mu? Öyleyse KBEK.
				{
					DoublyNode* temp = p;

					if (p->next->down != NULL)  //Sağ çocuk var mı?
					{
						parent = list;
						list = temp->next->down;
						temp = temp->next->down->header->next->next;

						if (list->n == 1) continue;

						if (temp->prev->down != NULL)
						{
							parent = list;
							list = temp->prev->down;
							temp = temp->prev->down->header->next->next;
						}

						if (list->n == 1) continue;

						p->score = temp->score;
						temp->prev->prev->next = temp->next;
						temp->next->prev = temp->prev->prev;

						delete temp->prev;
						delete temp;

						list->n--;
					}
				}
				else
				{
					p->prev->prev->next = p->next;
					p->next->prev = p->prev->prev;

					delete p->prev;
					delete p;

					list->n--;
				}

				break;    //Silme işlemi tamamlandı.
			}
		}
	}
}

// inorder traversal of 2-3-4 tree
void Tree_234::inorder(DoublyLinkedList* v) const
{
	if (v->header->next->down != NULL)								        	inorder(v->header->next->down);

	cout << v->header->next->next->score << " ";

	if (v->header->next->next->next->down != NULL)					        	inorder(v->header->next->next->next->down);

	if (v->n > 1) cout << v->header->next->next->next->next->score << " ";

	if (v->n > 1)
		if (v->header->next->next->next->next->next->down != NULL)	        	inorder(v->header->next->next->next->next->next->down);

	if (v->n > 2) cout << v->header->next->next->next->next->next->next->score << " ";

	if (v->n > 2)
		if (v->header->next->next->next->next->next->next->next->down != NULL)	inorder(v->header->next->next->next->next->next->next->next->down);
}

Tree_234::Tree_234()
{
	root = NULL;
}

void main()
{
	Tree_234 tree_234;

	tree_234.insert(16);
	tree_234.insert(8);
	tree_234.insert(24);
	tree_234.insert(4);
	tree_234.insert(12);
	tree_234.insert(20);
	tree_234.insert(28);
	tree_234.insert(2);
	tree_234.insert(6);
	tree_234.insert(10);
	tree_234.insert(14);
	tree_234.insert(18);
	tree_234.insert(22);
	tree_234.insert(26);
	tree_234.insert(30);
	tree_234.insert(1);
	tree_234.insert(3);
	tree_234.insert(5);
	tree_234.insert(7);
	tree_234.insert(9);
	tree_234.insert(11);
	tree_234.insert(13);
	tree_234.insert(15);
	tree_234.insert(17);
	tree_234.insert(19);
	tree_234.insert(21);
	tree_234.insert(23);
	tree_234.insert(25);
	tree_234.insert(27);
	tree_234.insert(29);
	tree_234.insert(31);

	cout << "2-3-4 Tree Inorder Traversal :" << endl;
	tree_234.inorder(tree_234.root);
	cout << endl << endl;

	tree_234.remove(tree_234.root->header, 18);
	tree_234.remove(tree_234.root->header, 1);
	tree_234.remove(tree_234.root->header, 5);
	tree_234.remove(tree_234.root->header, 22);
	tree_234.remove(tree_234.root->header, 6);
	tree_234.remove(tree_234.root->header, 16);
	tree_234.remove(tree_234.root->header, 7);
	tree_234.remove(tree_234.root->header, 15);
	tree_234.remove(tree_234.root->header, 19);
	tree_234.remove(tree_234.root->header, 20);
	tree_234.remove(tree_234.root->header, 26);
	tree_234.remove(tree_234.root->header, 31);
	tree_234.remove(tree_234.root->header, 17);
	//tree_234.remove(tree_234.root->header, 35);  //Not found.
	tree_234.remove(tree_234.root->header, 12);
	tree_234.remove(tree_234.root->header, 14);
	tree_234.remove(tree_234.root->header, 3);
	//tree_234.remove(tree_234.root->header, 18);  //Not found.
	tree_234.remove(tree_234.root->header, 4);
	tree_234.remove(tree_234.root->header, 9);
	tree_234.remove(tree_234.root->header, 21);
	tree_234.remove(tree_234.root->header, 27);
	tree_234.remove(tree_234.root->header, 28);
	tree_234.remove(tree_234.root->header, 29);
	tree_234.remove(tree_234.root->header, 30);
	tree_234.remove(tree_234.root->header, 25);
	tree_234.remove(tree_234.root->header, 11);
	tree_234.remove(tree_234.root->header, 13);

	cout << "2-3-4 Tree Inorder Traversal :" << endl;
	tree_234.inorder(tree_234.root);
	cout << endl << endl;

	tree_234.remove(tree_234.root->header, 2);
	tree_234.remove(tree_234.root->header, 8);
	tree_234.remove(tree_234.root->header, 23);
	tree_234.remove(tree_234.root->header, 24);
	tree_234.remove(tree_234.root->header, 10);
	tree_234.remove(tree_234.root->header, 29);   //Tree is empty!

	getchar();
}
