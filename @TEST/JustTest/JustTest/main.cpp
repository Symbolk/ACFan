#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
const int N=50010;
int n,k;
int res=0;
//��ƫ�����Ĳ��鼯
struct node{
	//int id;
	int f;
	int r;//father���Լ���ƫ����
};
node nodes[N];

int getf(int t){
	if(t==nodes[t].f){
		return t;
	}else{
		int tmp=nodes[t].f;
		//�ݹ�·��ѹ��
		nodes[t].f=getf(tmp);
		nodes[t].r=(nodes[t].r + nodes[tmp].r)%3;
		return nodes[t].f;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//cin>>n>>k;
	scanf("%d %d",&n,&k);
	int d, x, y;
	res=0;
	//init
	for(int i=0;i<n;i++){
		nodes[i].f=i;
		nodes[i].r=0;//�Լ����Լ���ͬ��
	}
	while(k--){
		scanf("%d %d %d",&d,&x,&y);
		//2��3���
		if(x>n||y>n){
			res++;
			continue;//��Ҫ������һ��ٻ�ͬʱ����2��3
		}
		if(d==2&&x==y){
			res++;
			continue;
		}
		int fx=getf(x);
		int fy=getf(y);
		if(fx!=fy){//�ϲ�fy������fx��
			nodes[fy].f=fx;
			nodes[fy].r=(nodes[x].r+d-1+3-nodes[y].r)%3;
		}else{//��֤
			if(d==1&&nodes[x].r!=nodes[y].r){
				res++;
				continue;
			}
			if(d==2&&(3-nodes[x].r+nodes[y].r)%3!=(d-1)){
				res++;
				continue;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}