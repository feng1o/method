/*
���дһ������������ĳ���ϵ����зǿ��Ӽ���
����һ��int����A������Ĵ�Сint n���뷵��A�����зǿ��Ӽ�����֤A��Ԫ�ظ���С�ڵ���20����Ԫ�ػ��졣���Ӽ��ڲ��Ӵ�С����,�Ӽ�֮���ֵ��������򣬼�������
����������
[123,456,789]
���أ�{[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}
http://www.nowcoder.com/practice/1f2700e2b1904254b55765479e9b8766?tpId=8&tqId=11037&rp=3&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking
����˼·��
��n-1�����������Ӽ��Ļ���������n�����������Ӽ���sets(n)ͨ�����²����ã�
1. ��sets(n-1)�������Ӽ�ǰ�߲��뵱ǰԪ��A[n-1]��
2. A[n-1]������Ϊһ���Ӽ�[A[n-1]]��
3. sets(n-1)ͬʱҲӦ������sets(n)�С�
�ٸ����ӣ�
A={1,2,3};
1.��������һ��Ԫ�ص��Ӽ�sets(1)={{1}}��
2.����Ԫ��2����sets(2)����������ɣ�
��1����sets(1)�������Ӽ�ǰ�߲��뵱ǰԪ��A[1]=2���õ�{{2,1}}��
��2��A[1]������Ϊһ���Ӽ�{2}��
��3��sets(1)ͬʱҲӦ������sets(2)�У�sets(3) = {{2,1},{2},{1}}��
3.����Ԫ��3����sets(3)����������ɣ�
��1����sets(2)�������Ӽ�ǰ�߲��뵱ǰԪ��A[2]=3���õ� {{3,2,1},{3,2},{3,1}}��
��2��A[2]������Ϊһ���Ӽ�{3}��
��3��sets(2)ͬʱҲӦ������sets(3)�У�sets(3) = {{3,2,1},{3,2},{3,1},{3},{2,1},{2},{1}}��
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
		//���������� n > indexӦ���˳����������ǲ���������������return����������ݹ���
		if (n == index){
			ans.push_back(vector<int>());
			return; //���û�������ݹ�
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
	//�ǵݹ�汾...........
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