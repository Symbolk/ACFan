#include <iostream>
#include <cstdio>
#include <cstring>
//��д���򣬶���һ��Ӣ��(ֻ������ĸ�Ϳո񣬵��ʼ��Ե����ո�ָ�)�������е��ʵ�˳���Ų��������Ȼ�Ե����ո�ָ���
using namespace std;
void Reserve(char *begin,char *end)
{
	while(begin<end)
	{
		char temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}
}

int main()
{
	char a[100];
	gets(a);
	char *begin,*end;
	char*p1,*p2;
	begin=a;
	end=a+strlen(a)-1;
	Reserve(begin,end);
	p1=p2=a;
	while(*p2!='\0')
	{
		while((*p2>='a' &&*p2<='z')||(*p2>='A' &&*p2<='Z'))
			p2++;
		Reserve(p1,p2-1);
		p2=p2+1;
		p1=p2;
	}
	puts(a);
}

