#if 0
/**http://blog.csdn.net/Hackbuteer1/article/details/6686925
�ҳ������ַ���������������еĳ���
** author :liuzhiwei
** data   :2011-08-15
**/
#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  
int LCSLength(char* str1, char* str2)    //��������ַ�������󹫹��Ӵ����Ȳ���������Ӵ�  
{
	int i, j, length1, length2;
	length1 = strlen(str1);
	length2 = strlen(str2);

	//˫ָ��ķ������붯̬��ά����  
	int **c = new int*[length1 + 1];      //����length1+1��  
	for (i = 0; i < length1 + 1; i++)
		c[i] = new int[length2 + 1];      //����length2+1��  

	for (i = 0; i < length1 + 1; i++)
		c[i][0] = 0;        //��0�ж���ʼ��Ϊ0  
	for (j = 0; j < length2 + 1; j++)
		c[0][j] = 0;        //��0�ж���ʼ��Ϊ0  

	for (i = 1; i < length1 + 1; i++)
	{
		for (j = 1; j < length2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])   //����c[][]��0��0��û��ʹ�ã�c[][]�ĵ�i��Ԫ�ض�Ӧstr1�ĵ�i-1��Ԫ��  
				c[i][j] = c[i - 1][j - 1] + 1;
			else if (c[i - 1][j]>c[i][j - 1])
				c[i][j] = c[i - 1][j];
			else
				c[i][j] = c[i][j - 1];
		}
	}

	//��������Ӵ�  
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
	printf("������Ӵ�Ϊ��");
	puts(s);

	for (i = 0; i < length1 + 1; i++)    //�ͷŶ�̬����Ķ�ά����  
		delete[] c[i];
	delete[] c;
	return len;
}

int main(void)
{
	char str1[100], str2[100];
	int length1, length2, len;

	printf("�������һ���ַ�����");
	gets(str1);
	printf("������ڶ����ַ�����");
	gets(str2);
	length1 = strlen(str1);
	length2 = strlen(str2);
	len = LCSLength(str1, str2);
	printf("������Ӵ��ĳ���Ϊ��%d\n", len);
	system("pause");
	return 0;
}
#endif