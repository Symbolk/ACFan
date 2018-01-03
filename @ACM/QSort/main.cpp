#include <stdio.h>
#define maxsize 10000

int b[maxsize];
int a;

void input()

{

 scanf("%d",&a);

    for(int i=1;i<=a;i++)

 {

  scanf("%d",&b[i]);

 }

}

void QSort(int m[],int i)
{

 int x=1;

 while(x<i)

 {

  while(m[x]<=m[x+1]&&x<i)

  {

   x++;

  }

  if(m[x]>m[x+1]&&x<i)

  {

   int d=x;

   m[0]=m[d];

   int j;

   j=m[d+1];

   while(j<m[d-1]&&d>1)

   {

    m[d]=m[d-1];

    d--;

   }

   m[d]=j;

   m[x+1]=m[0];

   x++;

  }

 }

 }

void printf(int m[])

{

 for(int i=1;i<=a;i++)

 {

  printf("%d\n",m[i]);

 }

}

void main()

{  input();

 QSort(b,a);

 printf(b);

}
