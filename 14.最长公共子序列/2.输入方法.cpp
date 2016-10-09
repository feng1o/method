#if 0
/**http://blog.csdn.net/Hackbuteer1/article/details/6686925
找出两个字符串的最长公共子序列的长度
** author :liuzhiwei
** data   :2011-08-15
**/
#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
int LCSLength(char* str1, char* str2)    //求得两个字符串的最大公共子串长度并输出公共子串  
{
	int i, j, length1, length2;
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
				c[i][j] = c[i - 1][j - 1] + 1;
			else if (c[i - 1][j]>c[i][j - 1])
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = c[i][j - 1];
		}
	}

	//输出公共子串  
	char s[100];
	int len, k;
	len = k = c[length1][length2];
	s[k--] = '\0';
	i = length1, j = length2;
	while (i>0 && j>0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			s[k--] = str1[i - 1];
			i--;
			j--;
		}
		else if (c[i - 1][j]<c[i][j - 1])
			j--;
		else
			i--;
	}
	printf("最长公共子串为：");
	puts(s);

	for (i = 0; i < length1 + 1; i++)    //释放动态申请的二维数组  
		delete[] c[i];
	delete[] c;
	return len;
}

int main(void)
{
	char str1[100], str2[100];
	int length1, length2, len;

	printf("请输入第一个字符串：");
	gets(str1);
	printf("请输入第二个字符串：");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	len = LCSLength(str1, str2);
	printf("最长公共子串的长度为：%d\n", len);
	system("pause");
	return 0;
}
#endif