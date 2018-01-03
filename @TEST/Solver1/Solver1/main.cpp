#include <iostream>  
#include <stack>  
#include <fstream>
#include <string> 

using namespace std;

int paren(const string &str)  
{  
	stack<char> s; 
	for (int i = 0; i < str.size();i++)  
	{  
		switch (str[i])  
		{  
		case '(':s.push(str[i]); break;  
		case ')':
			if(s.empty()){
				s.push(str[i]);
				break;
			}else{
				if (s.top() != '('){
					s.push(str[i]);
				}else
					s.pop(); break;  
			}


		default:  
			break;  
		}  
	}  
	return s.size();  
}  

int main()  
{  
	string line;
	freopen("in1.txt","r",stdin);
	ofstream outfile;
	outfile.open("out1.txt");
	while(cin>>line){
		outfile<<paren(line)<<endl;
	}
	getchar();
	return 0;  
}  