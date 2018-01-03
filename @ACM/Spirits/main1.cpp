/**
*输入输入数据的第一行包含三个整数：N(0 < N < 1000)，M(0 < M < 500)，K(0 < K < 100)，分别代表小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量。
之后的K行，每一行代表一个野生小精灵，包括两个整数：收服该小精灵需要的精灵球的数量，以及收服过程中对皮卡丘造成的伤害。输出输出为一行，包含两个整数：C，R，分别表示最多收服C个小精灵，以及收服C个小精灵时皮卡丘的剩余体力值最多为R。
*/

#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
int a[100][2];
int get[100]={0};
vector<int> hp;
int ballMost=0,hpRest=0;

void check(){
    int ballNeed=0,hpNeed=0,c=0;
    for(int i=0;i<k;i++){
        if(get[i]==1){
            ballNeed+=a[i][0];
            hpNeed+=a[i][1];
            c++;
        }
    }
    if(ballNeed<=n){
        if(hpNeed<=m){
           //hpRest=(m-hpNeed)>hpRest?(m-hpRest):hpRest;
            //ballMost=c>ballMost?c:ballMost;
            if(c>=ballMost){
                ballMost=c;
                hp.push_back(hpNeed);
            }
        }
    }
}

void search(int m){
    if(m>=k-1){
        check();
    }else{
        get[m]=0;
        search(m+1);
        get[m]=1;
        search(m+1);
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        cin>>a[i][0]>>a[i][1];
    }
    ballMost=0;
    hpRest=m;
    search(0);
    for(vector<int>::iterator it=hp.begin();it!=hp.end();it++){
        if(*it<hpRest){
            hpRest=*it;
        }
    }
    hpRest=m-hpRest;
    cout<<ballMost<<" "<<hpRest<<endl;
    return 0;
}
