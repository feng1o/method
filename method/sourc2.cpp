#if 0

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include "algorithm"
#include "vector"

using namespace std;
class A{
public:
	virtual void  fun(){
		g();
		cout << "..." << a << endl;
	}
protected:
	virtual void g(){
		a = 2;
	}
private:
	int a;
};

class B
int  deal(int num){
	int sum = 0;
	for (int i = 1; i <= num; ++i)
	{
		int tmp = i;
		int sum10 = 0;
		while (tmp > 0){
			sum10 += tmp % 10;
			tmp /= 10;
		}

		tmp = i;
		int bsum = 0;
		while (tmp > 0){
			if (tmp % 2 == 1)
				++bsum;
			tmp /= 2;
		}
		if (sum10 == bsum)
		{
			++sum;
		}
	}
	return sum;
}
int main(){
	int n, m;
	while (cin >> n){
		vector<int> vec(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}
		//sort(vec.begin(), vec.end());
		for (int i = 0; i < n; ++i)
		{
			cout << deal(vec[i]) << endl;
		}
	}
	return 0;
}
#endif

