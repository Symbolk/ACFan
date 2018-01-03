#include <iostream>

using namespace std;

int* Merge(int* a, int low,int mid,int high,int* res){
    int i=low,j=mid+1,m=mid,n=high;
    int k=0;
    while(i<m&&j<n){
        if(a[i]<=a[j]){
            res[k++]=a[i++];
        }else{
            res[k++]=a[j++];
        }
    }
    while(i<m){
        res[k++]=a[i++];
    }
    while(j<n){
        res[k++]=a[j++];
    }
    for(int i=0;i<k;i++){
        a[low+i]=res[i];
    }
}

void MSort(int* a, int low, int high,int *res){
    if(low<high){
        int mid=(low+high)/2;
        MSort(a,low,mid,res);
        MSort(a,mid+1,high,res);
        Merge(a,low,mid,high,res);
    }
}

int main()
{   int n;
    cin>>n;
    int* a=new int[n+1];
    int* res=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MSort(a,0,n-1,res);
     for(int i=0;i<n;i++){
        cout<<res[i];
    }
    delete[] a;
    return 0;
}
