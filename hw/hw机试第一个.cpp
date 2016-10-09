#if 0
//hw机试第一题吧["ab=c,c=e,e=ek"]，转成[[ab,c],[c,e]...]];
#include "iostream"
#include "string"
#include "vector"
using namespace  std;

int main(){
	string str;
	vector<string> vec;

	while (getline(cin, str)){
		int lhs = 0;
		int start = 0;
		int size = str.size();

		int pos = -1;
		while (1){
			 pos = str.find_first_of("=,", start);
				//cout << "pos==" << pos << endl;
			if (pos != string::npos){
				string substr = str.substr(lhs, pos-lhs);
				vec.push_back(substr);
				//substr.clear();
				lhs = pos + 1;
				start = pos + 1;
			}
			else
				break;
		}
		vec.push_back(str.substr(lhs, str.size() - lhs));
		cout << "[";
		for (int i = 0; i < vec.size(); ++i)
		{
			if (i % 2 == 0)
				cout << "[" << vec[i] << ",";
			else if (i != vec.size() - 1 && i % 2 == 1)
				cout << vec[i] << "]" << ",";
			else if (i == vec.size() - 1)
				cout << vec[i] << "]";
		}
		cout << "]" << endl;
	}

	return 0;
}
#endif