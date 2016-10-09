//http://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int deal(vector<int> v, vector<int> p, vector<int> q, int n, int money){
	vector<vector<int>> vec(n + 1, vector<int>(money + 1, 0));
	for (int i = 1; i<n + 1; ++i){
		for (int j = 0; j <= money; ++j){
			if (q[i] == 0 && j >= v[i]){
				if (vec[i - 1][j] < vec[i - 1][j - v[i]] + v[i] * p[i])
					vec[i][j] = vec[i - 1][j - v[i]] + v[i] * p[i];
				else
					vec[i][j] = vec[i - 1][j];
				//if(vec[i][j] < vec[i-1][j-v[i]] + v[i]*p[i])
				//  vec[i][j] = vec[i-1][j-v[i]] + v[i]*p[i];
			}
			else if (q[i] == 1 && j >= v[i] + v[q[i] - 1]){ //tip:这里不要考虑主见，只需要钱数量减少能容纳她就ok
				if (vec[i - 1][j] < vec[i - 1][j - v[i]] + v[i] * p[i])//+v[q[i]-1]*p[q[i]-1]
					vec[i][j] = vec[i - 1][j - v[i]] + v[i] * p[i];//+v[q[i]-1]*p[q[i]-1]
				//if(vec[i-][j] < vec[i-1][j-v[i]] + v[i]*p[i])//+v[q[i]-1]*p[q[i]-1]
				//vec[i][j] = vec[i-1][j-v[i]] + v[i]*p[i];//+v[q[i]-1]*p[q[i]-1]
				else
					vec[i][j] = vec[i - 1][j];
			}
		}
	}
	return vec[n][money];
}
int main(){
	int money;
	int n;
	while (cin >> money >> n){
		vector<int> v(n + 1, 0);
		vector<int> p(n + 1, 0);
		vector<int> q(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			cin >> v[i] >> p[i] >> q[i];
		cout << deal(v, p, q, n, money);
	}
	return 0;
}