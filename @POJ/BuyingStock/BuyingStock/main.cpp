#include <iostream>
#include <algorithm>
using namespace std;
const int N =100005;
const int INF=99999999;
int t, n;
int p;
int dp[3][2];//��ʾ��i������������(0)������(1)���������

int main(){
	freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<3;i++){
			for(int j=0;j<2;j++){
				dp[i][j]=-INF;
			}
		}
		for(int i=1;i<=n;i++){
			//�ڵ�i��Ľ������
			scanf("%d",&p);
			dp[1][0]=max(-p, dp[1][0]);
			dp[1][1]=max(p+dp[1][0], dp[1][1]);
			dp[2][0]=max(dp[1][1]-p, dp[2][0]);
			dp[2][1]=max(dp[2][0]+p,dp[2][1]);
		}
		cout<<dp[2][1]<<endl;
	}
	return 0;
}