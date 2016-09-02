#if 01
#include <stdio.h>  
#include "iostream"
#include "vector"
using namespace std;
#define M   10  
#define N   10  
int maze[M][N] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 1, 0, 0, 0, 1, 1, 0, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int StartX = 1, StartY = 1;
int EndX = 8, EndY = 8;
void print();
void travel(int, int);
void travel2(int i, int j, int cnt, int& n);
void travel3(int i, int j, int cnt, int& n);
int main()
{
	print();
	//travel(StartX, StartY);
	int n = INT_MAX;
	int cnt = 0;
	//travel2(StartX, StartY, cnt, n);
	travel3(StartX, StartY, cnt, n);
	cout << "nnnn...=" << n << endl;
	return 0;
}
void print()
{
	printf("路径.........^_^\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == 1)
				printf("▆");
			else if (maze[i][j] == 0)
				printf("  ");
			else if (maze[i][j] == 2)
				printf("●");
		}
		printf("\n");
	}
}
void travel(int i, int j)
{
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		return;
	}
	if (maze[i - 1][j] == 0)
		travel(i - 1, j);	
	if (maze[i][j - 1] == 0)
		travel(i, j - 1);	
	if (maze[i + 1][j] == 0)
		travel(i + 1, j);
	if (maze[i][j + 1] == 0)
		travel(i, j + 1);
	maze[i][j] = 0;
}

void travel2(int i, int j, int cnt, int& n){
	if (i > EndX || i <0 || j > EndY || j < 0)
		return;
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		if (cnt < n) n = cnt;
		return; //一旦走出去就结束了,,,,,,,,不一定是最好的 方法。。找最好的必须走完
		//因为此处有标记，所以，return了，不会清楚走过标记就 只能返回一个结果
	}
	if (maze[i + 1][j] == 0)
		travel2(i + 1, j, cnt + 1, n);
	if (maze[i - 1][j] == 0)
		travel2(i - 1, j, cnt + 1, n);
	if (maze[i][j + 1] == 0)
		travel2(i, j + 1, cnt + 1, n);
	if (maze[i][j - 1] == 0)
		travel2(i, j - 1, cnt + 1, n);
	maze[i][j] = 0; //恢复  这样如果灭走通的路径，会被清楚，走通了才会保存 
	//有无不影响最终通过的路径，，，，因为cnt会自动回滚的，，

}

void travel3(int i, int j, int cnt, int& n){
	if (i > EndX || i <0 || j > EndY || j < 0 || maze[i][j] != 0)//应该更浪费时间
		return;
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		if (cnt < n) n = cnt;
		cout << "...n====" << cnt<< endl;
		return;    //如果找最小的，，这个return不能有，会找到就结束了，，，，比如迷宫找最快出去几步能完成           //控制着结果显示几个。。。。
		//这个return导致只有一个是因为，return了，没办法调用最后的恢复当前点为访问否的问题，导致肯定不会走到终点了，，，
		/*void recur(int n){  //比如这个，不管有没有return都是一样的，，没区别，因为没有访问标记
			static int i = 0;
			if (n < 1)
				return;
			if (n == 1)
			{
				cout << "n=" << n << endl;
				return;
			}
			cout << "nn===" << n << endl;
			recur(n - 1);
			recur(n - 2);
			//cout << "nn===" << n << endl;
			++i;
			cout << "iiiiiiiiii = " << i << endl;
		}*/
		
	}

	//if (maze[i][j + 1] == 0)
		travel3(i, j + 1, cnt + 1, n);
	//if (maze[i][j - 1] == 0)
		travel3(i, j - 1, cnt + 1, n);
		//if (maze[i + 1][j] == 0)  //也是ok的.........................
		travel3(i + 1, j, cnt + 1, n);
		//if (maze[i - 1][j] == 0)
		travel3(i - 1, j, cnt + 1, n);
	//maze[i][j] = 0; //恢复  这样如果灭走通的路径，会被清楚，走通了才会保存 
		//没有这个也是走一次就结束了，，，如果找通路是否通，应该加上返回判定，如果走的是对的，就不管，没走通的时候才需要恢复的话，函数比较返回一个bool，，，sto 66题就这一个思路
	//有无不影响最终通过的路径，，，，因为cnt会自动回滚的，，

}

//加入只需要判定走一次是否能通，，或者所走的路径是不是以此为0 1 1 0 1  1这样的顺序，，sto 66题，
//比较树结构中的某条路径和等于n，路径判定 str="011011"
bool travel4(int i, int j, int cnt, int& n, string str, int index, vector<vector<int>> visited){
	if (i > EndX || i <0 || j > EndY || j < 0 || visited[i][j] !=0 || maze[i][j] != str[index])//应该更浪费时间
		return false;
	visited[i][j] = 1;  //走过标记
	if (str[index]= '\0'){
		return true;  //找到一条是的，，就应该停止所有的了
	}
	bool flag = false;
	//if (maze[i][j + 1] == 0)
	flag = travel4(i, j + 1, cnt, n ,str, index + 1, visited) || 
		travel4(i, j - 1, cnt,n, str, index + 1, visited) ||
		travel4(i + 1, j, cnt,n, str, index + 1, visited) ||
		travel4(i - 1, j, cnt, n, str, index + 1, visited);
	if (!flag)
	{
		visited[i][j] = 0;  //只有走不通 ，不对的时候才回复，，因为不需要走通多次，，，sto 66
	}
	return flag;
}
//比如在，找这个矩阵里面有没有一个string "aadkgnsd"能走通，并是这个，，，此时就应该加入返回值判定了
//比如，全排列递归问题，就应该注意
#endif