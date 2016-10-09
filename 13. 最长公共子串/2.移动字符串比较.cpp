/**
�ҳ������ַ���������������Ӵ��ĳ���
** author :liuzhiwei
** data   :2011-08-16
**/
#include "stdio.h"  
#include "string.h"  
#include "stdlib.h"  

int longest_common_substring(char *str1, char *str2)
{
	int i, len1, len2, len, s1_start, s2_start, idx, curmax, max;
	len1 = strlen(str1);
	len2 = strlen(str2);
	len = len1 + len2;
	max = 0;
	for (i = 0; i < len; i++)
	{
		s1_start = s2_start = 0;
		if (i < len1)
			s1_start = len1 - i;    //ÿ�ο�ʼƥ�����ʼλ��  
		else
			s2_start = i - len1;
		curmax = 0;
		for (idx = 0; (s1_start + idx < len1) && (s2_start + idx < len2); idx++)
		{
			if (str1[s1_start + idx] == str2[s2_start + idx])
				curmax++;
			else     //ֻҪ��һ������ȣ���˵����ȵĹ����ַ����ˣ��������ˣ�Ҫ����curmax��max�е����ֵ������curmax����Ϊ0  
			{
				max = curmax > max ? curmax : max;
				curmax = 0;
			}
		}
		max = curmax > max ? curmax : max;
	}
	return max;
}
int main(void)
{
	char str1[1000], str2[1000];
	printf("�������һ���ַ�����");
	gets(str1);
	printf("������ڶ����ַ�����");
	gets(str2);
	int len = longest_common_substring(str1, str2);
	printf("����������Ӵ��ĳ���Ϊ��%d\n", len);
	system("pause");
	return 0;
}