#include <iostream>
#include <cstring>
#include <queue>
#define N 26
using namespace std;

int n,h;
//if x lakes visited, time spent on the lake y is timespent[x][y]
int timespent[N][N];
int f[N],d[N],t[N];

class Lake{
public:
	int id;
	int f;
	int d;
	friend bool operator < (Lake a, Lake b){
		if(a.f==b.f){
			return a.id > b.id;
		}
		return a.f<b.f;
	}
	//Constructor
	Lake(int i, int fi, int de):id(i),f(fi),d(de){
	}
	Lake(){
	}
};
Lake lakes[N];

int main(){
	while(cin>>n&&n){
		int maxfish=0;
		cin>>h;
		memset(timespent, 0, sizeof(timespent));
		h*=12;// 1 hour= 12 * 5mins
		for(int i=1;i<=n;i++){
			lakes[i].id=i;
			cin>>lakes[i].f;
		}
		for(int i=1;i<=n;i++){
			cin>>lakes[i].d;
		}
		for(int i=1;i<n;i++){
			cin>>t[i];
		}
		int kmax=1;//as far as the lake k
		// try all the cases, visit lake[1]to lake[i]
		for(int i=1;i<=n;i++){
			int walktime=0;
			for(int j=1;j<i;j++){
				walktime+=t[j];
			}
			int fishtime=h-walktime;

			priority_queue<Lake> temp;//use pri-queue to rank automatically
			//find the max fish in the i lakes
			for(int j=1;j<=i;j++){
				temp.push(lakes[j]);//lakes will be ordered according to its f
			}
			//begin fishing and get the current max fish num
			int curmax=0;
			for(int k=1;k<=fishtime;k++){
				Lake l=temp.top();
				temp.pop();
				curmax+=l.f;
				timespent[i][l.id]++;//spend 5 mins on the lake l
				//update the visited lake
				int fishleft=l.f-l.d > 0 ? (l.f-l.d) : 0;
				Lake newl(l.id, fishleft, l.d);
				temp.push(newl);
			}
			if(curmax>maxfish){
				maxfish=curmax;
				kmax=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i<n){
				cout<<timespent[kmax][i]*5<<", ";
			}else{
				cout<<timespent[kmax][i]*5<<endl;
			}
		}
		cout<<"Number of fish expected: "<<maxfish<<endl;
		cout<<endl;
	}
	return 0;
}