//POJ 2240 Arbitrage
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map<string,int> s2i;
int n,m;
int cases=0;
double rates[31][31];
//����ɨ��ÿһ��(k)�����Ըõ���Ϊ�н�㣬�����ͨ��k���������������(i,j)����̾��룬����Ķ�̬�滮�㷨
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
        char c[50];//�˴���POJ C++��CE������G++�¿��ԣ������Ǳ�׼����
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
        //��Ŀ˵�п��У�����еĻ���PE��ȥ��AC
        //cout<<endl;
    }
    return 0;
}
