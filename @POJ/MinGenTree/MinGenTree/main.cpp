#include <iostream>

using namespace std;

const int N=10;
const int INF=99999999;

int main(){
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	int min,u,v,w;
	int e[N][N], dis[N], book[N]={0};
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				e[i][j]=0;
			}else{
				e[i][j]=INF;
			}
		}
	}
	for(i=1;i<=n;i++){
		dis[i]=e[1][i];
	}
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
	}
	int count=0, sum=0;

	book[1]=1;//����1�Žڵ�
	count++;
	while(count<n){//1��n-1
		//Ѱ��dis��С�Ľڵ�j
			min=INF;	
			for(i=1;i<=n;i++){
				if(book[i]==0&&dis[i]<min){
					min=dis[i];
					j=i;
				}
			}
			//����j����������
			count++;
			book[j]=1;
			sum+=dis[j];
			//����dis
            for(k=1;k<=n;k++){                                                                                                                                                                                                                               			for(k=1;k<=n;k++){
				if(book[k]==0&&dis[k]>e[j][k]){
					dis[k]=e[j][k];
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}