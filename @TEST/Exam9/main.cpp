#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
    int p;
    int l;
} gift;

bool compare(const gift &x, const gift &y)
{
    return x.l > y.l;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;

//    int p[100],l[100];
    gift gifts[100];
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        cin>>gifts[i].p>>gifts[i].l;
        if(gifts[i].p>m)
        {
            cout<<"0"<<endl;
            return 0;
        }
    }
    sort(gifts, gifts+n, compare);

    int sum=0;
    int res=0;
    for(int i=0; i<n; ++i)
    {
        if(sum+gifts[i].p<=m){
            sum+=gifts[i].p;
            res++;
        }else{
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}
