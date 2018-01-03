#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct State
{
    int row,col;
    int dir,color;
    int time;
};
int n;
int x,y,xx,yy,color;
//坐标0-19
int m[20][20];
queue<State> q;
int dirs[4][2]=
{
    {0,-1},{1,0},{0,1},{-1,0}//W,S,E,N规定为0123,逆时针方向
};
//int colors[5]= {0,1,2,3,4}; //逆时针方向规定颜色
int flags[20][20][5][4];//状态判重
struct State start,goal;

void read();
int search();
void out();
bool canMove(struct State s);
bool isAim(struct State s);
bool hasReached(struct State s);
struct State goAhead(struct State u);
struct State turnLeft(struct State u);
struct State turnRight(struct State u);

//void out();


int main()
{
        int res=0;
        read();
        //struct State temp=q.front();
        //out();
        res=search();
        cout<<res<<endl;
    return 0;
}

void read()
{
    char sCol,sDir,eCol;
    int a,b,c;
    cin>>x>>y>>sCol>>sDir>>xx>>yy>>eCol;
    //cout<<sCol<<endl;
    switch(sDir){
        case 'W':
            a=0;
            break;
        case 'S':
            a=1;
            break;
        case 'E':
            a=2;
            break;
        case 'N':
            a=3;
            break;
    }
    switch(sCol){
        case 'R':
            b=0;
            break;
        case 'Y':
            b=1;
            break;
        case 'B':
            b=2;
            break;
        case 'W':
            b=3;
            break;
        case 'G':
            b=4;
            break;
    }
     switch(eCol){
         case 'R':
            c=0;
            break;
        case 'Y':
            c=1;
            break;
        case 'B':
            c=2;
            break;
        case 'W':
            c=3;
            break;
        case 'G':
            c=4;
            break;
    }
    color=c;
    //cout<<a<<b<<c<<color<<endl;
    for(int i=0; i<20; i++)
    {
        getchar();
        for(int j=0; j<20; j++)
        {
            char c;
            c=getchar();
            if(c=='.')
            {
                m[i][j]=0;
            }
            else if(c=='X')
            {
                m[i][j]=1;
            }
        }
    }
    start= {x-1,y-1,a,b,0};
    goal= {xx-1,yy-1,0,c,0};
    q.push(start);
}


int search()
{
    struct State u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        v=goAhead(u);
        if(canMove(v))
        {
            if(isAim(v))
            {
                return v.time;
            }
            if(!hasReached(v))
            {
                q.push(v);
                flags[v.row][v.col][v.color][v.dir]=1;
            }
        }
        v=turnLeft(u);
        if(!hasReached(v))
        {
            q.push(v);
            flags[v.row][v.col][v.color][v.dir]=1;
        }
        v=turnRight(u);
        if(!hasReached(v))
        {
            q.push(v);
            flags[v.row][v.col][v.color][v.dir]=1;
        }
    }
}

struct State goAhead(struct State u)
{
    struct State v;
    v.row=u.row+dirs[u.dir][0];
    v.col=u.col+dirs[u.dir][1];
    v.color=(u.color+1)%5;
    v.dir=u.dir;
    v.time=u.time+1;
    return v;
}

struct State turnLeft(struct State u)
{
    struct State v;
    v.row=u.row;
    v.col=u.col;
    v.color=u.color;
    v.dir=(u.dir+1)%4;
    v.time=u.time+1;
    return v;
}

struct State turnRight(struct State u)
{
    struct State v;
    v.row=u.row;
    v.col=u.col;
    v.color=u.color;
    v.dir=(u.dir+3)%4;
    v.time=u.time+1;
    return v;
}

bool canMove(struct State s)
{
    if(s.row>=0&&s.row<=19&&s.col>=0&&s.col<=19)
    {
        if(m[s.row][s.col]==0)
        {
            return true;
        }
    }
    return false;
}

bool isAim(struct State s)
{
    if(s.row==goal.row&&s.col==goal.col&&s.color==goal.color)
    {
        return true;
    }
    return false;
}

bool hasReached(struct State s)
{
    if(flags[s.row][s.col][s.color][s.dir]==1)
    {
        return true;
    }
    return false;
}

void out()
{
    cout<<start.row<<start.col<<start.dir<<color<<endl;
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            cout<<m[i][j];
        }
        cout<<endl;
    }
}


