#include<iostream>
using namespace std;

/* 移动位数 = 已匹配的字符数 - 对应的部分匹配值 */

void GetNext( char *P, int *next )//求模式P的next值
{
	int i, j, len;
	next[0] = -1;
	for( j = 1; P[j] != '\0'; j++ )//依次求next[j]
	{
		for( len = j-1; len >= 1; len-- )//相等字串的最大长度为j-1;
		{
			for( i = 0; i < len; i++ )//依次比较P[0]~P[ len-1 ]与P[ j-len ]~P[ j-1 ]
				if( P[ i ] != P[ j-len+i ] )
					break;
			if( i == len )
			{
				next[ j ] = len;
				break;
			}
		}
	if( len<1 )
		next[ j ] = 0;//其他情况,无相等字串
	}
}

int KMP( char *S, char *P )//求P在S中的序号
{
	int i = 0;
	int j = 0;
	int next[80];
	GetNext( P, next );
	while( S[i] !='\0' && P[ j ] != '\0')
	{
		if( S[i] == P[j])
		{
			i++;
			j++;
		}
		else
		{
			 j = next[ j ];
			 if( j == -1 )
			 {
			 	i++;
			 	j++;
			 } 
		}
	} 
	if( P[j] == '\0' )
		return ( i - strlen(P) + 1 );//返回本趟匹配的开始位置
	else
		return 0;
}

int main()
{
	char P[] = "CCNU";
	char S[] = "hubei,CCNU,wuhan";
	int index = KMP( S, P );
	cout<<endl<<index<<endl;
	return 0;
}