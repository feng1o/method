#if 0
/*ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
����һ�������д洢��һ����Ʊ����һ�콻�״����ڸ�ʱ���Ĺ�Ʊ�۸�����������ֻ����һ�������һ�����������ṩһ���㷨�������ͨ��������������Եõ����������
����
�۸����У���,�Ÿ���
���
���Ŀ�������

��������
2,3,2,4
�������
2

*/

#include "iostream"
#include "string"
#include "vector"
using namespace std;

int deal(vector<int> vec, int x, int n)
{
	int lhs = 0; 
	int rhs = n - 1;
	while (lhs < rhs){
		int mid = (lhs + rhs) / 2;
		if (vec[mid] == x)
			return mid;
		if (x > vec[mid]){
			lhs = mid + 1;
		}
		else if (x < vec[mid]){
			rhs = mid - 1;
		}
	}
	if (lhs == 0){
		int i = 0;
		for (; i < n && vec[i] < x; ++i);
		return -1 - i;
	}

	else {
		int i = lhs-1;
		while (i < n && vec[i] < x)
			++i;
		return -1 - i;
	}

}
int main(){
	int x;
	int n;
	vector<int> vec;
	while (cin >> x >> n){
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int result = deal(vec, x, n);
		cout << result << endl;
	}
	return 0;
}
#endif