//http://blog.csdn.net/hackbuteer1/article/details/7462447

#include<iostream>  
using namespace std;
#include<assert.h>  

//��[nBegin,nEnd)�������Ƿ����ַ����±�ΪpEnd���ַ����  
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
		static int num = 1;  //�ֲ���̬����������ͳ��ȫ���еĸ���  
		printf("��%d������\t%s\n", num++, pStr);
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; pCh++)   //��pBegin�����ֱ�������������ֽ������ܵõ��µ�����     
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