/*����������ʱ��
ʱ�����ƣ�C/C++���� 10MS���������� 2010MS
�ڴ����ƣ�C/C++���� 1KB���������� 524289KB
��Ŀ������
���������ط���ȥ����������ص�2015�꣬����ѡ��һ֧��Ʊ����Ͷ�ʣ���ӵ����֧��Ʊδ��n��ļ۸�����ͼ��Ϊ�˶��֤���ļ�أ���ֻ��һ�������������ᡣ����Ҫ��ʵ��һ��������������������������ܻ��������档
����
��һ��Ϊ����n
������n�� Ϊ�����n������Ԫ�أ������n��ù�Ʊ�ļ۸�
���
���Ϊb��s      #�����b�����룬��s������

������0��ʼ
���û���ʺϵ��������� ��� -1,-1
ͬ������ʱԽ������Խ��������������Ҫ

��������
5
2
1
4
5
3
�������
1, 3

*/

#if 0
#include "iostream"
#include "string"
#include "vector"
#include "climits"

using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector<int> vec;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int max = 0;
		int min = INT_MAX;
		int lhs = -1;
		int rhs = -1;
		for (int i = 0; i < n; ++i)
		{
			if(vec[i] < min){
				min = vec[i];
				lhs = i;
			}
			if(vec[i] - min > max){
				rhs = i;
			}
			/*for (int j = i + 1; j < n; ++j)
			{
				if (vec[j] - vec[i] > max){
					max = vec[j] - vec[i];
					lhs = i;
					rhs = j;
				}
			}*/
		}
		cout << lhs << "," << rhs << endl;
	}
	return 0;
}
#endif