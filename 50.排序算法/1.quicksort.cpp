#if 0
//���봫�����ã���stringҲ��...........
/*tip
1.�����stringҲ�����ǵ�ַ�������á�����
2.���м��������ߣ��м�ֵ����������
3.��û���ʹ�� �����ߣ���q��һ���ַ���*/

#include<iostream>
#include<string>

using namespace std;
string quickSort(string& str, int begin, int end){  //���ϣ�������ʵ�α��޸ģ����������ã���ʹ��string
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
string quickSortch(char* str, int begin, int end){  //������ch�ᱻ���ݻ�ȥ������string���У�Ҳ���ǲ����޸�ԭ������ֵ��������
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
		quickSortch(str, begin, lhs);  //������lhs ����-1
		quickSortch(str, lhs + 2, end);  //+1��+2���ǿ��Ե�
	}
	return str;
}
string quickSort3(string& str, int begin, int end){
	if (begin < end){
		int mid = (begin + end) / 2;
		char key = str[mid];
		int lhs = begin - 1;
		int rhs = end + 1;
		while (lhs < rhs){  //���� <=���Ǵ�ġ����������������������ᵼ��Խ�������ѭ����������������������������������.............................
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
		while (lhs < rhs){                     //���� <=���Ǵ�ġ����������������������ᵼ��Խ�������ѭ����������������������������������.......................
			while (lhs < rhs && str[lhs] <= key)  //�ж� lhs �� rhs����ġ���������������������������������������������������������.........................
				++lhs;
			while (rhs > lhs && str[rhs] > key)
				--rhs;
			swap(str[lhs], str[rhs]);
		}
		swap(str[begin], str[lhs - 1]); //������lhs-1,,,��������������������������������������������������
		quickSort(str, begin, lhs - 1);
		quickSort(str, lhs, end);
	}
	return str;

}

int main(){
	char ch[] = "cba";
	cout << quickSortch(ch, 0, strlen(ch) - 1) << endl;
	cout << ch << endl;//����֮����string������󽻻��Ĳ�����string��������tip	
	cout << endl;
	string str;
	while (cin >> str){
		cout << quickSort3(str, 0, str.size() - 1) << endl;
		//cout << str << endl;//����֮����string������󽻻��Ĳ�����string��������tip
	}
	return 0;
}
#endif