#include <iostream>

using namespace std;
int a[11][2];
//int p[11];
int m[11][11],s[11][11];
int n=0;
void cal();

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }
   /* p[0]=a[1][0];
    for(int i=1;i<=n;i++){
        p[i]=a[i][1];
    }
    */
    cal();
    cout << m[1][n] << endl;
    return 0;
}

void cal(){
    int i,j;
    for(i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int r=1;r<n;r++){
        for(i=1;i<=n-r;i++){
            j=i+r;
            m[i][j]=m[i+1][j]+a[i][0]*a[i][1]*a[j][1];
            //p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int t=m[i][k]+m[k+1][j]+a[i][0]*a[k][1]*a[j][1];
                //p[i-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
