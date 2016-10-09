#if 0
#include <iostream>
#include <algorithm>
#include "vector"
#include "map"
#include "type_traits"
using namespace std;

void max_heapify(int arr[], int start, int end) {
	//���������cָ�˺��ӹ��cָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //���ӹ��cָ���ڹ����Ȳ������^
		if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱ��^�ɂ��ӹ��c��С���x������
			son++;
		if (arr[dad] > arr[son]) //��������c����ӹ��c�����{���ꮅ��ֱ����������
			return;
		else { //��t���Q���Ӄ������^�m�ӹ��c�͌O���c���^
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	//��ʼ����i������һ�������c�_ʼ�{��
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	//�Ȍ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ�����Q���ُ����{��(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ�������ꮅ
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