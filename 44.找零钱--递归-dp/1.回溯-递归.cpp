//�ҳ�һ���ж����֣������������ѵ��أ�http://www.cnblogs.com/anderslly/archive/2011/03/06/making-changes.html
#include "iostream"
#include "string"
#include "vector"

using namespace std;
//http://www.cnblogs.com/anderslly/archive/2011/03/06/making-changes.html
/*̰���㷨������������Ǯ��Ŀ�㹻���ʱ������ѵ�һ���⣬����������Ǯ������ʱ����
public static int[] MakeChange(int money, int[] changes)
{
    int[] result = new int[changes.Length];

    for (int i = 0; i < changes.Length; i++)
    {
        result[i] = money / changes[i];
        money = money % changes[i];

        if (money == 0) { break; }
    }

    return result;
}*/
void deal(int* a, int& ans, int n){
	if (n == 0){
		ans += 1;
		ans %= 1000000007;
		return;
	}
	if (n < 0)
		return;
	//if (n > 0){ //�ǵݹ飬������Ǯ��������
	//	if (n / *a > 0)
	//		deal(a, ans, n - a[0]);
	//	else
	//		deal(a + 1, ans, n);
	//}
	if( n > 0){  //������ݹ��̻���ִ����ظ������������ԣ�����Ϊ��Ǯ��������˳��ģ�1,1��5��5,1,1����Ϊ��ͬ
	deal(a, ans, n-a[0]);
	deal(a, ans, n-a[1]);
	deal(a, ans, n-a[2]);
	deal(a, ans, n-a[3]);
	}
}
//�ݹ���һ���ж���������Ǯ��������������ʱ���޷����
void deal2(int* a, int& ans, int n, int last){
	if (n == 0){
		ans += 1;
		ans %= 1000000007;
		return;
	}
	if (n < 0)
		return;
	if (n > 0){  //
		if (last >= a[0]) //��֤��Ǯ�ǰ��մӴ�С�ģ������ȳ��֣�5,1���ֳ��ָ�1,5������ֻ��1��1,1,1,1,1,1,1,1
		deal2(a, ans, n - a[0], a[0]);
		if (last >= a[1])
		deal2(a, ans, n - a[1], a[1]);
		if (last >= a[2])
		deal2(a, ans, n - a[2], a[2]);
		if (last >= a[3])
		deal2(a, ans, n - a[3], a[3]);
	}
}
int deal3(int *a, int &ans, int n, int cur){ //�ݹ�ķ������������������˼·��ǰ��� ����㲻ͬ
	int next;
	switch (cur){
	case 25:
		next = 10;
		break;
	case 10:
		next = 5;
		break;
	case 5:
		next = 1;
		break;
	case 1:
		return 1;
		// next = 1;

	}
	int cnt = 0;
	for (int i = 0; i*cur <= n; ++i){
		ans += 1;
		cnt += deal3(a, ans, n - i*cur, next);
	}
	return cnt;
}


int dealdp2(int *a, int N, int sum){
	if (a == nullptr || N < 1 || sum < 0) return 0;
	vector<vector<int>> vec(N+1, vector<int>(sum + 1, 0));
	for (int i = 0; i <= N; ++i)
		vec[i][0] = 1;
	for (int i = 1; i <= N; ++i){
		for (int j = 1; j <= sum; ++j){
			for (int k = 0; k <= j/a[i-1]; ++k){
				//vec[i][j] += vec[i - 1][j - k * a[i]];
				vec[i][j] += vec[i - 1][j - k * a[i-1]];
			}
		}
	}
	return vec[N][sum];
}

int dealdp(int *a, int N, int sum){ //��Ȿ�ʡ���������ʵ�ʴ�dealdp2����� ���������ܽ����
	if (a == nullptr || N < 1 || sum < 0) return 0;
	vector<int> vec(sum+1, 0);
	vec[0] = 1;
	for (int i = 1; i <= N; ++i){
		for (int j = a[i-1] ; j <= sum; ++j){
			//vec[j] += vec[j - a[i - 1]] % 1000000007;
			vec[j] = (vec[j] + vec[j - a[i - 1]]) % 1000000007;
			}
		}
	return vec[sum];
}

int countWays(int n) {
	// write code here
	int change[] = {1,5,10,25 };
	int ans = 0;
	//deal(change, ans, n);
	//deal2(change, ans, n, n);
	//deal3(change, ans, n, 25);
	//return ans; 
	return dealdp(change, 4, n);
}
int main(){
	//cout << 
	cout << countWays(7) << endl;
	cout << countWays(3) <<endl;
	cout << countWays(5) <<endl;
	cout << countWays(1000) << endl; //1000��Ҫ�ܾ��ˣ���10000����������������
	return 0;
}