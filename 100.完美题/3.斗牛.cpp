/*纸牌游戏-斗牛
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
纸牌游戏斗牛，每人发5张牌，从中选三张加起来是十的倍数，即为有牛(J,Q,K计为十)，然后比较剩下两张加起来个位数的大小，称为牛数，若相加为10的整数倍，则为牛10。
比如：牌面为A，5,6，9，K。A+9+K=20（即为有牛），5+6=11（个位数为1，即牛数为1）。
牌面为2,3,5,7,3。2+3+5=10（牛），7+3=10（牛10）。
牌面为2,4,3,6,7,A。任何3个数相加不为10的整数倍，则为无牛。
输入
输入5个数字，A，J，Q，K用字母表示。注意：输入数字之间用“,”隔开
输出
输出牛数，注意：无牛和错误输出none

样例输入
A，5,6，9，K
样例输出
1

Hint
暴力循环判断即可。关键需要考虑异常情况，如相同是数最多只能4个，输入的数合法性检测
*/
#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "algorithm"

using namespace std;

int deal(vector<int> vec){
	sort(vec.begin(), vec.end());
	if (vec[0] == vec[1] && vec[1] == vec[2] && vec[2] == vec[3] && vec[3] == vec[4])
		return 0;
	int n = 4;
	while (vec[n] == 10) --n;
	for (int i = 0; i <= n ; ++i)
	{
	}
}
int main(){
	string str;
	while (getline(cin, str)){
		vector<int> vec;
		stringstream ss;
		ss.str("");
		ss << str;
		char ch;
		int flag = 1;
		while (ss >> ch){
			if (flag == 1){
				if (isdigit(ch))
					vec.push_back(ch - '0');
				else if (ch == 'A')
					vec.push_back(1);
				else 
					vec.push_back(10);
				flag = -1;
			}
			else{
				flag = 1;
				continue;
			}
		}
	/*	for (auto it : vec)
		{
			cout << ".." << it << endl;
		}*/
		int tn = deal(vec);
		if (tn == 0)
			cout << "none" << endl;
		else
			cout << tn << endl;
	}
	return 0;
}



#include<iostream>
using namespace std;
int isNiu(int* arr){
	int i = 0, j = 0, k = 0;
	bool flag = 1;
	for (i = 0; i < 3; i++){
		for (j = i + 1; j < 4; j++){
			for (k = j + 1; k < 5; k++){
				if ((arr[i] + arr[j] + arr[k]) % 10 == 0){
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag) break;
	}
	if (flag) return -1;
	int res = 0;
	for (int z = 0; z < 5; z++){
		if (z != i&&z != j&&z != k)
			res += arr[z];
	}
	if (res % 10 == 0) return 10;
	else return res % 10;
}
int main(){
	char c;
	int a[5];
	int i = 0;
	while (cin >> c)
	{
		if (c == 'A')
		{
			a[i++] = 1;
		}
		else if (c == 'J')
		{
			a[i++] = 10;
		}
		else if (c == 'Q')
		{
			a[i++] = 10;
		}
		else if (c == 'K')
		{
			a[i++] = 10;
		}
		else if (c == '1')
		{
			if (cin.get() != '0')
			{
				cout << "none" << endl;
				return 0;
			}
			a[i++] = 10;
		}
		else if (c >= '2'&&c <= '9')
		{
			a[i++] = c - '0';
		}
		else
		{
			cout << "none" << endl;
			return 0;
		}
		if (cin.get() == '\n')
			break;
	}
	int res = isNiu(a);
	if (res == -1)cout << "none" << endl;
	else cout << res << endl;
	return 0;
}

