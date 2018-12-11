#include <stdio.h>
#include <iostream>
 // Recursive procedure
 // 2-way merge sort is iterative procedure
 // 2 list are taken at a time and merged.
 
 //https://hackr.io/blog/merge-sort-in-c
 
void merge(int arr[],int low,int mid,int high){
	int c[10] ={0};
	printf("inside merge\n"); 

	int i = 0 ,j = 0 ,k=0;
	
	while(i < mid && j < high){
		if (arr[i] < arr[j]){
			c[k++] = arr[i++] ;
		}
		else{
			c[k++] = arr[j++];
		}

	}
	//copy remaining elements of the left list 
	while(i < low){
		c[k++] = arr[i++];
	}
	//copy remaining elements of the Right list 
	while(j < high){
		c[k++] = arr[j++];
	}
	int f = 0;
	for (f=0; f < 10; f++) 
        printf("%d ", c[f]); 
    printf("\n"); 

}

void merge_sort(int arr[],int low ,int high )
{
	int mid ;

	if (low < high){
		
		mid =(high+low)/2;	
		//printf("low  %d\n",low); 
	//	printf("mid  %d\n",mid); 
		
		merge_sort(arr,low,mid); //left recursion 
	//	printf("\n\n"); 
	//	printf("mid+1  %d\n",mid+1); 
	//	printf("high  %d\n",high); 
		
	
		merge_sort(arr,mid+1,high);//Right recursion 
	  // printf("low  %d\n",low); 
	   //printf("mid  %d\n",mid); 
	   //printf("high  %d\n",high); 
	
		merge(arr,low,mid,high);
	}
	
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main (){
	
	int arr[]    = {7,4,5,8,10,8,1,3,5,9};
	int *result  = new int[sizeof (arr)/sizeof(arr[0])];
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	int i =0;
    printf("Given array is arr_size %d\n",arr_size); 
    printArray(arr, arr_size); 
  
    merge_sort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
   // printArray(c, arr_size); 

	return 0;
}