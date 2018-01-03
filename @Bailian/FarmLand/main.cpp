#include<iostream>
#include <cstdio>
using namespace std;
class BaseDate
{
public:
    bool geted;//存放当前的块是否被取
    char ch;//存放相应的字母
    int left,right,up,down;//存放是否有连通线
    void init(bool g=false,char c=' ',int l=0,int r=0,int u=0,int d=0);//默认构造函数
};

void BaseDate::init(bool g,char c,int l,int r,int u,int d)//默认构造函数
{
    geted=g;
    ch=c;
    left=l;
    right=r;
    up=u;
    down=d;
}
void readdata();
void search(int ,int);
int canplace(int row,int col,int r,int c);
BaseDate Array[50][50];
int R,C;

int main()
{
    //当满足一定条件时才结束程序的一种处理方法
    int num=0;
    readdata();
   // cout<<Array[0][0].ch<<endl;
    while(R!=-1||C!=-1)
    {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                if(Array[i][j].geted==false)
                {
                    search(i,j);
                    num++;
                }
        cout<<num<<endl;
        num=0;
        readdata();
    }
    return 0;
}

void readdata()
{
    cin>>R>>C;     //m表示行数，n表示列数
    getchar();
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
        {
            Array[i][j].geted=false;//重复使用全局变量Array[50][50]
            Array[i][j].left=0;
            Array[i][j].right=0;
            Array[i][j].up=0;
            Array[i][j].down=0;
            Array[i][j].ch=getchar();
            switch(Array[i][j].ch)
            {
            case'A':
                Array[i][j].left=1;
                Array[i][j].up=1;
                break;
            case'B':
                Array[i][j].right=1;
                Array[i][j].up=1;
                break;
            case'C':
                Array[i][j].left=1;
                Array[i][j].down=1;
                break;
            case'D':
                Array[i][j].right=1;
                Array[i][j].down=1;
                break;
            case'E':
                Array[i][j].up=1;
                Array[i][j].down=1;
                break;
            case'F':
                Array[i][j].left=1;
                Array[i][j].right=1;
                break;
            case'G':
                Array[i][j].left=1;
                Array[i][j].right=1;
                Array[i][j].up=1;
                break;
            case'H':
                Array[i][j].left=1;
                Array[i][j].up=1;
                Array[i][j].down=1;
                break;
            case'I':
                Array[i][j].left=1;
                Array[i][j].right=1;
                Array[i][j].down=1;
                break;
            case'J':
                Array[i][j].right=1;
                Array[i][j].up=1;
                Array[i][j].down=1;
                break;
            case'K':
                Array[i][j].left=1;
                Array[i][j].right=1;
                Array[i][j].up=1;
                Array[i][j].down=1;
                break;
                }
            }
            getchar();
        }
}
void search(int row,int col)
{
    int r,c;
    Array[row][col].geted=true;
    r=row;
    c=col-1;//左
    if(canplace(row,col,r,c))
        search(r,c);
    r=row+1;
    c=col;//下
    if(canplace(row,col,r,c))
        search(r,c);
    r=row;
    c=col+1;//右
    if(canplace(row,col,r,c))
        search(r,c);
    r=row-1;
    c=col;//上
    if(canplace(row,col,r,c))
        search(r,c);
}

int canplace(int row,int col,int r,int c)
{
    if(r>=0 &&r<R &&c>=0 &&c<C &&Array[r][c].geted==false)
    {
        if(r==row &&c==col-1 &&Array[row][col].left==1 &&Array[r][c].right==1) //判左
            return 1;
        if(r==row+1 &&c==col &&Array[row][col].down==1 &&Array[r][c].up==1)//判下
            return 1;
        if(r==row &&c==col+1 &&Array[row][col].right==1 &&Array[r][c].left==1)//判右
            return 1;
        if(r==row-1 &&c==col &&Array[row][col].up==1 &&Array[r][c].down==1)//判上
            return 1;
    }
    return 0;
}
