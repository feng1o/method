/*����һ�����룬����������ȣ��ֱ�Ϊm1,m2,m3��mn��
ÿ�������Ӧ������Ϊx1,x2,x3...xn������Ҫ����Щ����ȥ����������������ܳƳ������в�ͬ��������
http://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c?tpId=37&tqId=21264&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
�ο���
/*������1��ʼ����������ǰi�������ܳƳ��Ĳ�ͬ����ΪQ[i],��ôQ[i]һ����������������ģ���Q[i-1]�Ļ����ϣ���Q[i-1]����ͬ���������ֱ����k������i������ӵĹ����г�ȥ�ظ������
//���裺w[N]��ʾN����ͬ���������루������N=6����w[0~N-1]��
//      c[N]��ʾN����ͬ������Ӧ��������c[1~N]��
//��Q[i] = (Q[i-1] + k*w[i])-��ӹ������ظ��ĸ���������0=<k<=c[i]�����ϲ����ѵĽ���˼·*/

* /

#define  _CRT_SECURE_NO_WARNINGS
#include "cstdlib"
#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "functional"

using namespace std;

int main(){
	freopen("data.in", "r", stdin);
	int n = 0;
	while (cin >> n){
		//cout << n << endl;
		vector<int>  m(n, 0);
		vector<int>  c(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> m[i];
		for (int i = 0; i < n; ++i)
			cin >> c[i];
		vector<int> w;
		//w.push_back(0);
		for (int i = 0; i <= c[0]; ++i) //ȡ�ȡ�����������������
		{
			w.push_back(i*m[0]);
		}
		for (int j = 1; j < n; ++j)
		{
			int size = w.size();
			for (int k = 1; k <= c[j]; ++k)   //ȡ�ȡ�����������������
			{
				for (int i = 0; i < size; ++i)
				{
					if (find(w.begin(), w.end(), w[i] + k*m[j]) == w.end())
					{
						w.push_back(w[i] + k*m[j]);
					}
				}
			}
		}
		//w.push_back(0);
		cout << w.size() << endl;
	}
	return 0;
}