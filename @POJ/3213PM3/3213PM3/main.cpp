#include <iostream>
#include <cstring>
using namespace std;
const int N=25;
int h,w;
char map[N][N];
int book[N][N];
int sum=0;

void dfs(int x,int y){
	int move[4][2]={
		{0,1},{1,0},{0,-1},{-1,0}
	};
	if(x<0||x>h||y<0||y>w||map[x][y]=='#'){
		return;
	}
	for(int d=0;d<4;d++){
		int x1,y1;
		x1=x+move[d][0];
		y1=y+move[d][1];
		if(book[x1][y1]==0&&map[x1][y1]=='.'){
			sum++;
			book[x1][y1]=1;
			dfs(x1,y1);
		}
	}
}

int main(){
	//freopen("Text.txt","r",stdin);
	while(cin>>w>>h&&(w||h)){
		//init
		memset(book,0,sizeof(book));
		memset(map,0,sizeof(map));

		sum=0;
		int x0,y0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				book[i][j]=0;
				cin>>map[i][j];
				if(map[i][j]=='@'){
					sum++;
					book[i][j]=1;
					x0=i;y0=j;
				}
			}
		}
		dfs(x0,y0);
		cout<<sum<<endl;
	}
	return 0;
}