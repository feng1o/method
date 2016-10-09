#if 01
/*输入
输入中有多组测试数据。每组测试数据由3x3的矩阵构成，其中“X”表示按下的按键，“.” 表示未按下的按键。矩阵中可能不包含“X”，也可能没有“.”。
输出
对每组测试数据，在单独的行中输出结果，若密码是沿中心对称的，输出YES，否则输出NO。

样例输入
XX.
...
.XX
X.X
X..
...
样例输出
YES
NO*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool deal(vector<vector<char>> vec){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
		{
			if (vec[i][j] != vec[2 - i][2 - j])
				return false;
		}
	}
	return true;
}
int main(){
	while (1){
		vector<vector<char>> vec(3, vector<char>(3, '.'));
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> vec[i][j];
			}
		}


		if (deal(vec))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//if (cin.get() == '\n')
			//break;
	}
	return 0;
}


#endif
#if 0
#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool deal(vector<vector<char>> vec){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
		{
			if (vec[i][j] != vec[2 - i][2 - j])
				return false;
		}
	}
	return true;
}
int main(){
	vector<vector<char>> vec(3, vector<char>(3, '.'));
	int tmp;
	while (cin >> vec[0][0]){
		cin >> vec[0][1];
		cin >> vec[0][2];
		for (int i = 1; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> vec[i][j];
			}
		}


		if (deal(vec))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
#endif
