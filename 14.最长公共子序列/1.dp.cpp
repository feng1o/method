//http://blog.csdn.net/Hackbuteer1/article/details/6686925

/**
找出两个字符串的最长公共子序列的长度
** author :liuzhiwei
** data   :2011-08-15
**/
#define  _CRT_SECURE_NO_WARNINGS
#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
#include "vector"
#include "iostream"
using namespace std;
int LCSLength(char* str1, char* str2, int **b){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i, j, len;
	vector<vector<int>> vvec(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 0; i <= len1; ++i)
	{
		vvec[0][i] = 0;
		vvec[i][0] = 0;
	}
	for (i = 1; i <= len1;++i)
	{
		for (j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1]){
				vvec[i][j] = vvec[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else{
				if (vvec[i][j-1] > vvec[i-1][j]){
					vvec[i][j] = vvec[i][j - 1];
					b[i][j] = -1;
				}
				else{
					vvec[i][j] = vvec[i - 1][j];
					b[i][j] = 1;
				}
			}
		}
	}
	return vvec[len1][len2];
}
int LCSLength2(char* str1, char* str2, int **b)
{
	int i, j, length1, length2, len;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//双指针的方法申请动态二维数组  
	int **c = new int*[length1 + 1];      //共有length1+1行  
	for (i = 0; i < length1 + 1; i++)
		c[i] = new int[length2 + 1];      //共有length2+1列  

	for (i = 0; i < length1 + 1; i++)
		c[i][0] = 0;        //第0列都初始化为0  
	for (j = 0; j < length2 + 1; j++)
		c[0][j] = 0;        //第0行都初始化为0  

	for (i = 1; i < length1 + 1; i++)
	{
		for (j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])   //由于c[][]的0行0列没有使用，c[][]的第i行元素对应str1的第i-1个元素  
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;          //输出公共子串时的搜索方向  
			}
			else if (c[i - 1][j]>c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
	/*
	for(i= 0; i < length1+1; i++)
	{
	for(j = 0; j < length2+1; j++)
	printf("%d ",c[i][j]);
	printf("\n");
	}
	*/
	len = c[length1][length2];
	for (i = 0; i < length1 + 1; i++)    //释放动态申请的二维数组  
		delete[] c[i];
	delete[] c;
	return len;
}

//打印的方法.............
void PrintLCS(int **b, char *str1, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, str1, i - 1, j - 1);   //从后面开始递归，所以要先递归到子串的前面，然后从前往后开始输出子串  
		printf("%c", str1[i - 1]);        //c[][]的第i行元素对应str1的第i-1个元素  
	}
	else if (b[i][j] == 1)
		PrintLCS(b, str1, i - 1, j);
	else
		PrintLCS(b, str1, i, j - 1);
}
bool deal(int x){
	int tmp = 0;
	int xx = x;
	while (x){
		int n = x % 10;
		tmp = tmp * 10 + n;
		x /= 10;
	}
	return tmp == xx;
}
int main(void)
{
	cout << abs(-2) << endl;
	for (int i = 0; i < 10; ++i)
	{
		int x;
		cin >> x;
		cout << deal(x) << endl;
	}
	char str1[100], str2[100];
	int i, length1, length2, len;
	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	//双指针的方法申请动态二维数组  
	int **b = new int*[length1 + 1];
	for (i = 0; i < length1 + 1; i++)
		b[i] = new int[length2 + 1];
	len = LCSLength(str1, str2, b);
	printf("最长公共子序列的长度为：%d\n", len);
	printf("最长公共子序列为：");
	PrintLCS(b, str1, length1, length2);
	printf("\n");
	for (i = 0; i < length1 + 1; i++)    //释放动态申请的二维数组  
		delete[] b[i];
	delete[] b;
	system("pause");
	return 0;
}