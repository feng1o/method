/*
tip：
1.递归过程对于某些值，千万不要加入引用，，，比如返回结果加入引用，会使得第二次的里面存在第一次未清空的。。。。*/

#define  _CRT_SECURE_NO_WARNINGS

#include "string"
#include<iostream>
#include<vector>
#include "utility"
#include "ctime"

using namespace std;
//void deal(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ 
void deal(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //切记 结果pvec这里不要用&，否则，找到的后续会有前面的标记，，，，，，，，，，，，，，，，
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return;
	vec[x][y] = 1;//fang访问标记放的位置不一样，会导致结果是几倍的差别.................................................;
	pvec.push_back(make_pair(x, y));//这个的位置很重要，，，放在这里可以用引用了，if里面的不用push了
	if (x == row && y == col)
	{
		//pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}
		//return; //return 并不能影响递归几次，，，实际还是要走完的，比如此题只有一个解，那么应该判定了，只要找到就停止，，，return，每次哦度return
	}
	//pvec.push_back(make_pair(x, y));
	//vec[x][y] = 1; //fang访问标记放的位置不一样，会导致结果是几倍的差别.................................................
	deal(vec, x + 1, y, row, col, pvec);
	deal(vec, x, y+1, row, col, pvec);
	cout << ">>>>>\n";
	pvec.pop_back();
	vec[x][y] = 0;
}

//tip：这个只会保存一个，因此这个是可以用引用的。。。。。。。。。。
bool  deal2(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //此题的方法会减少很多次递归
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return false;
	if (x == row && y == col)
	{
		pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}
		return true; //return 并不能影响递归几次，，，实际还是要走完的，比如此题只有一个解，那么应该判定了，只要找到就停止，，，return，每次哦度reture
	}
	pvec.push_back(make_pair(x, y));
	vec[x][y] = 1;
	bool flag = false;
	if (deal2(vec, x + 1, y, row, col, pvec) || deal2(vec, x, y + 1, row, col, pvec))
		return true;
	else {
		cout << ">>>>>>>>>>>>>>>>>22222222222222\n";
		pvec.pop_back();
		vec[x][y] = 0;
		return false;
	}
}

/*错误版本，，，
1.此处引用，pvec，，
2.vec[x][y] = 1放的位置不对，，
3.压入结果也不应该这样
*/
void deal3(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //1..................
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return;
	if (x == row && y == col)
	{
		pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		return;
	}
	pvec.push_back(make_pair(x, y)); //3/////////////////
	vec[x][y] = 1; //2.................................................
	deal3(vec, x + 1, y, row, col, pvec);
	deal3(vec, x, y + 1, row, col, pvec);
	cout << ">>>>>\n";
	pvec.pop_back();
	vec[x][y] = 0;
}

int main(){
	cin.ignore(10, '\n');
	string str;
	getline(cin, str);
	cout << str << endl;

	int row;
	int col;
	freopen("data.in", "r", stdin);
	while (cin >> row >> col){
		vector<vector<int> >  vec(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				cin >> vec[i][j];
		clock_t start = clock();
		vector<pair<int, int>> pvec;
		deal(vec, 0, 0, row-1, col-1, pvec);
		cout << "值一次，找倒就直接返回的方法......\n";
		//deal2(vec, 0, 0, row-1, col-1, pvec);
		clock_t stop = clock();
		cout << "time = " << stop - start << endl;
		//此处打印的不是正确的，，，，，
	/*	for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}*/
	}
	return 0;
}



