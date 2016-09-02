/*˼�룺
  �ӵ�һ���㿪ʼ��ѹ��ջ��Ȼ��ȡջ��Ԫ�أ���ʼ���������п��ܵķ�������ȥ��
  �����һ�������յ㣬��ֹͣ��
  �����һ������ �յ㣬���ߣ��Ͱѵ�ǰ��ѹ��ջ��ͬʱ��¼��ǰ������߹��˼���������Ϊ�Ǵ�0-3��4�����������ж��ģ������Ϳ����ҵ��´η�������ʱ��Ӧ�����ĸ�����+1�����µķ���
  ����ҵ�����ͬ�ˣ���ʱӦ�÷��ؿ���һ���������ߵģ�ȥջ����Ԫ�أ���
  �ص㣺
  1.��֤��¼���һ���ߵķ���
  2.��¼�߹��ĵ㣬�˷���ֻ�ܱ�֤��ͨһ������������ô�죿
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
		while (count < DIRECT){ //�����ߵ�4�����򣬣�����
			int nx = i + direction[count][0];  //��һ�����򡣡���������
			int ny = j + direction[count][1];  //��ʼ��jЭ��i��δ��������
			if (nx == EndX && ny == EndY && maze[nx][ny] == 0)
			{
				maze[nx][ny] = 2;
				element.x = i;
				element.y = j;
				stack.push(element);  //ѹ��������Ϊ�˰�������ѹ��
				element.x = nx;
				element.y = ny; 
				stack.push(element); //����һ��ѹ��
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
				element.x = i; //��¼��ǰ���߹��������ߵ�count������
				element.y = j;  //�˴�����nx��nyԭ��Ҫ��⣬���Ǵ�i,j���Ե�nx,ny��
				 //�ߵķ�����count����¼�£���ô��һ����Ӧ�ÿ�ʼ�ӣ�nx,ny�����ߣ�������nx��ny����Ŀ�ľͽ��������Բ���Ҫ����ջ
				element.direction = count;
				stack.push(element);
				i = nx; //nx��nyӦ������һ��Ҫ�ߵĵ㣬�����������ͨ��nx��ny�ͻ���ջ��
				j = ny;
				count = -1; //nx��ny���µĵ㣬Ϊ�߹������Դ�-1�������0��ʼ�ߣ����ⲽҲ�ͱ�֤�������������������������
				
			}
			count++;
		}
	}
}
void print()
{
	printf("·��.........^_^\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == 1)
				printf("�}");
			else if (maze[i][j] == 0)
				printf("  ");
			else if (maze[i][j] == 2)
				printf("��");
		}
		printf("\n");
	}
}

#endif