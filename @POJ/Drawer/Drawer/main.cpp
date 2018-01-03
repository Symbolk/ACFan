#include <iostream>
#include <cstring>
using namespace std;
const int N=20;
int t, n;
int map[N][N];
int temp[N][N];
int line[N];
int steps, res;

void getline(int k){
	int j=n;
	while(j>0){
	line[j]=k%2;
		k/=2;
		j--;
	}
}	

void draw(int i, int j){
	int move[5][2]={
	{0,0},{0,1},{1,0},{0,-1},{-1,0}
	};
	//��(x,y)��draw��������ȡ��
	   // temp[x][y] = !temp[x][y];  
    //temp[x-1][y] = !temp[x-1][y];  
    //temp[x+1][y] = !temp[x+1][y];  
    //temp[x][y-1] = !temp[x][y-1];  
    //temp[x][y+1] = !temp[x][y+1];  
	for(int h=0;h<5;h++){
		temp[i+move[h][0]][j+move[h][1]]=!(temp[i+move[h][0]][j+move[h][1]]);
	}
	steps++;
}

int check(){
	//�ӵڶ��п�ʼ���ж������Ƿ�Ϊy��������draw
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(temp[i-1][j]==0){
				draw(i,j);
			}
		}
	}
	//������һ���Ƿ�Ϊy
	for(int j=1;j<=n;j++){
		if(temp[n][j]!=1){
			return 0;//����
		}
	}
	return 1;//����
}

int main(){
	//freopen("in.txt","r",stdin);
	//cin>>t;
	//while(t--){
		cin>>n;
		//init
		res=n*n+1;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				char c;
				cin>>c;
				map[i][j]= (c=='w') ? 0 : 1;//w=0, y=1
			}
		}
		//ö��,2��n�η���
		for(int k=0;k<pow(2.0, n);k++){
			steps=0;
			memcpy(temp, map, sizeof(map));
			getline(k);//��ȡһ�е��������
			//��һ�е�i��(1,i)�����
			for(int i=1;i<=n;i++){
					if(line[i]==1){
						draw(1,i);
				}
			}
			if(check()){
						res=steps < res ? steps : res; 
					}
		}
		if(res!=n*n+1){
			cout<<res<<endl;
		}else{
			cout<<"inf"<<endl;
		}
	//}
	return 0;
}