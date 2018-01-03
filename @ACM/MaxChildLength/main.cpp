#include <iostream>

using namespace std;
string a,b;
int m,n;
int ** f;
int ** c;
void LCSLength();
void LCS(int i,int j);
int main()
{
    cin>>a>>b;
    m=a.size();
    n=b.size();
   // cout<<m<<n<<endl;
    c=new int*[m+1];
    f=new int*[m+1];
    for(int k=0; k<m+1; k++)
    {
        c[k]=new int[n+1];
        f[k]=new int[n+1];
    }
    LCSLength();
    cout << c[m][n] << endl;
    LCS(m,n);
    return 0;
}

void LCSLength()
{
    int i,j;
    for(i=1; i<=m; i++)
    {
        c[i][0]=0;
    }
    for(i=1; i<=n; i++)
    {
        c[0][i]=0;
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i-1]==b[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                f[i][j]=1;
            }
            else
            {
                c[i][j]=c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];
                f[i][j]=c[i-1][j] >= c[i][j-1] ? 2 : 3;
            }
        }
    }
}

void LCS(int i,int j){
    if(i==0||j==0){
        return;
    }
    if(f[i][j]==1){
        LCS(i-1,j-1);
        cout<<a[i];
    }else if(f[i][j]==2){
        LCS(i-1,j);
    }else if(f[i][j]==3){
        LCS(i,j-1);
    }
}
