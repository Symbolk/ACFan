//Phone List(poj 3630)����Trie���һ�ּ򵥷�����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t,n;
string nums[10010];
bool judge(){
    int i,k,len;
    for(i=0;i<n-1;i++){
        len=nums[i].size();//string����ķ���������char�ĸ���
        for(k=0;k<len;k++){
            if(nums[i][k]!=nums[i+1][k]){
                break;
            }
        }
        if(k==len){//�����˳�ͻ�ĵ绰����
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
        sort(nums,nums+n);//���ֵ���������������ַע��
        if(judge()){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
