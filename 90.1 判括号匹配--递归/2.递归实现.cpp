/*http://blog.csdn.net/buaa_shang/article/details/11726619
�����ַ�������������Ƿ�ƥ�䣬���磬

"()" yes��

")(" no��

"(abcd(e)" no��

"(a)(b)" yes��

Ҫ������õݹ�д������ʵ�ֲ����Գ���һ��ѭ����䡣*/

#include "iostream"
#include "string"
#include "algorithm"
#include "numeric"
#include "functional"
#include "vector"

using namespace std;

bool rf(string str, int pos, int size, int cnt){
	if (pos < size){
		if (str[pos] != '(' && str[pos] != ')')
		{
			if (!rf(str, pos + 1, size, cnt))
				return false;
		}
		if (str[pos] == '(')
		{
			if (!rf(str, pos + 1, size, cnt + 1))  //���ʽ������ֵ
				return false;
		}
		if (str[pos] == ')' && cnt <=0)
		{
			return false;
		}
		if (str[pos] == ')' && cnt > 0)
		{
			if (!rf(str, pos + 1, size, cnt - 1))
				return false;
		}
	}
	else if (cnt == 0){
		return true;
	}
	else
		return false;
}
int main(){
	vector<int> vec{ 1, 23, 4, 256, 62 };
	sort(vec.begin(), vec.end(), greater<int>());
	for (auto it : vec)
	{
		cout << it << endl;
	}
	string str;
	while (getline(cin, str, '\n')){
		int cunt = 0;
		int pos = 0;
		int size = str.size();
		if (rf(str, pos, size, cunt))
			cout << "ok...\n";
		else
			cout << "error...\n";
	}

	return 0;
}