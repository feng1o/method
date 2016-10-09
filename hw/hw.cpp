#if 0
//http://blog.csdn.net/su20145104009/article/details/51279911

#include "iostream"
#include "vector"

using namespace  std;

void doDfs(vector<int> vec, int x, int count, int result, int& sum)
{
	if (count > 8)
		return;
	vec[count] = x;
	if (count == 8)
	{
		int num = 1;
		int currentSum = 0;
		int tmpSum = 1;
		int i = 1;
		for (i = 1; i < 9; i++)
		{
			if (vec[i] == 2)
				tmpSum = tmpSum * 10 + (++num);
			else
				break;
		}
		while (++num <= 9)
		{
			int op = vec[i];
			currentSum = num;
			for (int j = i + 1; j < 9; j++)
			{
				if (vec[j] == 2)
					currentSum = currentSum * 10 + (++num);
				else
				{
					i = j;
					break;
				}
			}
			if (op == 0)
				tmpSum += currentSum;
			else if (op == 1)
				tmpSum -= currentSum;
		}
		if (tmpSum == result)
		{
			sum++;
		}
		return;
	}
	doDfs(vec, 0, count + 1, result, sum);  
	doDfs(vec, 1, count + 1, result, sum);  
	doDfs(vec, 2, count + 1, result, sum);  
}
int main()
{
	int result;
	while (cin >> result)
	{
		vector<int> vec(9, -1);
		int sum = 0;
		doDfs(vec, 0, 0, result, sum);
		cout << sum << endl;
	}
}
#endif

#if 0
#include "iostream"
#include "vector"

using namespace std;

int doDfs(vector<int> vec, int sum, int result, int flag2, int index){
	if (index > 8)
		return 0;
	vec[index] = flag2;
	if (index == 8){
		int last = 1;
		bool flag = true;
		for (int i = 0; i < 8; ++i)
		{
			if (vec[i] == 2){
				last *= 10;
				last += i + 2;
				continue;
			}
			else if (vec[i] == 0){ //+
				if (flag)
					sum += last;
				else
					sum -= last;
				last = i + 2;
				flag = true;
			}
			else if (vec[i] == 1)
			{
				if (flag)
					sum += last;
				else
					sum -= last;
				flag = false;
				last = i + 2;
			}
		}
		if (sum == result)
			return 1;
		else
			return 0;
	}

	return doDfs(vec, sum, result, 0, index+1) + doDfs(vec, sum, result, 1, index+1) + doDfs(vec, sum, result, 2, index+1);
}

int main(){
	int result;
	while (cin >> result){
		int sum = 0;
		int index = 0;
		int flag = 0;
		int count = 0;
		vector<int> vec(8, -1);
		cout << doDfs(vec, sum, result, flag, index) << endl;
	}

	return 0;
}
#endif