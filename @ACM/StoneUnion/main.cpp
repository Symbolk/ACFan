#include<iostream>
using namespace std;
//7
//2 5 58 69 2 3 56
//463��459����ô�����ˣ�
int N;//ʯ�ӵĶ���
int num[100]={0};//ÿ��ʯ�Ӹ���

int sum(int begin,int n)
{
     int total=0;
     for (int i=begin;i<=begin+n-1;i++)
     {   if(i==N)
              total=total+num[N];//ȡ��num[0]
         else
              total=total+num[i%N];
     }
     return total;
}
int stone_merge()
{
       int score[100][100];//score[i][j]:�ӵ�i��ʯ�ӿ�ʼ��j��ʯ�Ӻϲ�����С�÷�
       int n,i,k,temp;
       for (i=1;i<=N;i++)
           score[i][1]=0;//һ��ʯ�ӣ��ϲ��÷�Ϊ0

       //num[0]=num[N];//��Ҫ��sum()������i=Nʱ,ȡnum[0]
       for (n=2;n<=N;n++)//�ϲ���ʯ�ӵĶ���
       {
           for (i=1;i<=N;i++)//�ϲ���ʼλ��
           {
               score[i][n]=score[i][1]+score[(i+1-1)%N+1][n-1];
               for (k=2;k<=n-1;k++)//�ض�λ��
               {
                  temp=score[i][k]+score[(i+k-1)%N+1][n-k];
                  if(temp <score[i][n])
                        score[i][n] = temp;//�ӵ�i��ʼ��k���ǣ���i+0�ѵ���(i+k-1)%N��
               }
               score[i][n]+=sum(i,n);
           }
       }
       int min=2147483647;
       for (i=1;i<=N;i++)
       {    if (min>score[i][N])
                  min=score[i][N];//ȡ�ӵ�i�ѿ�ʼ��N�ѵ���С��
       }
       return min;
}

int main()
{
       int min_count=0;
       cin>>N;//ʯ�ӵĶ���
       while(N!=0)
       {
           for (int i=1;i<=N;i++)
               cin>>num[i];//ÿ��ʯ�ӵ�����//��1��ʼ,num[0]����
           min_count=stone_merge();
           cout<<min_count<<endl;

           for(i=0;i<N;i++)//׼����һ��
               num[i]=0;
           min_count=0;
           cin>>N;
       }
       return 0;
}
