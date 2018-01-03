#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
	ofstream infile;
	infile.open("in2.txt");
	for(int i=0;i<100;i++){
		int row=rand()%20+1;
		int col=rand()%20+1;
		infile<<row<<" "<<col<<endl;		
		for(int r=0;r<row;r++){
			for(int c=0;c<col;c++){
				infile<<rand()%2;
				if(c==col-1){
					infile<<endl;
				}else{
					infile<<" ";
				}
			}
		}
		//infile<<endl;
	}	
	getchar();
	return 0;
}
