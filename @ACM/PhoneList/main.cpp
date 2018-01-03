//Phone List(poj 3630)除了Trie外的一种简单方法！
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t,n;
string nums[10010];
bool judge(){
    int i,k,len;
    for(i=0;i<n-1;i++){
        len=nums[i].size();//string数组的方法，返回char的个数
        for(k=0;k<len;k++){
            if(nums[i][k]!=nums[i+1][k]){
                break;
            }
        }
        if(k==len){//发现了冲突的电话号码
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums,nums+n);//按字典序进行排序，这里地址注意
        if(judge()){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
