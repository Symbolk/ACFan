#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
//���ԣ�����
using namespace std;

int** a;
int m,n,x,y;
int sum=0;

struct Dot{
    int x;
    int y;
    bool operator < (const Dot &a) const
    {
          return a.x<x||a.y<y;
    }
};

void read()
{
    a=new int*[m+2];
    for(int i=0; i<m+2; i++)
    {
        a[i]=new int[n+2];
    }
    for(int i=0; i<m+2; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            a[i][j]=-1;//-1Ϊ����
        }
    }
    char c;
    getchar();
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            c=getchar();
            if(c=='X')
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;//1Ϊ������
            }
        }
        getchar();
    }
}

void out()
{
    for(int i=0; i<m+2; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

void clear()
{
    for(int i=0; i<m+2; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

bool canplace(int x,int y)
{
    if (x>0&&y>0&&x<=m&&y<=n&&a[x][y]==0)//1��m
    {
        return true;
    }
    else
    {
        return false;
    }
}

void search(int x,int y)
{
    if(canplace(x,y))
    {
        a[x][y]=2;//2��ʾ�Ѹ���
        //Test the up,left,down and right
        if(canplace(x-1, y-1)) //����
        {
            search(x-1, y-1);
        }
        if (canplace(x, y-1))  //��
        {
            search(x, y-1);
        }
        if (canplace(x+1, y-1))  //����
        {
            search(x+1, y-1);
        }
        if (canplace(x+1, y))  //��
        {
            search(x+1, y);
        }

        if (canplace(x+1, y+1))  //����
        {
            search(x+1, y+1);
        }

        if (canplace(x, y+1))  //��
        {
            search(x, y+1);
        }

        if(canplace(x-1,y+1)) //����
        {
            search(x-1,y+1);
        }

        if (canplace(x-1, y))  //��
        {
            search(x-1, y);
        }

    }
}

int check()
{

    set<Dot> s;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==2)
            {
                if(a[x][y-1]==-1||a[x][y-1]==1)
                {
                    Dot d;
                    d.x=x;
                    d.y=y-1;
                    s.insert(d);
                }
                if( a[x+1][y] == -1||a[x+1][y] == 1)
                {
                    Dot d;
                    d.x=x+1;
                    d.y=y;
                    s.insert(d);
                }
                if( a[x][y + 1] ==-1||a[x][y + 1] ==1)
                {
                    Dot d;
                    d.x=x;
                    d.y=y+1;
                    s.insert(d);
                }
                if(a[x-1][y]==-1||a[x-1][y]==1)
                {
                    Dot d;
                    d.x=x-1;
                    d.y=y;
                    s.insert(d);
                }
            }
        }
    }
    return s.size();
}

int main()
{
    while(cin>>m>>n>>x>>y&&(m||n||x||y))
    {
        sum=0;
        read();
        //out();
        search(x,y);
        sum=check();
        cout<<sum;
        clear();
    }
    return 0;
}
