#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
//BFS������������ռ任ʱ�䣬Ч�ʺã��޻���
int a[12][12];//-1ǽ0·���ֵ�����С����
int x,y,xx,yy,start,e;
queue<int> s;
//��queue,stack�Ǵ���ģ�

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
    //�˴�������������0��ʼ����������1��ʼ����Ӧͳһ������
    start=x*12+y;
    e=xx*12+yy;
    //��ʼ������һ�䣬�������һ������Ĵ�������ʵsearchû��ִ��
    s.push(start);
    read();
    //out();
    res=search();
    cout<<res<<endl;
    return 0;
}
//��ĸ��׺��ͨ�����벢��ʽ���洢��int��ʾ����״̬��
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
//һ������෽������ĺ÷���
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
                if(a[rr][cc]==0){//δ����
                    a[rr][cc]=step+1;
                    int cur=rr*12+cc;
                    s.push(cur);
                }
            }
        }
    }
}
