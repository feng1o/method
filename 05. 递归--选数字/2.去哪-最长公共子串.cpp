//http://blog.csdn.net/hackbuteer1/article/details/6686931
#define  _CRT_SECURE_NO_WARNINGS

#if 0
#include "climits"
#include "vector"
#include "iostream"
#include "cstdio"    
#include "cstdlib"  
#include "string"
#include "algorithm"

using namespace std;
int longestCommonSubstring(char *str1, int len1, char *str2, int len2)
{
	int i, j, k, max, x, y;
	//len1 = strlen(str1);
	//len2 = strlen(str2);
	int **c = new int*[len1 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i] = new int[len2 + 1];
	for (i = 0; i < len1 + 1; i++)
		c[i][0] = 0;
	for (j = 0; j < len2 + 1; j++)
		c[0][j] = 0;
	max = -1;
	for (i = 1; i < len1 + 1; i++)
	{
		for (j = 1; j < len2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = 0;
			if (c[i][j]>max)
			{
				max = c[i][j];
				x = i;
				y = j;
			}
		}
	}

	char s[1000];
	k = max;
	i = x - 1, j = y - 1;
	s[k--] = '\0';
	while (i >= 0 && j >= 0)
	{
		if (str1[i] == str2[j])
		{
			s[k--] = str1[i];
			i--;
			j--;
		}
		else
			break;
	}
	if (s[0] == '\0')
		cout << "result=" << endl;
	else
		cout << "result=" << s << endl;
	for (i = 0; i < len1 + 1; i++)
		delete[] c[i];
	delete[] c;
	return max;
}
int main(void)
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		for (int i = 0; i < len1; ++i)
		{
			if (isupper(str1[i])){
				str1[i] = tolower(str1[i]);
			}
		}
		int len2 = str2.size();
		for (int i = 0; i < len2; ++i)
		{
			if (isupper(str2[i]))
				str2[i] = tolower(str2[i]);
		}
		//cout << str1 <<" " << str2 << endl;
		longestCommonSubstring(const_cast<char*>(str1.c_str()), len1, const_cast<char*>(str2.c_str()), len2);
	}
	return 0;
}
#endif
