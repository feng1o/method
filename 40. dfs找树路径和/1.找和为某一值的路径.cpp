/*
tip: http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=8&tqId=11018&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
1.dfs����������ǲ�һ����....�ŵ�λ�ò�ͬ,,,
2.���ûҪ�����·���Ӹ���ʼ��Ҷ�ӽڵ�����أ�����һ����·���أ���
3.���û����أ��ݹ��أ�
4.���ֻ��ݵݹ飬ʲôʱ�������ã�ʲô�ط�Ԫ�ز�������
5.ע����ݵ�ʱ���������ǰһ������
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> ans;
        vector<int> ivec;
        int sum = 0;
        deal(root, sum, expectNumber, ans, ivec);
        return ans;
    }
	//tip:sum���������ã���������ans�� iVec���������ã�����������������
	//���ֻ�����ж�����������·���أ�������Ż�������sto 66�⣬���������ṹ�����Բ���������⣬
    bool deal(TreeNode* root,int sum, int exp, vector<vector<int>>& ans, vector<int>& ivec){
        if(root == nullptr){
            sum = 0;
            return false;
        }
        sum += root->val;
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right) 
			//tip2:��ʱ����Ĭ�ϵ�Ҷ�ڵ��·��
			//�������·�������
            ans.push_back(ivec);
		//�˴�˵���ҵ��ˣ������return����ô�Ͳ�������ȥ����󲻻�pop����ô���£�������Ϊû�б���߹�������������Ҳ����������һ���Ķ���㣬����
		//���⣬���������return����Ӱ���������֣�����ͨ�����ǽ�����ԣ���û���
        if(root->left){
            deal(root->left, sum, exp, ans, ivec);
        }
        
        /*sum += root->val;  //�˴�������������������������������
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right)
            ans.push_back(ivec);*/
        
		if(root->right){
            deal(root->right, sum, exp, ans, ivec);
        }
		//5.ע����ݵ�ʱ���������ǰһ������
			ivec.pop_back();
        return true;
    }

	//����汾
    bool deal_error(TreeNode* root,int sum, int exp, vector<vector<int>>& ans, vector<int>& ivec){
        if(sum == exp)
            ans.push_back(ivec);
        if(root == nullptr){
            sum = 0;
            return false;
        }
        if(root->left){
            deal(root->left, sum, exp, ans, ivec);
        }
        //if(sum == exp)
            //ans.push_back(ivec);
        sum += root->val;
        ivec.push_back(root->val);
        if(sum == exp)
            ans.push_back(ivec);
		if(root->right){
            deal(root->right, sum, exp, ans, ivec);
        }
        //sum -= root->val;
        ivec.pop_back();
        return true;
    }
    
    //new method
	vector<vector<int> > FindPath2(TreeNode* root,int expectNumber) {
		vector<vector<int>> ans;
        vector<int> ivec;
        //int sum = 0;
        if(root)
        	deal2(root, expectNumber, ans, ivec);
        return ans;
    }
    void deal2(TreeNode* root,int exp, vector<vector<int>>& ans, vector<int>& ivec){
        if(root == nullptr)
			return ;
        ivec.push_back(root->val);
        if(exp == root->val && !root->left && !root->right)
            ans.push_back(ivec);
        else{
            if(root->left)
                deal2(root->left, exp-root->val, ans, ivec);
            if(root->right)
                deal2(root->right, exp-root->val, ans, ivec);
        }
        ivec.pop_back();
    }
};
/*
//�ο�:
    void dfsFind(TreeNode * node , int left){
        tmp.push_back(node->val);
        if(left-node->val == 0 && !node->left && !node->right)
            allRes.push_back(tmp);
        else {
            if(node->left) dfsFind(node->left, left-node->val);
            if(node->right) dfsFind(node->right, left-node->val);
        }
        tmp.pop_back(); 
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfsFind(root, expectNumber);
        return allRes;
    }
*/