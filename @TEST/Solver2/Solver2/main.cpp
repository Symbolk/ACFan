#include<iostream>
#include<fstream>

#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 25
using namespace std;

int h[maxn][maxn],r[maxn][maxn],l[maxn][maxn];
int n;
int maxr,maxl;
int Map[maxn][maxn];
int ans;

int main()
{
	//freopen("in2.txt","r",stdin);
	//ofstream outfile;
	//outfile.open("out2.txt");
	int m,n;
	while(cin>>m>>n){
		ans=-1;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>Map[i][j];
		for(int i=1;i<=m;i++)
			r[0][i]=n;
		for(int i=1;i<=m;i++)
		{
			maxr=n,maxl=1;
			for(int j=1;j<=n;j++)
			{
				if(Map[i][j])
				{
					maxl=j+1;
					h[i][j]=l[i][j]=0;
				}
				else
				{
					h[i][j]=h[i-1][j]+1;
					l[i][j]=max(maxl,l[i-1][j]);
				}
			}
			for(int j=n;j>=1;j--)
			{
				if(Map[i][j])
				{
					maxr=j-1;
					r[i][j]=n;
				}
				else
				{
					r[i][j]=min(r[i-1][j],maxr);
					ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	getchar();
	getchar();
	return 0;
}