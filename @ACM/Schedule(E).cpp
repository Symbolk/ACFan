#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

void Table(int k, int n, int **a);


int main()
{
	int k;
	cin >> k;
	int n = 1;
	for (int i = 1; i <= k; i++)
		n *= 2;

	int **a = (int **)malloc(sizeof(int *) * (n+1));
    for(int i=0; i<=n; i++){
           a[i] = (int *)malloc(sizeof(int) * (n+1));
    }

	Table(k, n, a);

    for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
		    cout << a[i][j];
			if(j!=n){
                cout << " ";
		}
		if(i!=n){
                cout << endl;
		}
	}

	for(int i=0; i<=n; i++){
	    free(a[i]);
	}

    free(a);
	//system("pause");
	return 0;
}



void Table(int k, int n, int **a)
{
	for (int i = 1; i <= n; i++)
		a[1][i] = i;//日程表第一行

	int m = 1;//起始位置
	for (int s = 1; s <= k; s++)
	{
		n /= 2;
		for (int t = 1; t <= n; t++)
		{
			for (int i = m + 1; i <= 2 * m; i++)//行
			{
				for (int j = m + 1; j <= 2 * m; j++)//列
				{
					a[i][j + (t - 1)*m * 2] = a[i - m][j + (t - 1)*m * 2 - m];
					a[i][j + (t - 1)*m * 2 - m] = a[i - m][j + (t - 1)*m * 2];
				}

			}
		}
		m *= 2;
	}
}

