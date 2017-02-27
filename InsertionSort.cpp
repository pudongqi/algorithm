#include<iostream>
using namespace std;

void InsertionSort( int A[], int N )
{
	int P,i;
	int Tmp;
	for( P=1; P<N; P++ )
	{
		Tmp = A[P];
		for( i=P; i>0 && A[i-1]>Tmp; i-- )
		{
			A[i] = A[i-1];
		}
		A[i] = Tmp;
	}
}

int main()
{
	int A[5]={ 5,2,9,4,7 };
	int N=5;
	InsertionSort( A, N );
	for ( int i=0; i<N; i++ )
	{
		cout<< A[i]<<" ";
	}
	cout<<endl;
}