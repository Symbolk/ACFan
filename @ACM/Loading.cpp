#include <iostream>
#include <algorithm>
using namespace std;
int c1,c2,n;
int sum=0;
int* a;
int m=0,best=0;
void search(int x)
{
    if(x>=n)
    {
        if(m>best){
            best=m;
        }
        return;
    }
    else
    {
        if(m+a[x]<=c1)
        {
            m+=a[x];
            search(x+1);
            m-=a[x];
        }
        search(x+1);
    }
}


int main()
{

    while(cin>>c1>>c2>>n&&n)
    {
        a=new int[n];
        sum=0;
        m=0;
        best=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        search(0);
        if(sum-best<=c2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        // cout<<sum;
    }
    return 0;
}
