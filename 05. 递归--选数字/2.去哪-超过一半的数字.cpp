#if 0
#include<string>
#include "iostream"
#include "vector"
#include "sstream"

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if (n == 0) return -1;

		int num = numbers[0], count = 1;
		for (int i = 1; i < n; i++) {
			if (numbers[i] == num) count++;
			else count--;
			if (count == 0) {
				num = numbers[i];
				count = 1;
			}
		}
		// Verifying
		count = 0;
		for (int i = 0; i < n; i++) {
			if (numbers[i] == num) count++;
		}
		if (count * 2 > n) return num;
		return -1;
	}
int main(){
	vector<int> vec;
	string str;
	while (getline(cin, str)){
		stringstream ss;
		ss.str(str);
		//ss << str;
		//cout << ss.str() << endl;
		char ch;
		int tmp;
		//ss.ignore(1);
		ss >> ch;
		//cout << ch << "....." << endl;
		while (ss >> tmp >> ch){
			//cout << ch << tmp << endl;
			vec.push_back(tmp);
		}
		//cout << "kong?\n";
	/*	for (auto it : vec)
		{
			cout << it << endl;
		}*/
		cout << MoreThanHalfNum_Solution(vec) << endl;
	}
}
#endif