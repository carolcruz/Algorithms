#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define char_to_index(c) ((int)c - (int)'a')

//Functions:

void divide(char array[], int low, int high);
void conquer(char array[], int low, int mid, int high);

void divide(char array[], int low, int high){

	if(high > low){
		int mid = low+(high-low)/2;
		divide(array, low, mid);
		divide(array, mid+1, high);
		conquer(array, low, mid, high);
	}
}

void conquer(char array[], int low, int mid, int high){

	int i=0, j=0, k=0;
	int n1=(mid-low+1), n2=(high-mid);

	char left[n1], right[n2];

	for(i=0; i<n1; i++){
		left[i] = array[low+i];
	}
	for(j=0; j<n2; j++){
		right[j] = array[mid+1+j];
	}

	i=0;
	j=0;
	k=low;

	while(i<n1 && j<n2){
		if(char_to_index(left[i]) < char_to_index(right[j])){
			array[k++] = left[i++];
		}
		else{
			array[k++] = right[j++];
		}
	}

	while(i<n1){
		array[k++] = left[i++];
	}

	while(j<n2){
		array[k++] = right[j++];
	}
}

void printArray(char A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%c ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    char arr[] = {'a', 'd', 'b', 'c', 'e'};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    divide(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}