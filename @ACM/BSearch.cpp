#include <iostream>

using namespace std;


int isIn(int* a,int len,int d){
    int low=0,high=len-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==d){
            return 1;
        }else if(a[mid]>d){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}


int main()
{
    int n,m,k;
    cin>>n;
    int* a=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    while(m--){
        cin>>k;
        if(isIn(a,n,k)==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
