#include <iostream>

using namespace std;

int n,c,m=0;
int  w[10],p[10];
int  a[10];

void check(){
    int i,wei=0,val=0;
    for(i=0;i<n;i++){
        if(a[i]==1){
            wei+=w[i];
            val+=p[i];
        }
    }
    if(wei<=c){
        if(val>m){
            m=val;
        }
    }
}

void search(int m){
    if(m>=n){
        check();
    }else{
        a[m]=0;
        search(m+1);
        a[m]=1;
        search(m+1);
    }
}

int main()
{
    while(cin>>n>>c&&(n||c)){
        m=0;
        int i;
        for(i=0;i<n;i++){
            cin>>w[i];
        }
       for(i=0;i<n;i++){
            cin>>p[i];
        }
        search(0);
        cout<<m<<endl;
        }
    return 0;
}
