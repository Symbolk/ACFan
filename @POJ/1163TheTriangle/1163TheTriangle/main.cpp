#include <iostream>

using namespace std;

int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	//a least representation of the triangle
	int **data=new int*[n];
	for(int i=0;i<n;++i){//row
		data[i]=new int[i+1];//col
		for(int j=0;j<=i;++j){
			cin>>data[i][j];//every row, from [i][0] to [i][i]
		}
	}
	//dp
	for(int i=n-2;i>=0;--i){//from the 2nd last row
		for(int j=0;j<=i;++j){
			//get the bigger one in every pair, and add that up(up+=max{left, right})
			data[i][j] += data[i+1][j] > data[i+1][j+1] ? data[i+1][j] : data[i+1][j+1];
		}
	}

	//the top one as the max sum
	cout<<data[0][0]<<endl;
	return 0;
}