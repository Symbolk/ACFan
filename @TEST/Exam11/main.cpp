#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define MAX 100
using namespace std;

int n,m;
int res=9999;// min
int sum=0;
int p[100];
int book[100];

void bt(int i, int cp)
{
    if(i>n)
    {
        if(cp>=m&&cp<res)
        {
            res=cp;
        }
    }
    else
    {
        for(int j=0; j<=1; ++j)
        {
            book[i]=j;
//            if(cp+p[i]*book[i]<m)
//            {
                cp+=p[i]*book[i];
                bt(i+1,cp);
                cp-=p[i]*book[i];
//            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>m;

    for(int i=0; i<n; ++i)
    {
        cin>>p[i];
    }
    bt(0,0);
    if(res==9999){
        cout<<"0"<<endl;
    }else{
        cout<<res<<endl;
    }

    return 0;
}
