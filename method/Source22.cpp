#if 0
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;
int main(){
	int n, m;
	while (cin >> n){
		if (1 == n || 2 == n){
			cout << 1 << '/' << 1 << endl;
			continue;
		}
		int num = n;
		int sum = 0;
		for (int i = 2; i < n; ++i)
		{
			num = n;
			while (num > 0)
			{
				sum += num%i;
				num /= i;
			}
		}
		//最大公约数
		int nn = n - 2;
		int rsum = sum;
		while (sum % nn)
		{
			int tmp = sum % nn;
			sum = nn;
			nn = tmp;
		}
		cout << rsum/nn << '/' << (n-2)/nn << endl;
	}
	return 0;
}
#endif