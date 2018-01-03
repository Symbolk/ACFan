//百练，献给小白鼠的花束
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

int T,R,C,S,E;
bool flag;
queue<int> q;
int dirs[4][2]={//0，1，2，3=up,right,down,left
    {-1,0},{0,1},{1,0},{0,-1}
};
int a[200][200];

bool move(int r,int c,int* rr,int* cc,int d){
    int row,col;
    row=r+dirs[d][0];
    col=c+dirs[d][1];
    if(row<0||row>=R||col<0||col>=C){
        return false;
    }else if(a[row][col]==0){
        *rr=row;
        *cc=col;
        return true;
    }
    return false;
}
//BFS
int search(){
    while(!q.empty()){
        int s=q.front();
        q.pop();
        int r,c,rr,cc;
        r=s/C;
        c=s%C;
        int step=a[r][c];
        for(int i=0;i<4;i++){
            if(move(r,c,&rr,&cc,i)){
                if(rr*C+cc==E){
                    flag=true;
                    return step+1;
                }
                if(a[rr][cc]==0){//not yet
                    a[rr][cc]=step+1;
                    q.push(rr*C+cc);
                }
            }
        }
    }
}

int main()
{
    cin>>T;
    while(T--){
        cin>>R>>C;
        memset(a,0,sizeof(a));
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<R;i++){
            getchar();
            for(int j=0;j<C;j++){
               // cout<<a[i][j]<<" ";
                char ch=getchar();
                switch(ch){
                    case '.':a[i][j]=0;break;
                    case '#':a[i][j]=-1;break;
                    //！！！这里受长期正方形误导，应当是乘以行数而非列数！！！
                    case 'S':S=i*C+j;cout<<"S:"<<i<<","<<j<<endl;break;
                    case 'E':E=i*C+j;cout<<"E:"<<i<<","<<j<<endl;
                }
            }
            //cout<<endl;
        }
        cout<<S<<" "<<E<<endl;
        q.push(S);
        flag=false;
        int res=search();
        if(flag){
            cout<<res<<endl;
        }else{
            cout<<"oops!"<<endl;
        }
    }

    return 0;
}
