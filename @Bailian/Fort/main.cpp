#include <iostream>
#include <cstdio>
//堡垒问题
using namespace std;

int a[8][8];
int n=0;

void out()
{
    cout<<"No "<<n<<":"<<endl;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(a[i][j]==1)
            {
                cout<<"A";
            }
            else
            {
                cout<<".";
            }
        }
        cout<<endl;
    }
}

bool canplace(int m)
{
    bool f1=false,f2=false;
    int r,c;
    r=m/8;
    c=m%8;
    int row=r,col=c;
    while(c>=0)
    {
        c--;
        if(c<0){
            while(r--){
                if(r<0){
                    f1 = true;
                }else if(a[r][col]==1){
                    f1 = false;
                }
            }
        }else if(a[row][c]==1){
            f1 = false;
        }
    }
    while(row>=0&&col>=0){
        row--;
        col--;
        if(row<0||col<0){
            f2=true;
        }else if(a[row][col]==1){
            f2=false;
        }
    }
    return (f1&&f2);
}

void search(int m)
{
    int r,c;
    r=m/8;
    c=m%8;
    if(m==64)
    {
        n++;
        out();
        //search(m+1);//得到可行解，输出
    }
    else
    {
        if(canplace(m))
        {
            a[r][c]=1;//放Queen
            search(m+1);
            a[r][c]=0;
        }
        else
        {
            search(m+1);//不放Queen
        }
    }
}

int main()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            a[i][j]=0;
        }
    }
    search(0);
    return 0;
}
