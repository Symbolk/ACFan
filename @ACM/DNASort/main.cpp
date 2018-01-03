#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
//POJ 1007
using namespace std;
char dnas[100][50];//m rows and length cols
int length=0;
struct DNA{
    int row;
    int count;
};
DNA *d=new DNA[100];
//vector<DNA> d(100);
int compare (const void * a, const void * b)
{
    const DNA *p1=(const DNA*)a;
    const DNA *p2=(const DNA*)b;
    if(p1->count > p2->count){
        return 1;
    }else if(p1->count < p2->count){
        return -1;
    }else{//equals
        if(p1->row>p2->row){
            return 1;
        }else{
            return -1;
        }
    }
   // return (p1->count)-(p2->count);
}

int main()
{
    int m;
    while(cin>>length>>m){
    int i=0,j=0;
    char c;
    for(i=0;i<m;i++){
        getchar();
        for(j=0;j<length;j++){
            c=getchar();
            dnas[i][j]=c;
        }
    }
    for(i=0;i<m;i++){
        d[i].row=i;
        d[i].count=0;
        for(j=0;j<length;j++){
            for(int k=j+1;k<length;k++){
                if(dnas[i][j]>dnas[i][k]){
                    d[i].count++;
                }
            }
        }
    }
    qsort(d,m,sizeof(DNA),compare);
//    for(i=0;i<m;i++){
//        cout<<d[i].count<<" "<<d[i].row<<endl;
//    }
    for(i=0;i<m;i++){
        int r=d[i].row;
        for(j=0;j<length;j++){
            cout<<dnas[r][j];
        }
            cout<<endl;
    }
    }
  //  cout<<d[0].count<<endl;
    return 0;
}
