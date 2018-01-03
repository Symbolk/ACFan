#include <iostream>

using namespace std;

int n=0;
int* a=new int[n+1];

void out(){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}

void search(int m){
    if(m==n){
        out();
    }else{
        a[m]=0;
        search(m+1);
        a[m]=1;
        search(m+1);
    }
}
int main()
{
    cin>>n;
    search(0);
    return 0;
}
