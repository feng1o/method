#if 0

#include "iostream"
#include "vector"
#include "array"

using namespace std;

const int  ca = 10;
int ia = 10;

const unsigned int ra(){
	return 10u;
}
//struct x{
//	constexpr int cera(){ return 10; }
//};
void merge(vector<int> &vec, int lhs, int mid, int rhs){
	//constexpr int i = 1;
	const int aaa = 2; 
//	array<int, aaa>  tmpx;
	vector<int> tmp; //归并排序要占用空间，，所以
	int j = mid + 1;             //此处应该是+1，，不可从mid，，因为递归中的条件问题
	int k = lhs;
	//for (int i = 0; i < rhs - lhs + 1; ++i)
	while (k<= mid && j <= rhs)
	{
		cout << ">....\n";
		if (vec[k] < vec[j] && k <= mid)
			tmp.push_back(vec[k++]);
		else 
			tmp.push_back(vec[j++]);
	}
	while (k <= mid)  tmp.push_back(vec[k++]);
	while (j <= rhs)   tmp.push_back(vec[j++]);
	//vec.clear();
	//vec.assign(tmp.begin(), tmp.end());
	//vec.erase(lhs, rhs + 1);
	vec.erase(vec.begin() + lhs, vec.begin() + rhs + 1);
	vec.insert(vec.begin() + lhs, tmp.begin(), tmp.end());
	//for (int i = 0; i < tmp.size(); ++i)
		//vec[lhs++] = tmp[i];
}
void mergeSort(vector<int> &vec, int lhs, int rhs){
	if (vec.size() <= 1)
		return;
	int mid = (lhs + rhs) / 2;
	if (lhs < rhs)
	{
		cout << "..." << endl;
		mergeSort(vec, lhs, mid);
		mergeSort(vec, mid + 1, rhs);
		merge(vec, lhs, mid, rhs);
	}
}
int main(){
	vector<int> vec{ 1, 23, 263, 3, 73, 23, 2, 265, 0, -23, 2355 };
	mergeSort(vec, 0, vec.size() - 1);
	for (auto it: vec)
	{
		cout << " " << it << endl;
	}
	return 0;
}
#endif