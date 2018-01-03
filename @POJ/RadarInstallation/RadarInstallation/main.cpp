#include  <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1002;
int n,d;
int res;
int flag;
int no;//case
struct Node{
	int x;
	int y;
	double s;
	double e;
};

int cmp(Node  a, Node b){
	return a.e<b.e;
}

int square(int a){
	return a*a;
}

int main(){
	//freopen("in.txt","r",stdin);
	while(cin>>n>>d&&(n||d)){
		res=0;
		flag=0;//ok
		no++;
		Node nodes[N];
		int book[N]={0};
		if(n==1){
			cin>>nodes[0].x>>nodes[0].y;
			if(abs(nodes[0].y)>d||d<=0){
			cout<<"Case "<<no<<": -1"<<endl;	
			}else{
			cout<<"Case "<<no<<": 1"<<endl;	
			}
			}else{//n>=1
			for(int i=0;i<n;i++){
				cin>>nodes[i].x>>nodes[i].y;
			}
			getchar();
			//getchar();
			for(int i=0;i<n;i++){
				if(abs(nodes[i].y)>d||d<=0){
					flag=1;
				}else{
					//double t=pow(d,2)-pow(nodes[i].y,2);
					double t=(double)square(d)-square(nodes[i].y);
					t=sqrt(t);
					nodes[i].s=nodes[i].x-t;
					nodes[i].e=nodes[i].x+t;
				}
			}
			if(flag){//flag!=0
				cout<<"Case "<<no<<": -1"<<endl;	
			}else{
				sort(nodes, nodes+n, cmp);//按结束区间排序

				for(int i=0;i<n;i++){
					if(!book[i]){
						book[i]=1;
						for(int j=0;j<n;j++){
							if(!book[j]&&nodes[j].s<=nodes[i].e){
								book[j]=1;//冲突的区间
							}
						}
						//统计与其他区间都不冲突的区间个数
						res++;
					}

				}
				cout<<"Case "<<no<<": "<<res<<endl;
			}
		}
	}
	return 0;
}