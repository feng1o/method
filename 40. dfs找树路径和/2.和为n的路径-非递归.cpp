//�ǵݹ�汾
//˼·��
//1.����������ѵ�ǰ�ڵ�cur������������ջͬʱ���浱ǰ�ڵ㣬ÿ�θ��µ�ǰ·���ĺ�sum��
//2.�жϵ�ǰ�ڵ��Ƿ���Ҷ�ӽڵ��Լ�sum�Ƿ����expectNumber������ǣ��ѵ�ǰ·���������С�
//3.����Ҷ�ӽڵ�cur����ΪNULL����ʱ��ջ��Ԫ�أ����ջ��Ԫ�صİ�ջ��Ԫ�ر�����last�����У�ͬʱ����ջ��Ԫ�أ�����·����ջ��Ԫ�ص�����sum����ջ��Ԫ�أ���һ���費����cur��ֵ��
//4.�������3�е�ջ��Ԫ�ص��Һ��Ӵ������Һ���֮ǰû�б���������ǰ�ڵ�cur����Ϊջ�����Һ��ӣ���ʱ�ı�cur = NULL�������
//http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=8&tqId=11018&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking

#include <iostream>
#include <vector>
#include "stack"

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};




vector<vector<int> > FindPath(TreeNode *root, int expectNumber){
	vector<vector<int> > res;
	if (root == NULL)
		return res;
	stack<TreeNode *> s;
	s.push(root);
	int sum = 0; //��ǰ��
	vector<int> curPath; //��ǰ·��
	TreeNode *cur = root; //��ǰ�ڵ�   �������null�����󣡣���������������
	TreeNode *last = NULL; //������һ���ڵ�
	while (!s.empty()){
		if (cur == NULL){
			TreeNode *temp = s.top();
			if (temp->right != NULL && temp->right != last){//��ֹ�Ǵ������������ߣ���������ã������ж����������������Ϊ��ȷ���Ǵ��ұ��߻�ȥ��ʱ�򣬵�
				cur = temp->right; //ת��δ��������������
			}
			else{
				last = temp; //������һ���ѱ����Ľڵ�
				s.pop();
				curPath.pop_back(); //�ӵ�ǰ·��ɾ��
				sum -= temp->val; //�ָ�....
			}
		}
		else{
			s.push(cur);
			sum += cur->val;
			curPath.push_back(cur->val);
			if (cur->left == NULL && cur->right == NULL && sum == expectNum){
				res.push_back(curPath);
			}
			cur = cur->left; //�������������������������
		}
	}
	return res;
}

//my ���� �����...
//������֪�����һ�η��ʵ��ǲ����������ӽڵ�
vector<vector<int> > FindPath44(TreeNode *root, int expectNumber){
	vector<vector<int>> ans;
	vector<int> ivec;
	if (!root)
		return ans;
	stack<TreeNode*> stack;
	TreeNode* cur = root;
	int sum = 0;
	while (!stack.empty() || cur){
		if (cur){
			sum += cur->val;
			stack.push(cur);//cur���ܻᱻpush��ȥ���Σ������ܶ�Σ����ִ���
			ivec.push_back(cur->val);
			cur = cur->left;
		}
		else if (!stack.empty()){
			cur = stack.top();
			//�����һ���ǴӸ���Ҷ�ӽڵ������ô�����
			if (cur->left == nullptr && !cur->right && sum == expectNumber)
				ans.push_back(ivec);
			else if (cur->left == nullptr && !cur->right && sum != expectNumber){
				sum -= cur->val;  //������һ�������ʵĽڵ������������⣬������ķ�����
				ivec.pop_back();
				stack.pop();//������һ�������ʵĽڵ������������⣬������ķ�����pop�Ǳ����
				cur = stack.top();
			}
			cur = cur->right;
		}
	}

	return ans;
}