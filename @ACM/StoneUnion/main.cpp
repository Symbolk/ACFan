#include<iostream>
using namespace std;
//7
//2 5 58 69 2 3 56
//463？459？怎么过不了？
int N;//石子的堆数
int num[100]={0};//每堆石子个数

int sum(int begin,int n)
{
     int total=0;
     for (int i=begin;i<=begin+n-1;i++)
     {   if(i==N)
              total=total+num[N];//取代num[0]
         else
              total=total+num[i%N];
     }
     return total;
}
int stone_merge()
{
       int score[100][100];//score[i][j]:从第i堆石子开始的j堆石子合并后最小得分
       int n,i,k,temp;
       for (i=1;i<=N;i++)
           score[i][1]=0;//一堆石子，合并得分为0

       //num[0]=num[N];//重要：sum()函数中i=N时,取num[0]
       for (n=2;n<=N;n++)//合并的石子的堆数
       {
           for (i=1;i<=N;i++)//合并起始位置
           {
               score[i][n]=score[i][1]+score[(i+1-1)%N+1][n-1];
               for (k=2;k<=n-1;k++)//截断位置
               {
                  temp=score[i][k]+score[(i+k-1)%N+1][n-k];
                  if(temp <score[i][n])
                        score[i][n] = temp;//从第i开始的k堆是：第i+0堆到第(i+k-1)%N堆
               }
               score[i][n]+=sum(i,n);
           }
       }
       int min=2147483647;
       for (i=1;i<=N;i++)
       {    if (min>score[i][N])
                  min=score[i][N];//取从第i堆开始的N堆的最小者
       }
       return min;
}

int main()
{
       int min_count=0;
       cin>>N;//石子的堆数
       while(N!=0)
       {
           for (int i=1;i<=N;i++)
               cin>>num[i];//每堆石子的数量//从1开始,num[0]不用
           min_count=stone_merge();
           cout<<min_count<<endl;

           for(i=0;i<N;i++)//准备下一轮
               num[i]=0;
           min_count=0;
           cin>>N;
       }
       return 0;
}
