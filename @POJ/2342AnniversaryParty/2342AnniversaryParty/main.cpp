 #include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 6005;
int dp[N][2], supervisor[N];
int n,l,k, start;
//vector<int> connected[N];

void dfs(int node){
	for(int i=1;i<=n;++i){
		if(supervisor[i]==node){
			//find one employee
			dfs(i);
			dp[node][1]+=dp[i][0];//node comes and its employee not
			dp[node][0]+=max(dp[i][0],dp[i][1]);
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>dp[i][1];
	}
	memset(supervisor, 0, sizeof(supervisor));
	while(cin>>l>>k&&(l||k)){
		supervisor[l]=k;
		start=k;
	}
	dfs(start);
	int result=max(dp[start][0],dp[start][1]);
	cout<<result<<endl;
	return 0;
}