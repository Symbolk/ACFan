#include <cstring>
#include <iostream>
#define INT_MIN 0x80000000
using namespace std;
const int N = 550;

int main()
{
	int n;
	int data[N][N], rowsum[N][N], dp[N];

	//freopen("in.txt","r",stdin);
	cin>>n;
		int max=INT_MIN;
		for(int i=0;i<=n;i++){
			rowsum[i][0]=0;
			rowsum[0][i]=0;
		}

		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cin>>data[i][j];
				rowsum[i][j] = rowsum[i][j-1]+data[i][j];
			}
		//cols are between j to i
		for(int i=1;i<=n;++i){
			//for every j before i
			for(int j=1;j<i;++j){
				//dp[k] means the inner sum between col j and i of row k
				dp[1]=rowsum[1][i]-rowsum[1][j-1];
				for(int k=2;k<=n;++k){
					//just like 1-d array, f[k]=max{f[k-1], f[k-1]+a[k]}
					int innersum=rowsum[k][i]-rowsum[k][j-1];
					dp[k]= innersum > innersum+dp[k-1] ? innersum : innersum+dp[k-1];
					if(dp[k]>max){
						max=dp[k];
					}
				}
			}
		}
	cout<<max<<endl;
    return 0;
}
