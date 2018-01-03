#include <iostream>
#include <cstring>
using namespace std;

char **chase;
int *f;// the piece is placed at(x,f(x))
int sum;
int n, k;
int flag[10];

bool place(int t){
	// compare with the former placed ones
	for(int i=0;i<t;i++){
		//same col
		if(f[i]==f[t])
		{
			return false;
		}
	}
	return true;

}

void backtrack(int t){
	if(t>=k){
		sum++;
	}
		//place the next line
		for(int i=0;i<n;i++){
			if(chase[t][i]=='#'){
				f[t]=i;// (t, i)
				if(place(t)){
						// place the next line
						backtrack(t+1);
				}
			}
			//else try the next col
		}
}

void search(int cur, int num){
	if(num==k){	sum++; return; }
	for(int i=cur;i<n;i++){
		for(int j=0;j<n;j++){
			if(chase[i][j]=='#'&&!flag[j]){
				flag[j]=1;
				search(i+1,num+1);
				flag[j]=0;
			}
		}
	}
}

int main(){
	while(cin>>n>>k&&n!=-1&&k!=-1){
		chase=new char*[n];
		sum=0;
		memset(flag,0,sizeof(flag));
		f=new int[k];
		for(int i=0;i<n;i++){
			chase[i]=new char[n];
		}
		//get the chase
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				chase[i][j]=getchar();
			}
			getchar();
		}
		for(int x=0;x<k;x++){
			f[x]=0;//init
		}
		// place from the 1st line
		//backtrack(0);
		search(0,0);
		cout<<sum<<endl;
	}
	return 0;
}