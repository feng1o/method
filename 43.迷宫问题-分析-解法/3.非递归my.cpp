/*思想：
  从第一个点开始，压入栈，然后取栈顶元素，开始找他的所有可能的方向，走下去：
  如果下一步到达终点，就停止，
  如果下一步不是 终点，可走，就把当前点压入栈，同时记录当前这个点走过了几个方向，因为是从0-3的4个方向依次判定的，这样就可以找到下次返回来的时候应该走哪个方向，+1就是新的方向；
  如果找到死胡同了，此时应该返回看上一步从哪里走的，去栈顶拿元素，，
  重点：
  1.保证记录最后一步走的方向，
  2.记录走过的点，此方法只能保证走通一条，，多条怎么办？
  */

#if 0
#include <stdio.h>  
#include "iostream"
#include "stack"
#include "vector"
#include "queue"
using namespace std;
#define M   10  
#define N   10  
int maze[M][N] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 1, 0, 0, 0, 1, 1, 0, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
enum { DIRECT = 4, INC = 2 };
typedef struct
{
	int x;
	int y;
	int direction;
}ElemType;
int direction[DIRECT][INC] = {
	0, 1,
	1, 0,
	0, -1,
	-1, 0,
};
int StartX = 1, StartY = 1;
int EndX = 8, EndY = 8;
void print();
void deal();
int main()
{
	//cout << direction[2][1] << endl;
	print(); 
	deal();
	return 0;
}
void deal(){
	ElemType element;
	element.x = StartX;
	element.y = StartY;
	element.direction = -1;
	stack<ElemType> stack;
	stack.push(element);
	while (!stack.empty()){
		cout << ".....size==" << stack.size() << endl;;
		element = stack.top();
		int count = element.direction + 1;
		int i = element.x;
		int j = element.y;
		//print();
		stack.pop();
		while (count < DIRECT){ //可能走的4个方向，，，，
			int nx = i + direction[count][0];  //下一个方向。。。。。。
			int ny = j + direction[count][1];  //开始吧j协程i，未发现问题
			if (nx == EndX && ny == EndY && maze[nx][ny] == 0)
			{
				maze[nx][ny] = 2;
				element.x = i;
				element.y = j;
				stack.push(element);  //压入两次是为了把这个结果压缩
				element.x = nx;
				element.y = ny; 
				stack.push(element); //最后的一个压入
				while (!stack.empty())
				{
					element = stack.top();
					printf("(%d,%d)->", element.x, element.y);
					stack.pop();
				}
				printf("\n");
				print();
				return;
			}
			if (maze[nx][ny]==0)
			{
				maze[nx][ny] = 2;
				element.x = i; //记录当前点走过，并且走到count方向了
				element.y = j;  //此处不是nx，ny原因要理解，就是从i,j可以到nx,ny，
				 //走的方向是count，记录下，那么下一步就应该开始从，nx,ny往下走，最终是nx，ny等于目的就结束，所以不需要他入栈
				element.direction = count;
				stack.push(element);
				i = nx; //nx，ny应该是下一次要走的点，，，如果能走通，nx，ny就会入栈了
				j = ny;
				count = -1; //nx，ny是新的点，为走过，所以从-1，下面从0开始走，，这步也就保证了类似深度优先搜索，，，，
				
			}
			count++;
		}
	}
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

#endif