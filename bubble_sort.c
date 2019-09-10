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

void bubble_sort(int* arr, int size)
{
	for(int i=0; i<size; i++)
	{
		unsigned int xchanges = 0;
		
		for(int j=0; j<size-i-1; j++)
		{
			if( arr[j] > arr[j+1] )
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}
		if( xchanges == 0 )
			break;
	}
}

void main(void)
{
	unsigned int size;
	
	printf("Enter size of array: ");
	scanf("%u",&size);
	
	int *arr;
	arr = (int*) malloc( size * sizeof(int) );

	read( arr, size );
	bubble_sort( arr, size );
	printf("Sorted Array : ");
 	show( arr, size );
}
	
