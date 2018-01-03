#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
//BFS，层序遍历，空间换时间，效率好，无回溯
int a[12][12];//-1墙0路数字等于最小步数
int x,y,xx,yy,start,e;
queue<int> s;
//用queue,stack是错误的！

void read();
//void out();
bool canMoveTo(int r,int c,int* rr,int* cc,int dir);
int search();

int main(){
    int res=0;
    cin>>x>>y>>xx>>yy;
    x--;
    y--;
    xx--;
    yy--;
    //此处程序中坐标以0开始，但输入以1开始，故应统一化处理。
    start=x*12+y;
    e=xx*12+yy;
    //开始少了这一句，总是输出一个随机的大数，其实search没有执行
    s.push(start);
    read();
    //out();
    res=search();
    cout<<res<<endl;
    return 0;
}
//字母连缀类通用输入并格式化存储，int表示有限状态集
void read(){
    char c;
    for(int i=0; i<12; i++)
    {
        getchar();
        for(int j=0; j<12; j++)
        {
            c=getchar();
            if(c=='X')
            {
                a[i][j]=-1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
}

void out()
{
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
//一个处理多方向遍历的好方法
bool canMoveTo(int r,int c,int* rr,int* cc,int dir){
    int row,col;
    row=r,col=c;
    switch(dir){
        case 0:col--; break;
        case 1:row++; break;
        case 2:col++; break;
        case 3:row--;
    }
    *rr=row;
    *cc=col;
    if(row<0||row>=12||col<0||col>=12){
        return false;
    }else if(a[row][col]==0){
        return true;
    }
    return false;
}

int search(){
    int t,r,c,rr,cc,step;
    while(!s.empty()){
        t=s.front();
        s.pop();
        r=t/12;
        c=t%12;
        step=a[r][c];
        for(int i=0;i<4;i++){
            if(canMoveTo(r,c,&rr,&cc,i)){
                if(rr*12+cc==e){
                    return step+1;
                }
                if(a[rr][cc]==0){//未到达
                    a[rr][cc]=step+1;
                    int cur=rr*12+cc;
                    s.push(cur);
                }
            }
        }
    }
}
