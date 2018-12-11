
//Finding kth element in an array


/*
The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), 
it recurs only for the part that contains the k-th smallest element. 
Logic :
if index of partitioned element is more than k, then we recur for left part.
If index is same as k, we have found the k-th smallest element and we return. 
If index is less than k, then we recur for right part. 

Complexity - This reduces the expected complexity from O(n log n) to O(n), with a worst case of O(n^2).


*/
#include <stdio.h>
#include <iostream>

	int arr[]    = {4,5,3,1};
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int Lomuto_Partition( int p, int r) {
	int pivotPoint = p ;
	int pivotValue= arr[pivotPoint];
	int j = pivotPoint ;
	//Move all the smaller element than pivotValue to left
	for (int i = j + 1; i <= r; ++i) {
		if (arr[i] < pivotValue) { //Got a smaller element than pivot Value
			j++ ;
			swap(&arr[j], &arr[i]) ;
		}
	}
	swap(&arr[j], &arr[pivotPoint]) ;
	pivotPoint = j ;
	return pivotPoint ;
}


int quickSelect(int k, int p, int r) {
	
	while (true) {
		    printf("quickSelect (k %d , p %d , r %d) \n",k,p,r); 

		if (p <= r) {
			int j = Lomuto_Partition(p, r);
			printf("After Lomuto_Partition j %d  \n",j); 
  			 printArray(arr, arr_size); 

			if (k == j) {
				return arr[k];
			}
			else if (k < j) {
				r = j - 1;
			}
			else {
				p = j + 1;
			}
		}
	}
}


int main (){
	
	int *result  = new int[sizeof (arr)/sizeof(arr[0])];

	int i =0;
	int k = 3; //Find the 5th smallest element in an array 
	
    printf("Given array is arr_size %d ,Now find %d th smallest element in the array \n",arr_size,k); 
    printArray(arr, arr_size); 
  	if (k > arr_size-1) return 0;
    int array_value  = quickSelect(k , 0, arr_size - 1); 
    printf("%d th element smallest in the array is %d \n",k,array_value); 

   // printArray(c, arr_size); 
	
	return 0;
}