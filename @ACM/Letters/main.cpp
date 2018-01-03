#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
struct data{
    char letter;
    int count;
};
int comp(const void *a,const void *b)
{
    return ((*(struct data *)b).count - (*(struct data *)a).count);
}
int main()
{
    char buffer[1024];
    int results[128]= {0};
    struct data datas[52];//upper case&lower case
    int temp[52]={0};
    ifstream in("test.txt");
    if(!in.is_open())
    {
        cout<<"Error!"<<endl;
        return 1;
    }
    while(!in.eof())
    {
        char c=in.get();
        results[c]++;
    }
    //copy the data into the new array
    for(int i=65;i<=90;++i){
        temp[i-65]=results[i];//0-25,UpperCase
    }
    for(int i=97;i<=122;++i){
        temp[i-71]=results[i];//26-51,LowerCase
    }

    //construct the array to be sorted with qsort
    for(int i=0; i<26; ++i)
    {
        datas[i].letter=char(i+65);
        datas[i].count=temp[i];
    }
     for(int i=26; i<52; ++i)
    {
        datas[i].letter=char(i+71);
        datas[i].count=temp[i];
    }

    //sort according to the count
    qsort(datas,52,sizeof(struct data),comp);

    for(int i=0; i<52; ++i)
    {
        if(datas[i].count!=0){
            cout<<datas[i].letter<<":"<<datas[i].count<<endl;
        }
    }
    in.close();
    return 0;
}
