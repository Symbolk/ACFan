#include <iostream>
#define maxsize 10000

using namespace std;
void QuickSort(int* a,int l,int r){
    if(l<r){
        int i=l,j=r,x=a[l];//���±꣬���±꣬��׼Ԫ��
        while(i<j){
            while(i<j&&a[j]>=x){
                //��-ǰ�ҵ�һ��<x��
                j--;
            }
            //���
            if(i<j){
                a[i++]=a[j];
            }
            while(i<j&&a[i]<x){
                i++;
            }
            if(i<j){
                a[j--]=a[i];
            }
        }
        a[i]=x;
        QuickSort(a,l,i);
        QuickSort(a,i+1,r);
    }
}

int main(){
    int n=0;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
