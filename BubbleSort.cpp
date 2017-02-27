#include<iostream>
using namespace std;

void BubbleSort( int A[], int N )
{
	for ( int p=N-1; p>=0; p-- )
	{
		int flag = 0;
		int Tmp = 0;
		for ( int i=0; i<p; i++ )
		{
			if ( A[i]>A[i+1] )
			{
				Tmp = A[i];
				A[i] = A[i+1];
				A[i+1] = Tmp;
				flag = 1;
			}
		}
		if( flag==0 )
		{
			break;
		}
	}
}

int main()
{
	int A[5]={ 5,2,9,4,7 };
	int N=5;
	BubbleSort( A, N );
	for ( int i=0; i<N; i++ )
	{
		cout<< A[i]<<" ";
	}
	cout<<endl;
}