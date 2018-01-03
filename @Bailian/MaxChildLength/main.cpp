#include <iostream>

using namespace std;
string a,b;
int m,n;
int ** c;
void LCS();

int main()
{
    cin>>a>>b;
    m=a.size();
    n=b.size();
   // cout<<m<<n<<endl;
    c=new int*[m+1];
    for(int k=0; k<m+1; k++)
    {
        c[k]=new int[n+1];
    }
    LCS();
    cout << c[m][n] << endl;
    return 0;
}

void LCS()
{
    int i,j;
    for(i=0; i<=m; i++)
    {
        c[i][0]=0;
    }
    for(i=0; i<=n; i++)
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
            }
            else
            {
                c[i][j]=c[i-1][j] >= c[i][j-1] ? c[i-1][j] : c[i][j-1];
            }
        }
    }

}
