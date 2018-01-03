#include <iostream>
#include <cstring>

using namespace std;
int n,k;
char chase[10][10];
int sum;
int flag[10];// visted or not

void search(int x, int t){
	if(t==k){
		// solution found
		sum++;
		return;
	}else{
		// for current row, search every col
		for(int i=x;i<n;i++){
			for(int j=0;i<n;j++){
				// blank and no others in the same col
				if(chase[i][j]=='#'&&!flag[j]){
					flag[j]=1;
					//place next piece in the next row
					search(i+1,t+1);
					flag[j]=0;
				}
			}
		}
	}
}

int main(){
	while(cin>>n>>k&&n!=-1&&k!=-1){
		//chase=new char*[n+1];
		sum=0;
		memset(flag,0,sizeof(flag));
		//flag=new int[n+1];
		//get the chase
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				chase[i][j]=getchar();
			}
			getchar();
		}
				for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				chase[i][j]=getchar();
			}
			getchar();
		}
		/*for(int i=0;i<n;i++){
			gets(chase[i]);//get a line and store it in chase array
		}*/
		
		// place from the 1st line
		//search(0,0);
		cout<<sum<<endl;
	}
	return 0;
}