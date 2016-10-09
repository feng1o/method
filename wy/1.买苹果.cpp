#if 0

//http://blog.tk-xiong.com/archives/1027
/*
[编程题|20分] 买苹果
时间限制：1秒
空间限制：32768K

题目描述：
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。
如果不能购买恰好n个苹果，小易将不会购买。

输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果

输出描述：
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

输入样例：
20

输出样例：
3
*/
#include "iostream"
#include "vector"

using namespace std;

int deal(int n, int cnt){
	
	if (n == 0)
		return cnt;
	if (n < 0)
		return -1;
	int tmp = 0;
	//cout << n << endl;
	tmp = deal(n - 8, cnt + 1);
	//cout << "     " << n << endl;
	if (tmp > 0)
		return  tmp;
	return deal(n - 6, cnt + 1);
	//cout <<">>"<< n << endl;

}
int Ans[101];

//预处理
//tip：比如一个数字N,可以用a1<a2，，a1，a2整数个他们组合这个N，那么怎么办？
void Begin()
{
	//处理所有的值
	for (int i = 1; i <= 100; i++)
	{
		Ans[i] = 32768;
		//根据6个苹果装的 - 判断8个苹果装的数量
		for (int j6 = 0; j6 <= i / 6; j6++)  //这一步理解。。。。。。。
		{
			int others = i - j6 * 6;
			if (others % 8 == 0)
			{
				int all = j6 + others / 8;
				if (Ans[i] > all)
				{
					Ans[i] = all;
				}
			}
		}
		if (Ans[i] == 32768)
		{
			Ans[i] = -1;
		}
	}
}
int main(){
	Begin();
	int n; 
	while (cin >> n){
		cout << "...." << Ans[n] << endl;
		if (n % 2 == 1)
		{
			cout << -1 << endl;
			continue;
		}
		cout << deal(n, 0) << endl;
	}
	return 0;
}
#endif