#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("test.txt","r");
    fp2=fopen("result.txt","w");
    if(fp1 == NULL||fp2==NULL)
    {
        cout<<"ERROR!"<<endl;
        return 1;
    }
    char str[100];
    float grades[15];
    int count=0;
    float sum=0.0,average=0.0,max=-1.0,min=101.0,veriance=0.0;
    while(fscanf(fp1,"%s",str)!=EOF)
    {
        int n=atoi(str);
        max=max>n?max:n;
        min=min<n?min:n;
        sum+=n;
        grades[count]=n;
        count++;
    }
    average=sum/count;
    for(int i=0;i<count;i++){
        veriance+=pow(grades[i]-average,2);
    }
    veriance/=count;

    fprintf(fp2,"average:%.2f\n",average);
    fprintf(fp2,"max:%.2f\n",max);
    fprintf(fp2,"min:%.2f\n",min);
    fprintf(fp2,"veriance:%.2f\n",veriance);

    return 0;
}

