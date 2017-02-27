#include<iostream>
using namespace std;

void MergeArray( int A[], int first, int mid, int last, int Tmp[] )
{
	int i = first, j = mid+1;
	int m = mid, n = last;
	int k=0;
	while( i<=m && j<=n )
	{
		if( A[i]<=A[j])
			Tmp[k++]=A[i++];
		else
			Tmp[k++]=A[j++];
	}
	while(i<=m)
		Tmp[k++] = A[i++];
	while(j<=n)
		Tmp[k++] = A[j]++;
	for( i=0; i<k; i++)
		A[first+i] = Tmp[i];
}

void mergesort( int A[], int first, int last, int Tmp[] )
{
	if( first < last )
	{
		int mid = ( first + last ) / 2;
		mergesort( A, first, mid, Tmp );
		mergesort( A, mid+1, last, Tmp );
		MergeArray( A, first, mid, last, Tmp );
	}
}
void MergeSort( int A[], int N )
{
	int *Tmp;
	Tmp = new int[N];
	if( Tmp != NULL )
	{
		mergesort( A, 0, N-1, Tmp );
	}
	else
		cout<<"空间不足"<<endl;
	delete []Tmp;
}

int main()
{
	int A[5]={ 5,2,9,4,7 };
	int N=5;
	MergeSort( A, N );
	for ( int i=0; i<N; i++ )
	{
		cout<< A[i]<<" ";
	}
	cout<<endl;
}