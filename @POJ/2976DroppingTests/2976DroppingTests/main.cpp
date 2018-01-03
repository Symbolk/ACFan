#include <iostream>
#include <algorithm>
using namespace std;
const int N=1005;
int n,k;
int a[N],b[N];
double c[N];

//按对整体正确率的贡献度排序asc，选择后n-k个（即c[n-1]到c[k]）
bool check(double x){
	for(int i=0;i<n;i++){
		c[i]=a[i]-x*b[i];
	}
	sort(c,c+n);
	double sum=0;
	for(int i=0;i<n-k;i++){
		sum+=c[n-i-1];
	}
	return (sum>=0);
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin>>n>>k&&(n||k)){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}

		//对准确率[0,1.0]之间二分搜索
		//double l=0,r=10e9,mid;
		double l=0,r=1.0,mid;
		for(int i=0;i<100;i++){
			mid=(l+r)/2;
			if(check(mid)){
				l=mid;
			}else{
				r=mid;
			}
		}
		//int ans=100*(l+0.005);
		//cout<<ans<<endl;
		printf("%.0lf\n",(double)mid*100.0);//小数长度为0的double输出
	}
	return 0;
}