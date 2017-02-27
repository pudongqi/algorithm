#include<iostream>
using namespace std;
void QuickSort( int A[], int Left, int Rigth )
{
	if( Left<Rigth )
	{
		int i = Left;
		int j = Rigth;
		int x = A[i];
		while( i<j )
		{
			while( i<j && A[j] >= x )
				j--;
			if( i<j )
				A[i++] = A[j];
			while( i<j && A[i] <x )
				i++;
			if( i<j )
				A[j--] = A[i];
		}
		A[i] = x;
		QuickSort( A, Left, i-1 );
		QuickSort( A, i+1, Rigth );
	}
}
int main()
{
	int A[5]={ 5,2,9,4,7 };
	int N=5;
	QuickSort( A, 0, 4 );
	for ( int i=0; i<N; i++ )
	{
		cout<< A[i]<<" ";
	}
	cout<<endl;
}