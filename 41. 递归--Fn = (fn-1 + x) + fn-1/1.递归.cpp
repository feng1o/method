/*
请编写一个方法，返回某集合的所有非空子集。
给定一个int数组A和数组的大小int n，请返回A的所有非空子集。保证A的元素个数小于等于20，且元素互异。各子集内部从大到小排序,子集之间字典逆序排序，见样例。
测试样例：
[123,456,789]
返回：{[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}
http://www.nowcoder.com/practice/1f2700e2b1904254b55765479e9b8766?tpId=8&tqId=11037&rp=3&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking
解题思路：
在n-1个数的所有子集的基础上生成n个数的所有子集，sets(n)通过如下步骤获得：
1. 在sets(n-1)的所有子集前边插入当前元素A[n-1]。
2. A[n-1]单独作为一个子集[A[n-1]]。
3. sets(n-1)同时也应包含到sets(n)中。
举个例子：
A={1,2,3};
1.首先生成一个元素的子集sets(1)={{1}}。
2.加入元素2，则sets(2)由三部分组成：
（1）在sets(1)的所有子集前边插入当前元素A[1]=2，得到{{2,1}}；
（2）A[1]单独作为一个子集{2}；
（3）sets(1)同时也应包含到sets(2)中，sets(3) = {{2,1},{2},{1}}。
3.加入元素3，则sets(3)由三部分组成：
（1）在sets(2)的所有子集前边插入当前元素A[2]=3，得到 {{3,2,1},{3,2},{3,1}}；
（2）A[2]单独作为一个子集{3}；
（3）sets(2)同时也应包含到sets(3)中，sets(3) = {{3,2,1},{3,2},{3,1},{3},{2,1},{2},{1}}。
*/

class Subset {
public:
	vector<vector<int> > getSubsets(vector<int> A, int n) {
		// write code here
		vector<vector<int>> ans;
		//int size = A.size();
		deal(A, ans, 0, n);
		sort(ans.begin(), ans.end(), std::greater<vector<int>>());//tip
		//reverse(ans.begin(), ans.end());
		ans.pop_back();
		//sort(ans.begin(), ans.end());
		return ans;
	}
	void deal2(vector<int> &vec, vector<vector<int>> &ans, int index, int n){
		//最好这里加上 n > index应该退出，，这里是不会错，不过如果忘了return，这就是死递归了
		if (n == index){
			ans.push_back(vector<int>());
			return; //如果没他，死递归
		}
		deal(vec, ans, index + 1, n);
		int size = ans.size();
		for (int i = 0; i < size; ++i){
			vector<int> tmp = ans[i];
			tmp.push_back(vec[index]);
			ans.push_back(tmp);
		}
		//  ans.push_back(vector<int>());
		// ans.push_back(vector<int>(1, vec[index]));

	}
	//非递归版本...........
	void deal(vector<int> &vec, vector<vector<int>> &ans, int index, int n){
		ans.push_back(vector<int>());
		vector<vector<int>>  tans;
		for (int j = n - 1; j >= 0; --j){
			tans.clear();
			for (int i = 0; i < ans.size(); ++i){
				vector<int> tmp = ans[i];
				tmp.push_back(vec[j]);
				tans.push_back(tmp);
			}
			ans.insert(ans.end(), tans.begin(), tans.end());
		}
	}
};