#include<stdio.h>
#define deep 15//深搜深度--共判断2^15种状态
int Arr[deep]={0};
int num[10]={0};//六个格子填的数
int flag=0;//标记是否到达终点

void search(int m);
void Achange();
void Bchange();
void check();
int isaim();
////////////////////////////////////////////////////
int main()
{
    while(scanf("%d",&num[0])!=EOF)
    {
        flag=0;
        for(int i=0;i<deep;i++)
            Arr[i]=0;//初始化状态选择数组

        for(int i=1;i<6;i++)
            scanf("%d",&num[i]);
        search(0);
        if(flag==1)    printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
void search(int m)//0,1,2.....15
{
    if(m==deep)//到达搜索深度
    {
        check();
        if(flag==1)
               return;//若能变换到目标布局，则标记并返回，不再继续搜索
    }
    else
    {    Arr[m]=1;//当前层进行A变换
        search(m+1);
                Arr[m]=0;//当前层进行B变换
            search(m+1);
    }
}
void check()//检查是否能到达目标
{
    for(int i=0;i<deep;i++)
    {
        if(Arr[i]==1)
        {
            Achange();
                        if(isaim())
            {  flag=1;  return; }
        }
        else
        {
            Bchange();
            if(isaim())
            {  flag=1;  return; }
        }
    }
}
void Achange()
{
    int temp=num[0];
    num[0]=num[3];
    num[3]=num[4];
    num[4]=num[1];
    num[1]=temp;
}
void Bchange()
{
    int temp=num[1];
    num[1]=num[4];
    num[4]=num[5];
    num[5]=num[2];
    num[2]=temp;
}
int isaim()//判断是否变换到目标布局
{
    int i;
    for(i=0;i<6;i++)
    {
        if(num[i]!=i+1)
           return 0;
    }
    if(i==6) return 1;
}
