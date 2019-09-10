#include<stdio.h>
#include<stdlib.h>

int a[10], low, high;

int partition( int a[], int low, int high )
{
	int pivot = a[high];
	int i = low-1;
	int temp;
	
	for( int j=low; j<=high-1; j++ )
	{
		if ( a[j] <= pivot )
		{
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
	a[high] = a[i+1];
	a[i+1] = temp;
	
	return (i+1);
}

void quickSort( int a[], int low, int high )
{
	if( low < high )
	{
		int pi = partition( a, low, high );
		quickSort( a, low, pi-1 );
		quickSort( a, pi+1, high );
	}
}	

void main()
{
	for( int i=0; i<=6 ; i++ )
		scanf("%d",&a[i]);
	quickSort( a, 0, 6 );
	for( int i=0; i<=6 ; i++ )
		printf("%d\t",a[i]);	
}	
