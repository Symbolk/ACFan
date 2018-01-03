#include <iostream>
#include <cstdio>
#define deep 15//2^15
int arr[deep]={0};//a/bChange
int num[10]={0};
int flag=0;
using namespace std;
void aChange();
void bChange();
void check();
bool isAim();

void search(int m){
    if(m==deep){
        check();
        if(flag==1){
            return;
        }
    }else{
        arr[m]=1;
        search(m+1);
        arr[m]=0;
        search(m+1);
    }
}

int main(){
    while(!cin.eof()){
        flag=0;
        int i;
        for(i=0;i<deep;i++){
            arr[i]=0;
        }
        for(i=0;i<6;i++){
            cin>>num[i];
        }
        search(0);
        cout<<(flag==1?"Yes":"No")<<endl;
    }
    return 0;
}

void check(){
    for(int i=0;i<deep;i++){
        if(arr[i]==1){
            aChange();
            if(isAim()){
                flag=1;
                return;
            }
        }else{
            bChange();
            if(isAim()){
                flag=1;
                return;
            }
        }
    }
}

void aChange(){
    int temp=num[0];
    num[0]=num[3];
    num[3]=num[4];
    num[4]=num[1];
    num[1]=temp;
}

void bChange(){
    int temp=num[1];
    num[1]=num[4];
    num[4]=num[5];
    num[5]=num[2];
    num[2]=temp;
}

bool isAim(){
    int i;
    for(i=0;i<6;i++){
        if(num[i]!=i+1){
            return false;
        }
    }
    if(i==6){
        return true;
    }
}
