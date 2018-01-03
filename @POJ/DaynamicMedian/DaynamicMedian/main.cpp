#include <iostream>
#include <queue>
#include <functional>
#include <cstdio>
#include <cassert>
using namespace std;
const int T=600;
const int N=10000;
int t,n;
int num=0;//当前数字的个数
//小数组成的最大堆
priority_queue<int, vector<int>, less<int> > pq1;
//大数组成的最小堆
priority_queue<int, vector<int>, greater<int> > pq2;

//init
void init(){
while(!pq1.empty()){
	pq1.pop();
}
while(!pq2.empty()){
	pq2.pop();
}
}

void check(){
	int tmp=pq1.size()-pq2.size();
	assert (abs(tmp)<=1);
	return;
}
//调整以使左右堆元素个数相同或差1
void balance(){
	if(pq1.size()+1<pq2.size()){
		pq1.push(pq2.top());
		pq2.pop();
	}else if(pq1.size()>pq2.size()+1){
		pq2.push(pq1.top());
		pq1.pop();
	}
}

void insert(int num){
	if(pq1.empty()&&pq2.empty()){
		pq1.push(num);
		return;
	}
	if(!pq1.empty()&&num<=pq1.top()){
		pq1.push(num);
	}else if(!pq2.empty()&&num>pq2.top()){
		pq2.push(num);
	}else{
		pq1.push(num);
	}
	balance();
}

int query(){
	assert (!pq1.empty() || !pq2.empty());
	check();
	if(pq1.size()<pq2.size()){
		return pq2.top();
	}else{
		return pq1.top();
	}
}

void del_median(){
	assert (!pq1.empty() || !pq2.empty());
	if(pq1.size() < pq2.size()){
		pq2.pop();
	}else{
		pq1.pop();
	}
	return;
}

int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		char ops;//operator	
		int opr;//operand
		num=0;
		init();
		while(n--){
			getchar();
			scanf("%c",&ops);
			switch(ops){
			case 'I': 	
					scanf("%d",&opr);
					insert(opr);
					check();
					break;
			case 'Q':
					cout<<query()<<endl;
					break;
			case 'D':
					del_median();
					break;
			}
		}
	}
	return 0;
}