#include <stdio.h>

void bubbleSort(int array[], int size, int ascending){
   for(int i = 0; i < size; i++) {
      int swaps = 0;
      for(int j = 0; j < size - i - 1; j++) {
         if(ascending ? (array[j] > array[j+1]) : (array[j] < array[j+1])) {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            swaps = 1;
         }
      }
      if(!swaps) break;
   }
}

int main(){
   int n;
   printf("Dizinin eleman sayisini girin: ");
   scanf("%d", &n);

   int arr[n];
   printf("Dizinin elemanlarini girin:\n");
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   int choice;
   printf("Siralamayi secin (1 = artan, 0 = azalan): ");
   scanf("%d", &choice);

   printf("Siralamadan once: ");
   for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   bubbleSort(arr, n, choice);

   printf("Siralamadan sonra: ");
   for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   return 0;
}
