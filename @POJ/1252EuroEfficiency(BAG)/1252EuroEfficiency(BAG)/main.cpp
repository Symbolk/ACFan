#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

//两轮dp，计算最大付款数和找零数
const int N=2005;
int t;
int val[7];
int dp[N];//凑成j块钱至少需要用到前i货币dp[i][j]个

int main(){
	freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		for(int i=1;i<=6;i++){
			cin>>val[i];
		}
			for(int j=1;j<N;j++){
				dp[j]=INT_MAX;
			}
		dp[0]=0;
		//第一轮dp
		for(int i=1;i<=6;i++){
			for(int j=val[i];j<N;j++){
				dp[j]=min(dp[j], dp[j-val[i]]+1);
			}
		}
		//第二轮dp，更新最终付款数
		for(int i=1;i<=6;i++){
			for(int j=N-1;j>=val[i];j--){
				dp[j-val[i]]=min(dp[j-val[i]],dp[j]+1);
			}
		}

		int sum=0;
		int maxn=0;
		for(int j=1;j<=100;j++){
			sum+=dp[j];
			maxn=dp[j]>maxn ? dp[j] : maxn; 
		}
		printf("%.2f %d\n", sum/100.0, maxn);
	}
	return 0;
}