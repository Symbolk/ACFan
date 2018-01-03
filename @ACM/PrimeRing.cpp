#include <iostream>
using namespace std;
int a[21];
int s[21];
int isPrime(int m)
{

    for(int i=2; i<m; i++)
    {
        if(m%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void out()
{
    for(int i=1; i<20; i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<a[20]<<endl;
}

bool isPrimeRing(int* a,int* s,int n){
    if(n==20){
            return isPrime(a[n]+a[1]);
    }
    for(int i=2;i<21;i++){
        if(s[i]==0&&isPrime(i+a[n])){
                s[i]=1;
                a[n+1]=i;
                if(isPrimeRing(a,s,n+1)){
                        return true;
                }else{
                    s[i]=0;
                }
        }
    }
    return false;
}

int main()
{
    a[0]=0;
    a[1]=1;
    for(int i=1; i<21; i++)
    {
        s[i]=0;
    }

    if(isPrimeRing(a,s,1))
    {
        out();
    }

    return 0;
}
