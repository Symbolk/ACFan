#include <iostream>
#include <cstdio>
using namespace std;

const int N=1002;
int n,m;
int father[N], offset[N];//fathers and offsets

int getf(int i){
	if(father[i]==i){
		return father[i];
	}else{
		int j=father[i];
		father[i]=getf(father[i]);//find the root recursively
		offset[i]=(offset[i]+offset[j])  % 2;
		return father[i];
	}
}

bool merge(int a, int b, int v){
	int fa=getf(a);
	int fb=getf(b);
	if(fa==fb){
		//possible conflict
		return ((offset[a]+offset[b]) %2 == v);//like XOR
	}else{
		father[fa]=fb;
		offset[fa]=(offset[a]+offset[b]+v)% 2;
		return true;//no confict
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	while(cin>>n>>m){
		//init
		for(int i=0;i<n;i++){
			father[i]=i;
			offset[i]=0;
		}
		int a, b, v;
		int flag=1;
		while(m--){
			scanf("%d %d %d",&a,&b,&v);
				if(!merge(a,b,v)){
					flag=0;
				}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}