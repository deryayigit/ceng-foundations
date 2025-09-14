/*
Time Complexity: 
-Worst Case -> O(n^2)
-Best Case -> O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

void bubbleSort(int array[], int size, int ascending){
   for(int i = 0; i < size - 1; i++) {
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
   printf("Please Enter the Number of Elements in The Array : ");
   scanf("%d", &n);

   int arr[n];
   printf("Please Enter Element of Array : \n");
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   int choice;
   printf("Select sort (1 = ascending, 0 = descending): ");
   scanf("%d", &choice);

   printf("Before Sorting : ");
   for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   bubbleSort(arr, n, choice);

   printf("After Sorting : ");
   for(int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   return 0;
}



