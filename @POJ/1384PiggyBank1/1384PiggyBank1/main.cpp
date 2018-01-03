#include <iostream>

using namespace std;
const int MAX=1000000;
const int MAXW=50005;
struct coin{
	int p;
	int w;
};
int t, W, e, f, n;
int dp[MAXW];

int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&e,&f);;
		W=f-e;
		scanf("%d",&n);
		coin *coins=new coin[n];
		for(int i=1;i<=n;i++){
			scanf("%d",&coins[i].p);
			scanf("%d",&coins[i].w);
		}
		dp[0]=0;
		for(int i=1;i<=W;i++){
			dp[i]=MAX;
		}
		for(int i=1;i<=n;i++){
			for(int j=coins[i].w;j<=W;j++){
				int temp= dp[j-coins[i].w]+coins[i].p;
				dp[j]=dp[j] < temp ? dp[j] : temp;
			}
		}
		if(dp[W]==MAX){
			cout<<"This is impossible."<<endl;
		}else{
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[W]<<"."<<endl;
		}
	}
	return 0;
}