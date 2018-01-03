#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string lines[11];
    getchar();
    for(int i=0;i<n;++i)
    {
        getline(cin,lines[i]);
    }

    for(int i=0;i<n;++i){

        int counts[26]= {0};
        string line=lines[i];
        for(int k=0; k<line.length(); ++k)
        {
            for(int j=0; j<26; ++j)
            {

                if(line[k]=='a'+j)
                {
                    counts[j]++;
                }
            }
        }
        for(int j=0; j<26; j++)
        {
            cout<<counts[j];
            if(j!=25)
            {
                cout<<" ";
            }
            else
            {
                cout<<endl;
            }
        }
    }
    return 0;
}
