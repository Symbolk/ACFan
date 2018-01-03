#include <iostream>
#include <cstdio>
#include <cstring>
//编写程序，读入一行英文(只包含字母和空格，单词间以单个空格分隔)，将所有单词的顺序倒排并输出，依然以单个空格分隔。
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

