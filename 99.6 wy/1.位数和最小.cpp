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

int deal(int lhs, int rhs, int mid){
	vector<int> vmid;
	while (mid > 0){
		int tmp = mid % 10;
		vmid.push_back(tmp);
		mid = mid / 10;
	}
	sort(vmid.begin(), vmid.end(), greater<int>());
	for ( auto it : vmid)
	{
		cout << it << endl;
	}
	int ans = 0;
	for (int i = 0; i < vmid.size(); ++i)
	{
		int anst = ans;
		anst = anst * 10 + vmid[i];
		if (anst < lhs || anst)
		{

		}
	}
	return 0;
}

int getsum(int mid){
	mid = abs(mid);
	int sum = 0;
	while (mid > 0){
		int tmp = mid % 10;
		//vmid.push_back(tmp);
		sum += tmp;
		mid = mid / 10;
	}
	return sum;
}

int  deal2(int lhs, int rhs, int mid){
	int sum = getsum(mid);
	int last = lhs;
	int min = INT_MAX;
	for (int i = lhs; i <= rhs; ++i)
	{
		int tsum = getsum(i);
		if (abs(tsum - sum) < min){
			min = abs(tsum - sum);
			last = i;
		}
		else
			continue;
	}
	return last;
}
int main(){
	int lhs, rhs, mid;
	while (cin >> lhs >> rhs >> mid){
		//lhs = abs(lhs);
		//rhs = abs(rhs);
		//mid = abs(mid);
		int ans = deal2(lhs, rhs, mid);
		cout << ans << endl;
	}
	return 0;
}
#endif