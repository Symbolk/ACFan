#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const int N=1005;
int n, d;
struct island{
	int x;
	int y;
	bool operator < (const island& is){
		return x>is.x;
	}
};
island iss[N];
string line;
int cnt=0;
int res=0;
int flag=0;

int cmp(const void *a, const void *b){
	return (*(island*)a).x > (*(island*)b).x;
}
int square(int x){
	return x*x;
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin>>n>>d&&(n||d)){
		cnt++;
		res=0;
		for(int i=0;i<n;i++){
			cin>>iss[i].x>>iss[i].y;
			if(iss[i].y>d){
				flag=1;
			}
		}
		//getline(cin,line);
		getchar();
		qsort(iss,n,sizeof(iss[0]),cmp);
		//sort(iss, iss+n);//从小到大排序
		for(int i=0;i<n;i++){
			cout<<iss[i].x<<" ";
		}
		//计算相邻不重叠的点个数
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				int dis=square(iss[j].y-iss[i].y)+square(iss[j].x-iss[i].x);
				if(dis>square(2*d)){
					res++;
				}
			}
		}
		if(flag){
		cout<<"Case "<<cnt<<": -1"<<endl;
		}else{
		cout<<"Case "<<cnt<<": "<<res<<endl;
		}
		}

	return 0;
}