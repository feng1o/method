#if 0
#define  _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "string"

using namespace std;


class ca{
public:
	ca(){};
	ca(const ca& x) {
		strcpy(a, x.a);
		//memset(a, x.a[0], 3);
		//a[0] = x.a[0];
		//a[1] = x.a[1];
		//a[2] = x.a[2];
	}
	~ca(){};
private:
	char a[3];
};

void recur2(int n){  //�˰汾��Ȼ�����������ݹ飬����Ϊʲô�����ÿ���ж��ݹ飬�ܵݹ��ٵݹ�
	static int i = 0;
	if (n == 1)
	{
		cout << "n=" << n << endl;
	}
	cout << "nn===" << n << endl;
	recur2(n - 1); // �ж�
	++i;
	cout << "iiiiiiiiii = " << i << endl;
}
void recur(int n){
	static int i = 0;
	if (n < 1)
		return;
	if (n == 1)
	{
		cout << "n=" << n << endl;
		return;//���������������û��return����һ���ģ���û������Ϊû�з��ʱ��
	}
	cout << "nn===" << n << endl;
	recur(n - 1);
	recur(n - 2); //�������������return���ޣ���������ߵڶ��ν�������n==1�ط�
	//cout << "nn===" << n << endl;
	++i;
	cout << "iiiiiiiiii = " << i << endl;
}
int main(){
	recur(3);
	cout << endl;
	char a[4] = { 'a', 'b', 'c', '\0' };
	char b[4];
	strcpy(b, a);
	cout << b << endl;

	ca aa;
	ca bb = aa;
	cout << sizeof(aa) << endl;
	cout << &aa << "..." << &bb << endl;
	cout << "xxxxxxxxx\n";
	return 0;
}
#endif