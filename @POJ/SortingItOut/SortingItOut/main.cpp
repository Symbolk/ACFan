#include <iostream>
#include <queue>
#include <vector>

#define N 27
using namespace std;

int n, m;
int temp[N],in[N], result[N];
vector<int> Graph[N];//vecotr array to store in nodes of every node

int topo();

int main(){
	char x, y;
	int count, over;
	int accepted;
	while(cin>>n>>m&&(n||m)){
		memset(in, 0, sizeof(in));
		memset(temp, 0, sizeof(temp));
		for(int i=0;i<n;i++){
			Graph[i].clear();
		}
		over=accepted=0;
		while(m--){
			accepted++;
			getchar();
			x=getchar();
			getchar();
			y=getchar();
			Graph[x-'A'].push_back(y-'A');//edge from x to y
			in[y-'A']++;
			memcpy(temp, in, sizeof(temp));
			if(over){
				continue;

			}
			count = topo();
			if(count<0){
				over = 1;

			}else if(count){
				over=2;
			}
		}
		switch(over){
		case 1:
			cout<<"Inconsistency found after "<<accepted<<" relations."<<endl;break;
		case 2:
			cout<<"Sorted sequence determined after "<<accepted<<" relations:";
			for(int i=0;i<n;i++){
				char c=result[i]+'A';
				cout<<c;
			}
			cout<<"."<<endl;
			break;
		default:
			cout<<"Sorted sequence cannot bedetermined."<<endl;
		}
	}
	return 0;
}

int topo(){
	memset(result, 0, sizeof(result));
	int count =0, ok=0;
	queue<int> zero;
	for(int i=0;i<n;i++){
		if(temp[i]==0){
			zero.push(i);
		}
	}
	while(!zero.empty()){
		if(zero.size()>1){
			ok=1;
		}
		int node=zero.front();
		result[count]=node;
		count++;
		zero.pop();
		//remove edges from every 0-in node
		for(int i=0;i < Graph[node].size();i++){
			int left=temp[Graph[node][i]]--;
			if(left==0){
				zero.push(Graph[node][i]);
			}
		}
	}
	if(count<n){
		return -1;
	}else if(ok){
		return 0;
	}else{
		return 1;
	}
}