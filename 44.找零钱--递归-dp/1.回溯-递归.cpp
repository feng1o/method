//找出一共有多少种，，，如果找最佳的呢？http://www.cnblogs.com/anderslly/archive/2011/03/06/making-changes.html
#include "iostream"
#include "string"
#include "vector"

using namespace std;
//http://www.cnblogs.com/anderslly/archive/2011/03/06/making-changes.html
/*贪心算法，，，，在零钱数目足够多的时候是最佳的一个解，，，但，零钱不够的时候不是
public static int[] MakeChange(int money, int[] changes)
{
    int[] result = new int[changes.Length];

    for (int i = 0; i < changes.Length; i++)
    {
        result[i] = money / changes[i];
        money = money % changes[i];

        if (money == 0) { break; }
    }

    return result;
}*/
void deal(int* a, int& ans, int n){
	if (n == 0){
		ans += 1;
		ans %= 1000000007;
		return;
	}
	if (n < 0)
		return;
	//if (n > 0){ //非递归，找最少钱数，找零
	//	if (n / *a > 0)
	//		deal(a, ans, n - a[0]);
	//	else
	//		deal(a + 1, ans, n);
	//}
	if( n > 0){  //这个回溯过程会出现大量重复次数，，不对，他认为零钱出现是有顺序的，1,1，5；5,1,1被认为不同
	deal(a, ans, n-a[0]);
	deal(a, ans, n-a[1]);
	deal(a, ans, n-a[2]);
	deal(a, ans, n-a[3]);
	}
}
//递归求一共有多少种找零钱方法，，基本超时，无法完成
void deal2(int* a, int& ans, int n, int last){
	if (n == 0){
		ans += 1;
		ans %= 1000000007;
		return;
	}
	if (n < 0)
		return;
	if (n > 0){  //
		if (last >= a[0]) //保证零钱是按照从大到小的，不会先出现，5,1；又出现个1,5，后面只有1，1,1,1,1,1,1,1,1
		deal2(a, ans, n - a[0], a[0]);
		if (last >= a[1])
		deal2(a, ans, n - a[1], a[1]);
		if (last >= a[2])
		deal2(a, ans, n - a[2], a[2]);
		if (last >= a[3])
		deal2(a, ans, n - a[3], a[3]);
	}
}
int deal3(int *a, int &ans, int n, int cur){ //递归的方法，，但是这个分析思路和前面的 切入点不同
	int next;
	switch (cur){
	case 25:
		next = 10;
		break;
	case 10:
		next = 5;
		break;
	case 5:
		next = 1;
		break;
	case 1:
		return 1;
		// next = 1;

	}
	int cnt = 0;
	for (int i = 0; i*cur <= n; ++i){
		ans += 1;
		cnt += deal3(a, ans, n - i*cur, next);
	}
	return cnt;
}


int dealdp2(int *a, int N, int sum){
	if (a == nullptr || N < 1 || sum < 0) return 0;
	vector<vector<int>> vec(N+1, vector<int>(sum + 1, 0));
	for (int i = 0; i <= N; ++i)
		vec[i][0] = 1;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= sum; ++j){
			for (int k = 0; k <= j/a[i-1]; ++k){
				//vec[i][j] += vec[i - 1][j - k * a[i]];
				vec[i][j] += vec[i - 1][j - k * a[i-1]];
			}
		}
	}
	return vec[N][sum];
}

int dealdp(int *a, int N, int sum){ //理解本质。。。。。实际从dealdp2哪里加 背包问题总结出的
	if (a == nullptr || N < 1 || sum < 0) return 0;
	vector<int> vec(sum+1, 0);
	vec[0] = 1;
	for (int i = 1; i <= N; ++i){
		for (int j = a[i-1] ; j <= sum; ++j){
			//vec[j] += vec[j - a[i - 1]] % 1000000007;
			vec[j] = (vec[j] + vec[j - a[i - 1]]) % 1000000007;
			}
		}
	return vec[sum];
}

int countWays(int n) {
	// write code here
	int change[] = {1,5,10,25 };
	int ans = 0;
	//deal(change, ans, n);
	//deal2(change, ans, n, n);
	//deal3(change, ans, n, 25);
	//return ans; 
	return dealdp(change, 4, n);
}
int main(){
	//cout << 
	cout << countWays(7) << endl;
	cout << countWays(3) <<endl;
	cout << countWays(5) <<endl;
	cout << countWays(1000) << endl; //1000就要很久了，，10000这样基本出不来了
	return 0;
}