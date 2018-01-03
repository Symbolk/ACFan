#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//A plurality of test cases.
//Each test case of three lines: the first line contains an integer n, said the two sides each have n horse; second lines of N integers n Tian Ji horse speed; third lines of N integers King n horse speed.
//N = 0 indicates the end of input.

int r[100][100];
int a[100],b[100];//齐a田b
int n;

int compare (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}

void read()
{
    int i;
    for(i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

void init()
{
    qsort (a, n, sizeof(int), compare);
    qsort (b, n, sizeof(int), compare);//DSD
    for(int i=0; i<n; i++)
    {
        if(a[i]<b[0]){
            r[i][0]=1;//win
        }else if(a[i]==b[0]){
            r[i][0]=0;
        }else{
            r[i][0]=-1;//lose
        }
    }
}

int main()
{
    while(cin>>n&&n)
    {
        read();
        init();
        int i,j;
        for(i=n-2; i>=0; i--)
        {
            for(j=1; j<n-i; j++)
            {
                if(a[i+j]<b[j]){//赢就比
                    r[i][j]=r[i][j-1]+1;
                }else if(a[i+j]>b[j]){//输就找最快的比
                    r[i][j]=r[i+1][j-1]-1;
                }else if(r[i+1][j-1]-1>r[i][j-1]){//平就判断哪种更有利
                    r[i][j]=r[i+1][j-1]-1;
                }else{
                    r[i][j]=r[i][j-1];
                }
            }
        }
        cout<<r[0][n-1]<<endl;
    }

    return 0;
}
