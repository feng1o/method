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

void recur2(int n){  //此版本必然导致死迭代递归，，，为什么，最好每次判定递归，能递归再递归
	static int i = 0;
	if (n == 1)
	{
		cout << "n=" << n << endl;
	}
	cout << "nn===" << n << endl;
	recur2(n - 1); // 判定
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
		return;//比如这个，不管有没有return都是一样的，，没区别，因为没有访问标记
	}
	cout << "nn===" << n << endl;
	recur(n - 1);
	recur(n - 2); //有了这个，不管return有无，都会继续走第二次进入满足n==1地方
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