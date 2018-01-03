#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iomanip>
//最优服务次序问题
using namespace std;
int x[10000];

int main()
{
    int n;
    cin >> n;
    int temp;
    //vector<int> x;
     for(int j = 0; j< n; j++)
       {
          // scanf("%d",&temp);
          //  x.push_back(temp);
          scanf("%d",&x[j]);
        }


   // sort(x.begin(),x.end());
     sort(x,x+n);

    for(int i = 1; i < n; i++){
        x[i]+=x[i-1];
    }

    double t = 0;
    for(int i = 0; i < n; i++){
        t+=x[i];
    }
    t/=n;
    cout.setf(ios::fixed);
    cout << setprecision(2)  << t << endl;

    system("pause");
    return 0;
}
