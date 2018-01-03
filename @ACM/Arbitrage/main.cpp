//POJ 2240 Arbitrage
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map<string,int> s2i;
int n,m;
int cases=0;
double rates[31][31];
//依次扫描每一点(k)，并以该点作为中介点，计算出通过k点的其他任意两点(i,j)的最短距离，经典的动态规划算法
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //rates[i][j] = rates[i][j]<rates[i][k]*rates[k][j]) ? rates[i][k]*rates[k][j]:rates[i][j];
                if(rates[i][j]<rates[i][k]*rates[k][j]){
                    rates[i][j]=rates[i][k]*rates[k][j];
                }
            }
        }
    }
}

int main()
{
    while(cin>>n&&n){
        cases++;
        int i=0;
        bool flag=false;
        //string c;
        char c[50];//此处在POJ C++下CE，但在G++下可以，想来是标准问题
        memset(rates,10000,sizeof(rates));
        for(i=1;i<=n;i++){
            cin>>c;
            s2i[c]=i;
            rates[i][i]=1;
        }
        cin>>m;
        string c1,c2;
        double rate;
        for(i=1;i<=m;i++){
            cin>>c1>>rate>>c2;
            rates[s2i[c1]][s2i[c2]]=rate;
        }
        floyd();
        for(i=1;i<=n;i++){
            if(rates[i][i]>1){
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"Case "<<cases<<": Yes"<<endl;
        }else{
            cout<<"Case "<<cases<<": No"<<endl;
        }
        //题目说有空行，结果有的话会PE，去则AC
        //cout<<endl;
    }
    return 0;
}
