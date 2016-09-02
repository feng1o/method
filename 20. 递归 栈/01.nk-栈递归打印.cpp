#include "stack"
#include "vector"
#include "iostream"
using namespace std;

int reStack(stack<int,vector<int>>& stack){
	if (stack.empty())
		return 0;
	int  tmp = stack.top(); //�����ʱ������һֱ����״̬����
	stack.pop();
	if (stack.empty())  //����Ƴ�һ����Ϊ���ˣ�˵���Ѿ����һ��Ԫ�أ�ջ��ok��ȡ
	{
		cout << "tmp==" << tmp << endl;
		return tmp;
	}
	else{
		int  res = reStack(stack); //û��ջ�ף������ߣ���һֱ����
		stack.push(tmp); //û��ջ�ף���ôӦ�ð������ѹ�룬��
		cout <<"res: " << res << endl;
		return res;  //���һ�������ظ����յ�
	}

}

int reStack2(stack<int, vector<int>>& stack, int tmp){ //һ��ʵ����
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
	int i = reStack(stack); //��ȡջ��Ԫ�أ�����
	//if (stack.empty())
	//{
	//	stack.push(i);
	//}
	if (!stack.empty())  //��λ�գ�����ôӦ�ü���ȥ��ȡջ�׵ģ���
		reverse(stack);//
	stack.push(i); //ѹ��ջ�ף������ͳ���������
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