#include<iostream>
using namespace std;

int BruteForce( char *S, char *P )
{
	int i=0, j;
	while( i<strlen(S) )
	{
		j=0;
		while( S[i]==P[j] && j<strlen(P) )
		{
			i++;
			j++;
		}
		if( j==strlen(P) )
			return i-strlen(P);
		i=i-j+1;
	}
	return -1;
}

int main()
{
	char P[] = "CCNU";
	char S[] = "hubei,CCNU,wuhan";
	cout<<endl;
	int index = BruteForce( S, P );
	cout<<index<<endl;
	return 0;
}