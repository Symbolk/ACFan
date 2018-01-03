//踩方格
#include <iostream>

using namespace std;
int n;
int a[21]={0,3,7};
//递归法
int f(int m){
    if(m==1){
        return 3;
    }else if(m==2){
        return 7;
    }else{
        return 2*f(m-1)+f(m-2);
    }
}

int main()
{
    cin>>n;
    //a={0,3,7};
    if(n==1||n==2){
        cout<<a[n]<<endl;
    }else{
        //备忘录法
        for(int i=3;i<=n;i++){
            a[i]=2*a[i-1]+a[i-2];
        }
        cout<<a[n]<<endl;
    }
    //int res=0;
    //res=f(n);
    //cout<<res<<endl;
    return 0;
}
