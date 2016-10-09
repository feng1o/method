/*
TIP:
1.打印结果，最后可能没有空格。。。。。。。。。。。。。。tip，空格注意了
2.回溯过程，如果想让改变的数据最后完成还在，，，那么只能return，找到后不要继续走了，，，return，，，
3.记住引用个，vector,,,,,http://www.nowcoder.com/practice/78a1a4ebe8a34c93aac006c44f6bf8a1?tpId=37&tqId=21267&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
4.注意const的应用*/
#define _CRT_SECURE_NO_WARNINGS
#include "cstdlib"
#include "string"
#include "iostream"
#include "vector"

using namespace std;
bool check(const vector<vector<int> > vec, int n, int key);
void print(const vector<vector<int> > vec);
void DFS(vector<vector<int> > &vec, int n){ // 3.记住引用个，vector,,,,, 
	//vec[0][0] = 5;
	if (n>80)
	{
		print(vec);
		return;
	}
	int row = n / 9;
	int col = n % 9;
	if (vec[row][col] != 0)
		DFS(vec, n + 1);
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				DFS(vec, n + 1);
				vec[row][col] = 0;               //这样，没return判定，一直会到这个递归恢复，所以最后打印出来的是原值一样的
			}
		}
	}
}

/*比较dfs3，dfs2,,,,
1.dfs2如果在两次if判定中有一次漏掉判定就会错。。。
2.dfs2的方法最可靠的是在成功n=81的时候打印，但是这样还是所有有结果，，
3.如果找打一种就停止，必须是return，而且每个回溯地方都要用，，，，，
4.注意，用全局标志更简单*/
bool DFS2(vector<vector<int> > &vec, int n){ // 3.记住引用个，vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		if (DFS2(vec, n + 1) == true)
		{
			return true;
		}
		else                //没用这个，会让下面的else，结构破坏，，，if最好加大括号。。。。
			return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				if (DFS2(vec, n + 1))
					return true;
				else
					vec[row][col] = 0;    //这样，没return判定，一直会到这个递归恢复，所以最后打印出来的是原值一样的
			}
		}
	}
	return false;
}
//错误在if，else结构，，，，
bool DFS2_1(vector<vector<int> > &vec, int n){ // 3.记住引用个，vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		if (DFS2_1(vec, n + 1) == true)//错误在if，else结构，，，，
		{
			return true;
		}  //这里判定方法没错，不一定需要/*flag =DFS2(vec, n + 1); 但是，if，else结构被破坏了，，
	//else
	//return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
		else{
			for (int key = 1; key < 10; ++key)
			{
				if (check(vec, n, key) == true){
					vec[row][col] = key;
					if (DFS2_1(vec, n + 1))
						return true;
					else
						vec[row][col] = 0;               //这样，没return判定，一直会到这个递归恢复，所以最后打印出来的是原值一样的
				}
			}
		}
		return false;
}
//错误在：有回溯过程没判定返回值，，，，，，，，，，，，
bool DFS2_2(vector<vector<int> > &vec, int n){ // 3.记住引用个，vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		DFS2_2(vec, n + 1); //...error在这里，，，准备上 一次结束，实际上这个地方返回，会到后面的false，本是true
	/*if (DFS2_2(vec, n + 1) == true)//错误在if，else结构，，，，
	{
	return true;
	}  //这里判定方法没错，不一定需要flag =DFS2(vec, n + 1); 但是，if，else结构被破坏了，，*/
	//else
	//return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				if (DFS2_2(vec, n + 1))
					return true;
				else
					vec[row][col] = 0;               //这样，没return判定，一直会到这个递归恢复，所以最后打印出来的是原值一样的
			}
		}
	}
	return false;
}
bool sign;


/*比较dfs3，dfs2,,,,
1.dfs2如果在两次if判定中有一次漏掉判定就会错。。。
2.dfs2的方法最可靠的是在成功n=81的时候打印，但是这样还是所有有结果，，
3.如果找打一种就停止，必须是return，而且每个回溯地方都要用，，，，，
4.注意，用全局标志更简单*/
int DFS3(vector<vector<int>>& num, int n)
{
	/* 所有的都符合，退出搜索,n代表格子数，共81个格子，0~80 */
	if (n > 80){
		sign = true;
		return 1;
	}

	if (num[n / 9][n % 9] != 0)
		DFS3(num, n + 1);
	else{
		/* 否则对当前位一次填入1~9进行测试 */
		for (int i = 1; i <= 9; i++){
			if (check(num, n, i)){
				num[n / 9][n % 9] = i;
				/* 继续搜索，后续位也填1~9测试，直到最后一位，通过的话置true */
				DFS3(num, n + 1);
				/* 返回时如果构造成功，则直接退出 */
				if (sign)
					return 0;
				/* 如果构造不成功，还原当前位 */
				num[n / 9][n % 9] = 0;
			}

		}
	}
	return 0;
}
int main(){
	freopen("data.in", "r", stdin);
	vector<vector<int> > vec(9, vector<int>(9, 0));
	for (int i = 0; i < 81; ++i)
	{
		cin >> vec[i / 9][i % 9];
	}

	print(vec);
	//cout << "ch-" << check(vec, 0, 5) << endl;
	DFS2(vec, 0);
	cout << "....\n\n";
	print(vec);  //tip...............tip...............在这个地方打印，那么必须是的回溯找到后不要恢复状态继续走下去，否则只能去判定出打印了，，，，，
	return 0;
}

bool check(const vector<vector<int> > vec, int n, int key){
	int x = n / 9;
	int y = n % 9;
	for (int i = 0; i < 9; ++i)
		if (vec[x][i] == key || vec[i][y] == key)
			return false;
	int ix = n / 9 / 3 * 3;
	int iy = n % 9 / 3 * 3;
	for (int i = ix; i < ix + 3; ++i)
	{
		for (int j = iy; j < iy + 3; ++j)
		{
			if (vec[i][j] == key)
				return false;
		}
	}
	return true;
}

void print(const vector<vector<int> > vec){
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			//1.打印结果，最后可能没有空格。。。。。。。。。。。。。。tip，空格注意了
			//cout << vec[i][j] << " ";//
			cout << vec[i][j] << " ";
		}
		cout << vec[i][8]; //.....................
		cout << endl;
	}
}