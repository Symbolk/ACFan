#include<stdio.h>
#define deep 15//�������--���ж�2^15��״̬
int Arr[deep]={0};
int num[10]={0};//�������������
int flag=0;//����Ƿ񵽴��յ�

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
            Arr[i]=0;//��ʼ��״̬ѡ������

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
    if(m==deep)//�����������
    {
        check();
        if(flag==1)
               return;//���ܱ任��Ŀ�겼�֣����ǲ����أ����ټ�������
    }
    else
    {    Arr[m]=1;//��ǰ�����A�任
        search(m+1);
                Arr[m]=0;//��ǰ�����B�任
            search(m+1);
    }
}
void check()//����Ƿ��ܵ���Ŀ��
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
int isaim()//�ж��Ƿ�任��Ŀ�겼��
{
    int i;
    for(i=0;i<6;i++)
    {
        if(num[i]!=i+1)
           return 0;
    }
    if(i==6) return 1;
}
