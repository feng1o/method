//http://blog.csdn.net/hackbuteer1/article/details/7462447

#include<iostream>  
using namespace std;
#include<assert.h>  

//在[nBegin,nEnd)区间中是否有字符与下标为pEnd的字符相等  
bool IsSwap(char* pBegin, char* pEnd)
{
	char *p;
	for (p = pBegin; p < pEnd; p++)
	{
		if (*p == *pEnd)
			return false;
	}
	return true;
}
void Permutation(char* pStr, char *pBegin)
{
	assert(pStr);

	if (*pBegin == '\0')
	{
		static int num = 1;  //局部静态变量，用来统计全排列的个数  
		printf("第%d个排列\t%s\n", num++, pStr);
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; pCh++)   //第pBegin个数分别与它后面的数字交换就能得到新的排列     
		{
			if (IsSwap(pBegin, pCh))
			{
				swap(*pBegin, *pCh);
				Permutation(pStr, pBegin + 1);
				swap(*pBegin, *pCh);
			}
		}
	}
}

int main(void)
{
	char str[] = "baa";
	Permutation(str, str);
	return 0;
}