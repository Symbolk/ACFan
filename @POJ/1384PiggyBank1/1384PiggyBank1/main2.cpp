#include <iostream>
#include <cstring>
using namespace std;
const int MAX=10001;
const int N=505;

int t, W, e, f, n;
int dpp[MAX], dpw[MAX];
int p[N],w[N];

int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&e,&f);;
		W=f-e;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>p[i]>>w[i];
		}
		memset(dpp, 0x3f, sizeof(dpp));
		memset(dpw, 0, sizeof(dpw));
		dpp[0]=0;
		
		for(int i=1;i<=n;i++){
			for(int j=w[i];j<=W;j++){
				dpw[j] = dpw[j] > dpw[j-w[i]]+w[i] ? dpw[j] : dpw[j-w[i]]+w[i];
				dpp[j] = dpp[j] < dpp[j-w[i]]+p[i] ? dpp[j] : dpp[j-w[i]]+p[i];
			}
		}

		if(dpw[W]!=W){
			cout<<"This is impossible."<<endl;
		}else{
			cout<<"The minimum amount of money in the piggy-bank is "<<dpp[W]<<"."<<endl;
		}
	}
	return 0;
}