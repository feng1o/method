#if 0
/*小萌的副本生涯
题目描述：
在主城站街很久之后，小萌决定不能就这样的浪费时间虚度青春，他打算去打副本。
这次的副本只有一个BOSS，而且BOSS是不需要击杀的，只需要和它比智力…….
BOSS会列出一正整数的序列，由小萌先开始，然后两个人轮流从序列的任意一端取数，取得的数累加到积分里，当所有数都取完，游戏结束。
假设小萌和BOSS都很聪明，两个人取数的方法都是最优策略，问最后两人得分各是多少。
输入
第一行：一个正整数N（2 ≤ N ≤ 100），表示序列中正整数的个数。
第二行至末尾：用空格隔开的N个正整数（1 ≤ a[i] ≤ 200）
输出
只有一行，用空格隔开的两个数，小萌的得分和BOSS的得分。

样例输入
6
4 7 2 9 5 2
样例输出
18 11
*/

#include <iostream>

using namespace std;

int **dp1, **dp2;
int secondMax(int data[], int left, int right);

int firstMax(int data[], int left, int right){
	if (left == right)	return data[left];
	if (dp1[left][right] != -1)	return	dp1[left][right];
	int getLeft = data[left] + secondMax(data, left + 1, right);
	int getRight = data[right] + secondMax(data, left, right - 1);
	if (getLeft > getRight)
		dp1[left][right] = getLeft;
	else
		dp1[left][right] = getRight;
	return dp1[left][right];
}

int secondMax(int data[], int left, int right){
	if (left == right)	return 0;
	if (dp2[left][right] != -1)	return	dp2[left][right];
	int getLeft = firstMax(data, left + 1, right);
	int getRight = firstMax(data, left, right - 1);
	if (getLeft < getRight)
		dp2[left][right] = getLeft;
	else
		dp2[left][right] = getRight;
	return dp2[left][right];
}

int main(){
	int n, tmp;
	scanf("%d", &n);
	int *data = new int[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		data[i] = tmp;
	}
	int first, second;
	int sum = 0;
	dp1 = new int*[n];
	for (int i = 0; i < n; i++){
		dp1[i] = new int[n];
	}
	dp2 = new int*[n];
	for (int i = 0; i < n; i++){
		dp2[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dp1[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	first = firstMax(data, 0, n - 1);
	for (int i = 0; i < n; i++)
		sum += data[i];
	second = sum - first;
	for (int i = 0; i < n; i++){
		delete[] dp1[i];
		delete[] dp2[i];
	}
	delete[] dp1;
	delete[] dp2;
	printf("%d %d\n", first, second);
	return 0;
}
#endif