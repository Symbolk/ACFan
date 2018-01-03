#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define N 200
using namespace std;
//
int a[N][N]={0};//0--199为范围,存储到达最小步数
int dirs[8][2];//8个方向的坐标偏移
int n,res=0;//case个数和结果
int x,y,xx,yy,start,end;//起终点及其单一表示
queue<int> s;

bool canMoveTo(int r,int c,int* rr,int* cc,int dir);
int search();
void init();

int main()
{
    cin>>n;
    while(n--)
    {
        init();
        cin>>x>>y>>xx>>yy;
        x--;
        y--;
        xx--;
        yy--;
        //此处程序中坐标以0开始，但输入以1开始，故应统一化处理。
        start=x*N+y;
        end=xx*N+yy;
        if(start==end){
            res=0;
        }else{
            s.push(start);
            res=search();
        }
        cout<<res<<endl;
    }
    return 0;
}
//表示各个方向的坐标偏移量
void init()
{
    res=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            a[i][j]=0;
        }
    }
    while(!s.empty()){
        s.pop();
    }
    //memset(a,0,sizeof(a));
    //改进:int direction[8][2]={{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
    dirs[0][0]=-2;
    dirs[0][1]=-1;
    dirs[1][0]=-1;
    dirs[1][1]=-2;
    dirs[2][0]=1;
    dirs[2][1]=-2;
    dirs[3][0]=2;
    dirs[3][1]=-1;
    dirs[4][0]=2;
    dirs[4][1]=1;
    dirs[5][0]=1;
    dirs[5][1]=2;
    dirs[6][0]=-1;
    dirs[6][1]=2;
    dirs[7][0]=-2;
    dirs[7][1]=1;
}
//一个处理多方向遍历的方法
bool canMoveTo(int r,int c,int* rr,int* cc,int d)
{
    int row,col;
    row=r,col=c;
    row+=dirs[d][0];
    col+=dirs[d][1];
    if(row<0||row>=N||col<0||col>=N)
    {
        return false;
    }else{
        *rr=row;
        *cc=col;
        return true;
    }
}

int search()
{
    int t,r,c,rr,cc,step;
    while(!s.empty())
    {
        t=s.front();
        s.pop();
        r=t/N;
        c=t%N;
        step=a[r][c];
        for(int i=0; i<8; i++)
        {
            if(canMoveTo(r,c,&rr,&cc,i))
            {
                if(rr*N+cc==end)
                {
                    return step+1;
                }
                if(a[rr][cc]==0)
                {
                    a[rr][cc]=step+1;
                    int cur=rr*N+cc;
                    s.push(cur);
                }
            }
        }
    }
    //return step;
}
