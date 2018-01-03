#include <iostream>
#include <cmath>
using namespace std;

int a[9];
int n=0;

bool place(int k){
    for(int i=1;i<k;i++){
        if(a[i]==a[k]||abs(k-i)==abs(a[k]-a[i])){
            return false;
        }
    }
    return true;
}

void out(){
    n++;
    cout<<"No "<<n<<":"<<endl;
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++){
            if(j==a[i]){
                cout<<"A";
            }else{
                cout<<".";
            }
        }
        cout<<endl;
    }
}
void search(){
    int k=1;
    while(k>=1){
        a[k]=a[k]+1;
        while(a[k]<=8&&!place(k)){
            a[k]=a[k]+1;
        }
        if(a[k]<=8&&k==8){
            out();
            //return;
        }else if(a[k]<=8&&k<8){
            k++;
        }else{
            a[k]=0;
            k--;
        }
    }
}
int main(){
    for(int i=1;i<9;i++){
        a[i]=0;
    }
    search();
    return 0;
}

