#include <iostream>
#include <sstream>
using namespace std;

string convertToString(int num)
{
    ostringstream os;
    if (os<<num){
        return os.str();
    }
    else{
        return "error";
    }
}
int main()
{
    int n,num;
    cin>>n;
    string result;
    string *data=new string[n+1];
    for(int i=0;i<n;i++){
        cin>>num;
        data[i]=convertToString(num);
    }
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            if(data[i]+data[j]<data[j]+data[i]){
                string temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        result+=data[i];
    }
    cout<<result<<endl;
    return 0;
}
