#include <iostream>

using namespace std;
int a[100];//height
int b[100];//num

int main()
{
    int n=0;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int max;
        b[n-1]=1;
        for(int i=n-2; i>=0; i--)
        {
            max=0;
            for(int j=i+1; j<n; j++)
            {
                if(a[j]<=a[i])
                {
                    max= max >= b[j]?max:b[j];
                }
            }
            b[i]=max+1;
        }
        //此处要选取最大的结果
        for(int i=0;i<n;i++){
            max=max>=b[i]?max:b[i];
        }
        cout<<max<<endl;
    }
    return 0;
}
