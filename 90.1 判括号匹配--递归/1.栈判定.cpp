#if 0
/*http://blog.csdn.net/buaa_shang/article/details/11726619
给定字符串，输出括号是否匹配，例如，

"()" yes；

")(" no；

"(abcd(e)" no；

"(a)(b)" yes。

要求必须用递归写，整个实现不可以出现一个循环语句。*/

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