#if 0
//必须传入引用，，string也是...........
/*tip
1.传入的string也必须是地址或者引用。。。
2.从中间往两笔走，切记值，，，，，
3.最好还是使用 单边走，，q第一个种方法*/

#include<iostream>
#include<string>

using namespace std;
string quickSort(string& str, int begin, int end){  //如果希望传入的实参被修改，，必须引用，即使是string
	if (begin < end){
		char key = str[end];
		int lhs = begin - 1;
		for (int j = begin; j < end; ++j){
			if (str[j] <= key){
				++lhs;
				swap(str[lhs], str[j]);
			}
		}
		swap(str[lhs + 1], str[end]);
		quickSort(str, begin, lhs);
		quickSort(str, lhs + 2, end);
	}
	return str;
}
string quickSortch(char* str, int begin, int end){  //参数是ch会被传递回去，，，string不行，也就是不能修改原变量的值，，，，
	if (begin < end){
		char key = str[end];
		int lhs = begin - 1;
		for (int j = begin; j < end; ++j){
			if (str[j] <= key){
				++lhs;
				swap(str[lhs], str[j]);
			}
		}
		swap(str[lhs + 1], str[end]);
		quickSortch(str, begin, lhs);  //必须是lhs 不可-1
		quickSortch(str, lhs + 2, end);  //+1，+2搜是可以的
	}
	return str;
}
string quickSort3(string& str, int begin, int end){
	if (begin < end){
		int mid = (begin + end) / 2;
		char key = str[mid];
		int lhs = begin - 1;
		int rhs = end + 1;
		while (lhs < rhs){  //加了 <=就是错的。。。。。。。。。。。会导致越界或者死循环。。。。。。。。。。。。。。。。.............................
			while (lhs < rhs && str[++lhs] < key);
			while (lhs < rhs && str[--rhs] > key);
			std::swap(str[lhs], str[rhs]);
			cout << "..." << str << endl;
		}
		//quickSort(str, begin, lhs - 1);
		//quickSort(str, rhs + 1, end);
		quickSort(str, begin, lhs);
		quickSort(str, rhs, end);;
	}
	return str;
}

string quickSort2(string& str, int begin, int end){
	if (begin < end){
		char key = str[begin];
		int lhs = begin + 1;
		int rhs = end;
		while (lhs < rhs){                     //加了 <=就是错的。。。。。。。。。。。会导致越界或者死循环。。。。。。。。。。。。。。。。.......................
			while (lhs < rhs && str[lhs] <= key)  //判定 lhs 《 rhs必须的。。。。。。。。。。。。。。。。。。。。。。。。。。。。。.........................
				++lhs;
			while (rhs > lhs && str[rhs] > key)
				--rhs;
			swap(str[lhs], str[rhs]);
		}
		swap(str[begin], str[lhs - 1]); //必须是lhs-1,,,。。。。。。。。。。。。。。。。。。。。。。。。。
		quickSort(str, begin, lhs - 1);
		quickSort(str, lhs, end);
	}
	return str;

}

int main(){
	char ch[] = "cba";
	cout << quickSortch(ch, 0, strlen(ch) - 1) << endl;
	cout << ch << endl;//采用之处地string，，最后交换的并不是string本身，，，tip	
	cout << endl;
	string str;
	while (cin >> str){
		cout << quickSort3(str, 0, str.size() - 1) << endl;
		//cout << str << endl;//采用之处地string，，最后交换的并不是string本身，，，tip
	}
	return 0;
}
#endif