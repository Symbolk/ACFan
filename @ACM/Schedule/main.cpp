#include<iostream>
#include<cmath>
using namespace std;
//ѭ�����ճ̱�����
void gametable(int k)
{
    int a[100][100];
    int n,temp,i,j,p,t;
    n=2;//k=1��������ѡ���ճ̿���ֱ�����
    a[1][1]=1;a[1][2]=2;
    a[2][1]=2;a[2][2]=1;
    for(t=1;t<k;t++)//�������������δ���2^n....2^k��ѡ�ֵı����ճ�
    {
        temp=n;n=n*2;//�����½�Ԫ��
        for(i=temp+1;i<=n;i++){
            for(j=1;j<=temp;j++){
                a[i][j]=a[i-temp][j]+temp;//���½Ǻ����Ͻ�Ԫ�صĶ�Ӧ��ϵ
            }
        }
        for(i=1;i<=temp;i++){//�����½�Ԫ�س������Ͻ�
            for(j=temp+1;j<=n;j++){
                a[i][j]=a[i+temp][(j+temp)%n];
            }
        }
        for(i=temp+1;i<=n;i++){//�����Ͻ�Ԫ�س������½�
            for(j=temp+1;j<=n;j++){
                a[i][j]=a[i-temp][j-temp];
            }
        }
    }
    cout<<"��������Ϊ:"<<n<<"\n(��i�е�j�б�ʾ�͵�i��ѡ���ڵ�j�������ѡ�����)\n"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            cout<<a[i][j];
            if(j==n){
                cout<<endl;
            }
        }
    }
}

int main()
{
    int k;
    cout<<"����ѡ�ָ���Ϊn(n=2^k)�����������K(K>0):"<<endl;
    cin>>k;
    if(k!=0)
    gametable(k);
    return 0;
}