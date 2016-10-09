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
using namespace std;


int  getCloseNumber(int x) {
		// write code here
		vector<int> ivec;
		if (x <= 1)
			return 0;
		int left1 = 0;
		int num = x;
		while (num && ((num & 1) == 1)){
			left1++;
			num = num >> 1;
		}
		int left0 = 0;
		while (num && (num & 1) == 0){
			left0++;
			num = num >> 1;
		}
		//int min = x & ((~0) << (left0 + left1 + 1));
		int min = x & ~((1 << (left0 + left1 + 1)) - 1);
		int mask = (1 << (left1 + 1)) - 1;
		min |= mask << (left0 - 1);
		//ivec.push_back(x-(1 << left1) - (1<<left0 -1)+1);
		ivec.push_back(min);


		int num2 = x;
		int left00 = 0;
		int left01 = 0;
		while (num2 && (num2 & 1) == 0){
			left00++;
			num2 >>= 1;
		}
		while (num2 && (num2 & 1)){
			left01++;
			num2 >>= 1;
		}

		int max = x | (1 << left00 + left01);
		int mask2 = (~(0) << left00 + left01);
		max &= mask2;
		max |= ((1 << left01 - 1) - 1);
		//if(left01 + left00 >= 31 || letf00 +left01 == 0)
		//max = -1;
		ivec.push_back(max);
		return max;
	}

int main(){
	int n;
	while (cin >> n){
		int ans = getCloseNumber(n);
		cout << ans << endl;
	}
	return 0;
}
#endif