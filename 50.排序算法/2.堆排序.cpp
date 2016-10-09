#if 0
#include <iostream>
#include <algorithm>
#include "vector"
#include "map"
#include "type_traits"
using namespace std;

void max_heapify(int arr[], int start, int end) {
	//建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子節點指標在範圍內才做比較
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	//初始化，i從最後一個父節點開始調整
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	std::map<string, int> smap;
	string str = "abc";
	smap[str] = 2;
	cout << "get.map==" << smap["abc"]  << "...." << endl;
	std::map<int, int> mapints;
	mapints[1] = 1;
	mapints[3] = 3;
	std::vector<string> vints;
	for (auto imap : smap){
		vints.push_back(imap.first);
		//cout << "..."  << imap.first << endl;
		cout << "...type traits" << is_pointer<int>::value << endl;
	}
	for (auto it : vints)
	{
		//cout << ">>>>>>>>>>>>" << it <<endl;
	}
	int len = (int) sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
/*

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void doHeap(vector<int>& vec, int p, int len){
    int child = 2*p + 1;
    while(child <= len){
        if(child + 1 <= len && vec[child+1] > vec[child])
            ++child;
        if(vec[child] < vec[p])
            swap(vec[p], vec[child]);
            p = child;
            child = 2 * p + 1;
        
    }
}

void heapSort(vector<int>& vec, int len){
    if(len < 1 )
        return ;
    for(int i=len/2 - 1; i>=0; --i)
        doHeap(vec, i, len-1);
    for(int j=len-1; j>0; --j){
        swap(vec[j], vec[0]);
        doHeap(vec, 0, j);
    }
    
}
int main(){
    vector<int> vec{1,2,3,4,5,6,7};
    for_each(vec.begin(), vec.end(), [](int it){cout << "--" << it; });
    heapSort(vec, 7);
    for_each(vec.begin(), vec.end(), [](int it){cout << "--" << it; });

    return 0;
}
*/
#endif