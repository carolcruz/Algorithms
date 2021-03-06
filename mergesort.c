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

void print(char array[], int lenght)
{
    int i;
    for (i=0; i < lenght; i++)
        printf("%c ", array[i]);
    printf("\n");
}

int main()
{
    char array[] = {'a', 'd', 'b', 'c', 'e'};
    int lenght = sizeof(array)/sizeof(array[0]);
 
    printf("Given:\n");
    print(array, lenght);
 
    divide(array, 0, lenght-1);
 
    printf("\nSorted:\n");
    print(array, lenght);
    return 0;
}
