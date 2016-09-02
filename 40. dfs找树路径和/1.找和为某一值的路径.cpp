/*
tip: http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=8&tqId=11018&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
1.dfs和中序遍历是不一样的....放的位置不同,,,
2.如果没要求这个路径从根开始，叶子节点结束呢？任意一个段路径呢？？
3.不用回溯呢？递归呢？
4.区分回溯递归，什么时候用引用，什么地方元素不用引用
5.注意回溯的时候，最后的清除前一步问题
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
	//tip:sum不能是引用，，，但是ans， iVec必须是引用，，，，，，，，，
	//如果只是让判定有无这样的路径呢，，如何优化，，，sto 66题，这里是树结构，所以不会存在问题，
    bool deal(TreeNode* root,int sum, int exp, vector<vector<int>>& ans, vector<int>& ivec){
        if(root == nullptr){
            sum = 0;
            return false;
        }
        sum += root->val;
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right) 
			//tip2:此时就是默认到叶节点的路径
			//如果任意路径如何求？
            ans.push_back(ivec);
		//此处说明找到了，如果加return，那么就不会走下去，最后不会pop，那么导致（此题因为没有标记走过否）最后其他结果也会有这个最后一步的多余点，错误
		//另外，这个题有无return不会影响结果都少种，都会通，但是结果不对，因没标记
        if(root->left){
            deal(root->left, sum, exp, ans, ivec);
        }
        
        /*sum += root->val;  //此处就是中序遍历，这样不是深度优先了
        ivec.push_back(root->val);
        if(sum == exp && root->left == nullptr && !root->right)
            ans.push_back(ivec);*/
        
		if(root->right){
            deal(root->right, sum, exp, ans, ivec);
        }
		//5.注意回溯的时候，最后的清除前一步问题
			ivec.pop_back();
        return true;
    }

	//错误版本
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
//参考:
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