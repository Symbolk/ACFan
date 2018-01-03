#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
//const int INF=1e8;
int t;
int val[12];
int dis[200];//当凑齐i块钱时需要的货币个数dis[i]
queue<int> q;

void bfs(){
	while(!q.empty()){
		//出队一个节点
		int u=q.front();
		q.pop();
		for(int i=0;i<12;i++){
			//下一个可以到达的所有点
			int v=u+val[i];
			if(v>0&&v<200&&dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		//6种正货币
		for(int i=0;i<6;i++){
			cin>>val[i];
		}
		//6种负货币
		for(int i=6;i<12;i++){
			val[i]=-val[i-6];
		}
		//memset(dis, INT_MAX, sizeof(dis));//为什么不能正确初始化？
		dis[0]=0;
		for(int i=1;i<200;i++){
			dis[i]=INT_MAX;
		}
		q.push(0);
		//cout<<"----"<<endl;
		//cout<<dis[0]<<" "<<dis[2]<<endl;;
		bfs();
		int sum=0;
		int maxn=0;
		for(int i=1;i<=100;i++){
			sum+=dis[i];
			maxn=dis[i]>maxn ? dis[i] : maxn; 
		}
		printf("%.2f %d\n", sum/100.0, maxn);
	}
	return 0;
}