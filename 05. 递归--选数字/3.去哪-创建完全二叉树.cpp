#if 01
#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>
#include "cassert"
#include "cmath"
using namespace std;

typedef char elemType;
typedef struct tag_BinTreeNode binTreeNode;
typedef  binTreeNode * pBinTree;

struct tag_BinTreeNode
{
	tag_BinTreeNode(char ch) :lchild(NULL), rchild(NULL), data(ch){};
	elemType data;
	binTreeNode* lchild, *rchild;
};

int getHeight(pBinTree tree){
	if (tree == nullptr)
		return 0;
	else{
		int l = getHeight(tree->lchild);
		int r = getHeight(tree->rchild);
		return l > r ? l + 1 : r + 1;
	}
}

pBinTree CreatBinTree2(vector<char> vec, int n)
{
	char ch;

	pBinTree tmptree;

	if (n >= vec.size())
	{
		tmptree = NULL;
		return tmptree;

	}
	else
	{
		//*tree = new binTreeNode;//这样需要构造器
		tmptree = (pBinTree)malloc(sizeof(binTreeNode));
		//tmptree = (pBinTree)calloc(1,sizeof(binTreeNode));
		assert(tmptree != NULL);
		tmptree->data = vec[n];
		tmptree->lchild = NULL;
		tmptree->rchild = NULL;
		//printf("插入了= %c\n", tmptree->data);

		tmptree->lchild = CreatBinTree2(vec, 2*n+1);
		tmptree->rchild = CreatBinTree2(vec, 2*n+2);
	}
	return tmptree;
}
void VistBinTree(pBinTree tree, int level)
{
	//std::cout << "访问节点 " << tree->data <<"：层数 "<< level << std::endl;
	printf("%c位于第%d层\n", tree->data, level);
}

//遍历二叉树
void PreOrderTravelBinTree(pBinTree tree, int level)
{
	if (tree)
	{
		//VistBinTree(tree, level);
		cout << tree->data << endl;
		PreOrderTravelBinTree(tree->lchild, level + 1); //这里就是单纯递归，非回溯，回溯会是选择，比如
		PreOrderTravelBinTree(tree->rchild, level + 1);
	}
	else
	{
		//printf("递归了]\n");
	}
}
void printTree(pBinTree tree, int i, int h){
	vector<int> vec(h, 0);
	for (int i = 1; i < h; ++i){
		int tmp = pow(2, i-1);
		for (int j = 0; j < i; ++j)
		{
			tmp += vec[j];
		}
		vec[i] = tmp + 1;
	}
	deque<pBinTree>  deq;
	deq.push_back(tree);
	for (int i = h - 1; i >= 0; ++i){
		for (int i = 0; i < vec[i]; ++i)
		{
			cout << " ";
		}
		pBinTree node = deq.front();
		deq.pop_front();
		cout << node->data << endl;
		for (int j = 0; j <= i; ++j)
		{
			for (int k = 0; k < vec[i] - j - 1; ++k)
			{
				cout << " ";
			}
			cout << '/';
		}
	}
}
int main()
{
	vector<char> vec;
	string str;
	while (getline(cin, str)){
		stringstream ss;
		ss.str(str);
		//ss << str;
		//cout << ss.str() << endl;
		char ch3, ch1, ch2, ch4;
		//ss.ignore(1);
		ss >> ch1;
		//cout << ch1 << "....." << endl;
		while (ss >> ch1 >> ch2 >> ch3 >> ch4){
			//cout << ch2  << endl;
			vec.push_back(ch2);
		}
		/*	for (auto it : vec)
			{
			cout << it << endl;
			}*/


		//pBinTree tree2 = CreatBinTree2(vec, 0);//1级指针
		//cout << "height =" << getHeight(tree2) << endl;
		//int h = getHeight(tree2);
		//PreOrderTravelBinTree(tree2, 1);
		for (int i = 0; i < 10;++i)
		{
			cout << " ";
		}
		cout << 'A' << endl;
		for (int i = 0; i < 9; ++i)
			cout << " ";
		cout << '/';
		cout << " ";
		cout << '\\' << endl;
		for (int i = 0; i < 8; ++i)
			cout << " ";
		cout << '/';
		cout << " ";
		cout << '\\' << endl;
		for (int i = 0; i < 7; ++i)
			cout << " ";
		cout << '/';
		cout << " ";
		cout << '\\' << endl;
		for (int i = 0; i < 6; ++i)
			cout << " ";
		cout << '/';
		cout << " ";
		cout << '\\' << endl;
	}
	return 0;
}
#endif