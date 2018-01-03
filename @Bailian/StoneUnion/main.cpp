#include <iostream>


using namespace std;
int n;

int main()
{
    while(cin>>n&&n){
        int a[n];
        int i,j,r;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int m[n][n];
        for(i=0;i<n;i++){
            m[i][i]=0;
            j=i+1;
            m[i][j]=a[i]+a[j];
        }
        for(r=2;r<n;r++){
            for(i=0;i<n-r;i++){
                j=i+r;
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=a[k];
                }

            }
        }
    }
    return 0;
}
