#if 0
/*http://blog.csdn.net/buaa_shang/article/details/11726619
�����ַ�������������Ƿ�ƥ�䣬���磬

"()" yes��

")(" no��

"(abcd(e)" no��

"(a)(b)" yes��

Ҫ������õݹ�д������ʵ�ֲ����Գ���һ��ѭ����䡣*/

#include "iostream"
#include <string>
#include "stack"
using namespace std;

int main(){
	string str;
	while (getline(cin, str, '\n')){
		stack<char> stack;
		int size = str.size();
		for (int i = 0; i < size; ++i)
		{
			if (str[i] == '(' || str[i] == ')')
			{
				if (stack.empty() && str[i] == ')')
				{
					cout << "error \n";
					break;
				}
				else if (str[i] == '(')
					stack.push(str[i]);
				else if (!stack.empty() && str[i] == ')'){
					if (stack.top() != '(')
					{
						cout << "error\n";
						break;
					}
					else
						stack.pop();

				}
			}
			else
				continue;
		}
		if (stack.empty())
		{
			cout << "ok!...\n";
		}
		else
			cout << "error.\n";
	}
	return 0;
}
#endif