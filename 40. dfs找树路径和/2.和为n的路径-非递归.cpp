//非递归版本
//思路：
//1.按先序遍历把当前节点cur的左孩子依次入栈同时保存当前节点，每次更新当前路径的和sum；
//2.判断当前节点是否是叶子节点以及sum是否等于expectNumber，如果是，把当前路径放入结果中。
//3.遇到叶子节点cur更新为NULL，此时看栈顶元素，如果栈顶元素的把栈顶元素保存在last变量中，同时弹出栈顶元素，当期路径中栈顶元素弹出，sum减掉栈顶元素，这一步骤不更改cur的值；
//4.如果步骤3中的栈顶元素的右孩子存在且右孩子之前没有遍历过，当前节点cur更新为栈顶的右孩子，此时改变cur = NULL的情况。
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
	int sum = 0; //当前和
	vector<int> curPath; //当前路径
	TreeNode *cur = root; //当前节点   如果设置null。错误！！！！！！！！！
	TreeNode *last = NULL; //保存上一个节点
	while (!s.empty()){
		if (cur == NULL){
			TreeNode *temp = s.top();
			if (temp->right != NULL && temp->right != last){//防止是从右子树往回走，这个很有用，必须判定，她这个方法就是为了确定是从右边走回去的时候，倒
				cur = temp->right; //转向未遍历过的右子树
			}
			else{
				last = temp; //保存上一个已遍历的节点
				s.pop();
				curPath.pop_back(); //从当前路径删除
				sum -= temp->val; //恢复....
			}
		}
		else{
			s.push(cur);
			sum += cur->val;
			curPath.push_back(cur->val);
			if (cur->left == NULL && cur->right == NULL && sum == expectNum){
				res.push_back(curPath);
			}
			cur = cur->left; //先序遍历，左子树先于右子树
		}
	}
	return res;
}

//my 方法 错误的...
//必须能知道最后一次访问的是不是他的右子节点
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
			stack.push(cur);//cur可能会被push进去两次，甚至很多次，出现错误
			ivec.push_back(cur->val);
			cur = cur->left;
		}
		else if (!stack.empty()){
			cur = stack.top();
			//如果不一定是从跟到叶子节点这个怎么解决？
			if (cur->left == nullptr && !cur->right && sum == expectNumber)
				ans.push_back(ivec);
			else if (cur->left == nullptr && !cur->right && sum != expectNumber){
				sum -= cur->val;  //可以用一个最后访问的节点来解决这个问题，看下面的方法，
				ivec.pop_back();
				stack.pop();//可以用一个最后访问的节点来解决这个问题，看下面的方法，pop是必须的
				cur = stack.top();
			}
			cur = cur->right;
		}
	}

	return ans;
}