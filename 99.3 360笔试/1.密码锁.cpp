#if 01
/*����
�������ж���������ݡ�ÿ�����������3x3�ľ��󹹳ɣ����С�X����ʾ���µİ�������.�� ��ʾδ���µİ����������п��ܲ�������X����Ҳ����û�С�.����
���
��ÿ��������ݣ��ڵ������������������������������ĶԳƵģ����YES���������NO��

��������
XX.
...
.XX
X.X
X..
...
�������
YES
NO*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool deal(vector<vector<char>> vec){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
		{
			if (vec[i][j] != vec[2 - i][2 - j])
				return false;
		}
	}
	return true;
}
int main(){
	while (1){
		vector<vector<char>> vec(3, vector<char>(3, '.'));
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> vec[i][j];
			}
		}


		if (deal(vec))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//if (cin.get() == '\n')
			//break;
	}
	return 0;
}


#endif
#if 0
#include<iostream>
#include<string>
#include<vector>

using namespace std;
bool deal(vector<vector<char>> vec){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j)
		{
			if (vec[i][j] != vec[2 - i][2 - j])
				return false;
		}
	}
	return true;
}
int main(){
	vector<vector<char>> vec(3, vector<char>(3, '.'));
	int tmp;
	while (cin >> vec[0][0]){
		cin >> vec[0][1];
		cin >> vec[0][2];
		for (int i = 1; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> vec[i][j];
			}
		}


		if (deal(vec))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
#endif
