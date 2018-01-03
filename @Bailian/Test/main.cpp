#include <iostream>

using namespace std;

int* qsort(int* a,int low,int high){
    int i=low,j=high;
    if(i>=j){
        return a;
    }
    int key=a[i];
    while(i<j){
        while(i<j&&a[j]>=key){
            j--;
        }
        a[i]=a[j];
        while(i<j&&a[i]<=key){
            i++;
        }
        a[j]=a[i];
    }
    a[i]=key;
    qsort(a,low,i-1);
    qsort(a,j+1,high);
    return a;
}

int main()
{
    int n;
    cin>>n;
    int* a=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qsort(a,0,n-1);
    for(int j=0;j<n;j++){
        cout<<a[j]<<endl;
    }
    return 0;
}
