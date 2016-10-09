#if 0
/*С�ȵĸ�������
��Ŀ������
������վ�ֺܾ�֮��С�Ⱦ������ܾ��������˷�ʱ������ഺ��������ȥ�򸱱���
��εĸ���ֻ��һ��BOSS������BOSS�ǲ���Ҫ��ɱ�ģ�ֻ��Ҫ��������������.
BOSS���г�һ�����������У���С���ȿ�ʼ��Ȼ�����������������е�����һ��ȡ����ȡ�õ����ۼӵ����������������ȡ�꣬��Ϸ������
����С�Ⱥ�BOSS���ܴ�����������ȡ���ķ����������Ų��ԣ���������˵÷ָ��Ƕ��١�
����
��һ�У�һ��������N��2 �� N �� 100������ʾ�������������ĸ�����
�ڶ�����ĩβ���ÿո������N����������1 �� a[i] �� 200��
���
ֻ��һ�У��ÿո��������������С�ȵĵ÷ֺ�BOSS�ĵ÷֡�

��������
6
4 7 2 9 5 2
�������
18 11
*/

#include <iostream>

using namespace std;

int **dp1, **dp2;
int secondMax(int data[], int left, int right);

int firstMax(int data[], int left, int right){
	if (left == right)	return data[left];
	if (dp1[left][right] != -1)	return	dp1[left][right];
	int getLeft = data[left] + secondMax(data, left + 1, right);
	int getRight = data[right] + secondMax(data, left, right - 1);
	if (getLeft > getRight)
		dp1[left][right] = getLeft;
	else
		dp1[left][right] = getRight;
	return dp1[left][right];
}

int secondMax(int data[], int left, int right){
	if (left == right)	return 0;
	if (dp2[left][right] != -1)	return	dp2[left][right];
	int getLeft = firstMax(data, left + 1, right);
	int getRight = firstMax(data, left, right - 1);
	if (getLeft < getRight)
		dp2[left][right] = getLeft;
	else
		dp2[left][right] = getRight;
	return dp2[left][right];
}

int main(){
	int n, tmp;
	scanf("%d", &n);
	int *data = new int[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		data[i] = tmp;
	}
	int first, second;
	int sum = 0;
	dp1 = new int*[n];
	for (int i = 0; i < n; i++){
		dp1[i] = new int[n];
	}
	dp2 = new int*[n];
	for (int i = 0; i < n; i++){
		dp2[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dp1[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	first = firstMax(data, 0, n - 1);
	for (int i = 0; i < n; i++)
		sum += data[i];
	second = sum - first;
	for (int i = 0; i < n; i++){
		delete[] dp1[i];
		delete[] dp2[i];
	}
	delete[] dp1;
	delete[] dp2;
	printf("%d %d\n", first, second);
	return 0;
}
#endif