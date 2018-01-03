#include <iostream>

using namespace std;

bool checkMin(int min)
{
	int i;
	for (i = 100; i >= 2; i--)
	{
		if (min % i == 0)
		{
			min /= i;
			if (min == 1)
				return 1;
		}
	}
	return min == 1;
}

bool notConflict(int max, int min, int n)
{
	//²»³åÍ»
	if (max == 1 && min == 1)
		return 1;
	//³åÍ»ÁË
	else if (n == 1)
		return 0;
	else
	{
		return  (max % n == 0 && notConflict(max / n, min, n - 1) ||
			min % n == 0 && notConflict(max, min / n, n - 1) ||
			notConflict(max, min, n - 1));
	}
}

int main()
{
	int a, b;
	while (cin >> a >> b&&(a||b))
	{
		if (a == 0 && b == 0)
			break;
		//a >= b
		a= a>=b ? a : b;
		if(a<=100||a>9900){
            cout<<a<<endl;
        }else{
		cout << (checkMin(b) && !notConflict(a, b, 100) ? b : a)<< endl;
        }
	}
	return 0;
}
