#include "stack"
#include "vector"
#include "iostream"
using namespace std;

int reStack(stack<int,vector<int>>& stack){
	if (stack.empty())
		return 0;
	int  tmp = stack.top(); //这个临时变量会一直存在状态里面
	stack.pop();
	if (stack.empty())  //如果移除一个后为空了，说明已经最后一个元素，栈底ok获取
	{
		cout << "tmp==" << tmp << endl;
		return tmp;
	}
	else{
		int  res = reStack(stack); //没到栈底，继续走，，一直到底
		stack.push(tmp); //没到栈底，那么应该把这个都压入，，
		cout <<"res: " << res << endl;
		return res;  //结果一步步返回给最终的
	}

}

int reStack2(stack<int, vector<int>>& stack, int tmp){ //一样实现了
	tmp = stack.top();
	stack.pop();
	if (stack.empty())
	{
		cout << "null ..." << tmp << endl;
		return tmp;
	}
	else{
		int res = reStack2(stack, tmp);
		stack.push(tmp);
		cout << "rr...==res==" << res << endl;
		return res;
	}
}

void reverse(stack<int, vector<int>>&stack){
	if (stack.empty())
	{
		return;
	}
	int i = reStack(stack); //获取栈底元素，，，
	//if (stack.empty())
	//{
	//	stack.push(i);
	//}
	if (!stack.empty())  //补位空，，那么应该继续去获取栈底的，，
		reverse(stack);//
	stack.push(i); //压入栈底，这样就成了逆序了
}
int main(){
	vector<int> vec{ 1, 2, 3, 4 };
	stack<int,vector<int>> stack(vec);
	int tmp = 0;
	reStack2(stack,tmp);
	//reStack(stack);
	reverse(stack);
	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}