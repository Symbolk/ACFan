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
//带偏移量的并查集
struct node{
	//int id;
	int f;
	int r;//father到自己的偏移量
};
node nodes[N];

int getf(int t){
	if(t==nodes[t].f){
		return t;
	}else{
		int tmp=nodes[t].f;
		//递归路径压缩
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
		nodes[i].r=0;//自己和自己是同类
	}
	while(k--){
		scanf("%d %d %d",&d,&x,&y);
		//2、3情况
		if(x>n||y>n){
			res++;
			continue;//必要！避免一句假话同时符合2和3
		}
		if(d==2&&x==y){
			res++;
			continue;
		}
		int fx=getf(x);
		int fy=getf(y);
		if(fx!=fy){//合并fy子树到fx上
			nodes[fy].f=fx;
			nodes[fy].r=(nodes[x].r+d-1+3-nodes[y].r)%3;
		}else{//验证
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