#if 0
#include "iostream"
#include "string"
#include "vector"
using namespace std;

void deal(vector<int>& vec, int n, int key){
	int num = 0;
	int count = 0;
	for (int i = 0; num <= n; ++i)
	{
		i %= (n+1);
		if (vec[i] != -1)
		{
			++count;
			if (count == key)
			{
				key = vec[i];
				++num;
				vec[i] = -1;
				if (num != n+1)
					cout << i+1 << " ";
				else cout << i +1 << endl;
				count = 0;
			}
		}
	}
}
int main(){
	int n;
	int key;
	while (cin >> n >> key){
		vector<int> vec(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}
		if (n <= 0)
			continue;
		deal(vec, n-1, key);
	}
}
#endif