#include<iostream>
#include<vector>

using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<vector<int> > vec(n, vector<int>(n, 0));
		int val = 0;
		for (int i = 0; i <= n; i += 1){
			for (int k = i; k < n - i; ++k)
				vec[i][k] = ++val;
			for (int row = i + 1; row < n - i; ++row)
				vec[row][n - i - 1] = ++val;
			for (int col = n - i - 2; col >= i; --col)
				vec[n - i - 1][col] = ++val;
			for (int row = n - i - 2; row > i; --row)
				vec[row][i] = ++val;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cout << vec[i][j] << " ";
		cout << endl;
	}
	return 0;
}