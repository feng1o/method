

#include"stdio.h"
#include"stdlib.h"
#include"iostream"
#include"vector"
#define N  4

using namespace std;
static char vec[N][N];
static int count = 0;

void init()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			vec[i][j] = '.';
		}
	}
}

void display()
{
	int i = 0;
	int j = 1;

	for (i = 0; i < N ; i++)
	{
		for (j = 0; j < N ; j++)
		{
			printf("%c", vec[i][j]);
		}

		printf("\n");
	}
}



bool check( int x, int y){
	for (int i = 0; i < N; ++i)
		if (vec[x][i] == '1')
			return false;
	int upx = x;
	int upy = y;
	while (--upx >= 0)
		if (vec[upx][upy] == '1')
			return false;

	int lslopx = x;
	int lslopy = y;
	while (--lslopx >= 0 && --lslopy >= 0)
		if (vec[lslopx][lslopy] == '1')
			return false;

	int rslopx = x;
	int rslopy = y;
	while (--rslopx >= 0 && ++rslopy < N)
		if (vec[rslopx][rslopy] == '1')
			return false;
	return true;
}

void deal( int& cnt, int row, int n){
	if (row == n){
		++cnt;
		display();
		cout << ">>>>>>>>>>>\\n";
		return;
	}
	for (int col = 0; col<n; ++col){
		if (check( row, col)){
			vec[row][col] = '1';
			//display();
			deal( cnt, row + 1, n);
			vec[row][col] = '.';
		}
	}
}
void print(vector<vector<int>> arr){
	for (auto it : arr)
		for (auto it2 :it)
		cout << "..." << it2 << endl;
}
void pp(vector<vector<int>> &arr){
	print(arr);
}
int main()
{
	vector<vector<int>> arr(2, vector<int>(2,2));
	print(arr);
		pp(arr);
	//init();
	//display();
	//int cnt = 0;
	//deal( cnt, 0, N);
	//display();
	//cout << cnt << endl;
	return 0;
}


