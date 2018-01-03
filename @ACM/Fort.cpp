#include <iostream>
#include <cstdio>
//堡垒问题
using namespace std;
int a[4][4];
int n,best=0;

void read()
{
    char c;
    getchar();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            c=getchar();
            if(c=='X')
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
        }
        getchar();
    }
}

bool canplace(int m){
    int r,c;
    r=m/n;
    c=m%n;
    int row=r,col=c;
    if(a[r][c]==1||a[r][c]==2){
        return false;
    }
    while(c>=0&&a[row][c]==0){
        c--;//判断同一行是否满足条件
        if(c<0||(c>=0&&a[row][c]==1)){
            while(r>=0&&a[r][col]==0){
                r--;//判断同一行是否满足条件
                /*此处的边界条件开始未想好，导致如：
                *  3
                    ...
                    .XX
                    .XX
                    出现错误
                */
                if(r<=0||(r>0&&a[r][col]==1)){
                    return true;
                }
            }
        }
    }
    return false;
}

void check(){
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==2){
                s++;
            }
        }
    }
    best=s>best?s:best;
}

void out(){
      for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
}


void search(int m){
    int r,c;
    r=m/n;
    c=m%n;
    if(m==n*n){
        check();//得到可行解，检查
    }else{
        if(canplace(m)){
            a[r][c]=2;//放堡垒
            search(m+1);
            a[r][c]=0;
        }else{
            search(m+1);
        }
    }
}

int main()
{
    while(cin>>n&&n){
            best=0;
            read();
            //out();
            search(0);
            cout<<best<<endl;
    }
    return 0;
}
