#if 0
#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>
#include "cassert"
#include "cmath"
#include "numeric"
#include "functional"
#include "set"
#include "map"
using namespace std;

bool isDoubleStr(string str){
	int size = str.size();
	if (size % 2 != 0)
	{
		return false;
	}
	//cout << "ooooo\n";
	//cout << str << endl;
	for (int i = 0; i < size / 2; ++i)
	{
		//cout << i << " " << str[i] << " " << size - i-1 << " " << str[size - i-1] << endl;
		if (str[i] != str[size/2 + i])
		{
			return false;
		}
	}
//	cout << str << "...." << "true " << endl;
	return true;
}
int getDoubleStr(string str){
	map<string, int> map;
	int size = str.size();
	int cnt = 0;
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			string substr(str.begin() + i, str.begin() + j+1);
		//	cout << substr << endl;
			bool flag = isDoubleStr(substr);
			if (flag && map.count(substr) == 0)
			{
				//cout << cnt << endl;
				++cnt;
				map.insert(make_pair(substr, 1));
			}
		}
	}
	return cnt;
}
int main(){
	string str;
	while (cin >> str){
		int cnt = getDoubleStr(str);
		cout << cnt << endl;
	}
	return 0;
}

//aaabccabccCC
//aa  abab是的重复只记一次
#endif

#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>
#include "cassert"
#include "cmath"
#include "numeric"
#include "functional"
#include "set"
#include "map"
using namespace std;

vector<int> quickSort(vector<int>& str, int begin, int end){  
	if (begin < end){
		char key = str[end];
		int lhs = begin - 1;
		for (int j = begin; j < end; ++j){
			if (str[j] <= key){
				++lhs;
				swap(str[lhs], str[j]);
			}
		}
		swap(str[lhs + 1], str[end]);
		quickSort(str, begin, lhs);
		quickSort(str, lhs + 2, end);
	}
	return str;
}
bool func(int N){
	vector<int> vec;
	time_t tm;
	tm = time(&tm);
	srand(tm);
	for (int i = 0; i < N; ++i)
	{
		int tmp = rand() % 101;
		vec.push_back(tmp);
	}
	quickSort(vec, 0, vec.size()-1);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << " " <<  vec[i] << endl;
	}
	return true;
}
int main()
{
	func(10);
	return 0;
}
