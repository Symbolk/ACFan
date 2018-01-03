#include<iostream>
using namespace std;
const int N = 20000; 
int A[N];
int n;
void Merge( int p,int q,int r) ;
void MergeSort( int p,int r) ;
int res;

int main(void)
{
	//freopen("in.txt","r",stdin) ;

	while(cin>>n&&n)
	{
		res=0;
		for(int i = 0 ; i < n ; i++)
		{
			cin>>A[i] ;
		}

		MergeSort( 0,n-1) ; 
		cout<<res<<endl;
	}		
	return 0 ;
}


void MergeSort( int l,int r) 
{
	//left mid right
	int m = 0 ;

	if(l < r)
	{
		m = (l+r)/2 ; 
		MergeSort(l,m) ;
		MergeSort(m+1,r) ;
		Merge( l,m,r) ;
	}
}

void Merge(int p, int q, int r)
{
	int L[N], R[N] ;
	int i,j,k ;
	int nLeft,nRight ;

	nLeft = q + 1 - p ;
	nRight = r - q ;

	for(i = 0 ; i < nLeft ; ++i )
	{
		L[i] = A[p+i] ;
	}

	for(j = 0 ; j < nRight ; ++j)
	{
		R[j] = A[q+j+1] ;
	}

	i = 0 ;
	j = 0 ;
	//merge the two parts 
	for(k = p ; k < r && i<nLeft && j<nRight ; k++ )
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i] ; 	
			i++ ;
		}
		else
		{
			res+=nLeft-i;//get the inversion pair numbers
			A[k] = R[j] ; 
			j++ ;
		}
	}
	//copy the remaining nums
	if(i >= nLeft)
	{
		for(; k <= r ; ++k,++j) 
		{
			A[k] = R[j] ;
		}
	}
	else
	{
		for(; k <= r ; ++k,++i)
		{
			A[k] = L[i] ;
		}
	}
}
