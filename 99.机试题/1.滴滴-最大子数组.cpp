/*#include<iostream>
#include<vector>

using namespace std;

int getMax(vector<int> arr, int N);

int main(){
	int N = 0;
	while (cin >> N)
	{
		if (N <= 0){
			continue;
		}
		vector<int> arr(N, 0);
		cin.ignore(3, '\n');
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		cout << getMax(arr, N) << endl;
	}
	return 0;
}
int getMax(vector<int> arr, int n){
	if (n > 0){
		int max = arr[0];
		int now = arr[0];
		for (int i = 0; i < n; ++i){
			now = now < 0 ? 0 : now;
			now += arr[i];
			if (now > max)
				max = now;
		}
		return max;
	}
	else
		return 0;
}

*/
/*

#include<iostream>
#include<vector>

using namespace std;
int deal(vector<int> vec, int n){
	if (n > 0){
		int max = vec[0];
		int cur = vec[0];
		for (int i = 0; i < n; ++i){
			//cur = cur < 0 ? 0 : cur;
			if (cur <= 0)
				cur = 0;
			cur += vec[i];
			if (cur > max)
				max = cur;
		}
		return max;
	}
	else
		return 0;
}
int main(){
	int n = 0;
	while (cin >> n){
		//cout << "n=" << n << endl;
		if (n <= 0)
			continue;
		cin.ignore(1, '\n');
		vector<int> vec(n, 0);
		for (int i = 0; i < n; ++i){
			cin >> vec[i];
		}
		//for (auto it : vec)
		//	cout << "..." << it << endl;
		cout << deal(vec, n) << endl;
	}

	return 0;
}

*/