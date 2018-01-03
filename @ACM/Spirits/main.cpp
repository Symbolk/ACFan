//百练 宠物小精灵
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
class twoInt {
public:
	int fir,sec;//ball/SpiritsGet, hp
	twoInt (int f = 0, int s = 0):fir(f), sec(s){}
};
twoInt re[1000][500], jl[100], tmp1, tmp2;//State & Spirits
int main()
{
	int n, m, k, i, j, a, b;
	cin >> n >> m >> k;
	for(i = 1; i <= k; ++i)
        cin >> jl[i].fir >> jl[i].sec;
	for(a = 0; a <= n; ++a)
        for(b = 0; b <= m; ++b)
            re[a][b].sec = b;//?
	for(i = 1; i <= k; ++i){
        for(a = n; a >= 1; --a){
            for(b = m; b >= 1; --b){
                tmp1 = twoInt();
                tmp2 = re[a][b];//pass curent jl
                if(tmp2.fir > tmp1.fir) tmp1 = tmp2;
                else if(tmp2.fir == tmp1.fir && tmp2.sec > tmp1.sec) tmp1 = tmp2;
                if(a - jl[i].fir >= 0 && b - jl[i].sec >= 0){//get curent jl
                    tmp2 = re[a - jl[i].fir][b - jl[i].sec];
                    tmp2.fir++;//?
                    if(tmp2.fir > tmp1.fir) tmp1 = tmp2;
                    else if(tmp2.fir == tmp1.fir && tmp2.sec > tmp1.sec) tmp1 = tmp2;
                }
            re[a][b] = tmp1;
            }
        }
	}
	cout << re[n][m].fir << ' ' << re[n][m].sec;
	return 0;
}
