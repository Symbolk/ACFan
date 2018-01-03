#include <iostream>
#include <cstdio>
using namespace std;

int** a;
int n;
int x1,y1,x2,y2;
bool flag=false;

void read()
{
    a=new int*[20];
    for(int k=0; k<20; k++)
    {
        a[k]=new int[20];
    }
    char c;
    getchar();
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
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

void out()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

void clear()
{
    for(int i=0; i<20; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

bool canplace(int x,int y)
{
    if (x>=0&&y>=0&&x<20&&y<20&&a[x][y]==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
void search(int x, int y)
{
    if(x==x2&&y==y2)
    {
        flag=true;
        return;
    }
    else
    {
        if(canplace(x,y))
        {
            a[x][y]=1;
        }
        if (canplace(x, y-1))  //вС
        {
            search(x, y-1);
        }
        if (canplace(x+1, y))  //об
        {
            search(x+1, y);
        }
        if (canplace(x, y+1))  //ср
        {
            search(x, y+1);
        }
        if (canplace(x-1, y))  //ио
        {
            search(x-1, y);
        }
    }
return;
}


int main()
{
    cin>>n;
    while(n--)
    {
        flag=false;
        cin>>x1>>y1>>x2>>y2;
        read();
        //out();
        search(x1,y1);
        if(flag){
                cout<<"Yes"<<endl;
        }else{
                cout<<"No"<<endl;
        }
        clear();
    }

    return 0;
}
