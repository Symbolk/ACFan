#include <iostream>
#include <cstring>
using namespace std;
const int N=1000;
int t,n;

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		char ops;
		int opr;
		for(int i=1;i<=n;i++){//第i次操作
			if(i==1){
				scanf("%c &d",&ops, &opr);
				cout<,ops<<" "<<opr<<endl;
			}else{
					scanf("%c",&ops);	
					cout<<ops;
					if(ops=='I'){
						scanf("%d",&opr);
						cout<<" ";
					}
					cout<<endl;
			}
			
		}
	}
	return 0;
}