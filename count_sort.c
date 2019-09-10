#include<stdio.h>
#include<stdlib.h>

void read(int* arr, int size)
{
	printf("Enter elements of array: ");
	for( int i=0; i<size; i++)
        	scanf("%d",&arr[i]);
}

void show(int* arr, int size)
{
	for( int i=0; i<size; i++)
        	printf("%d\t",arr[i]);
}

int max_number(int* arr, int size)
{
	int max_no = arr[0];
	for(int i=0; i<size; i++)
	{
		if( arr[i] > max_no )
			max_no = arr[i];
	}
	return max_no;
}

void counting_sort(int* arr, int size)
{
	int max = max_number(arr, size);
	int B[size], C[max+1];
	
	for(int i=0; i<size; i++)
		B[i] = 0;

	for(int i=0; i<=max; i++)
		C[i] = 0;

	for(int i=0; i<size; i++)
		C[arr[i]]++;

	for(int i=0; i<=max; i++)
		C[i] += C[i-1];

	for(int i=0; i<size; i++)
	{
		B[C[arr[i]] - 1] = arr[i];
		C[arr[i]]--;
	}
	show(B, size);
}

void main(void)
{
	unsigned int size;
	
	printf("Enter size of array: ");
	scanf("%u",&size);
	
	int *arr;
	arr = (int*) malloc( size * sizeof(int) );

	read(arr, size);
	printf("Input Array: ");	show(arr, size);
		
	counting_sort(arr, size);
	printf("Sorted Array: ");	
}
