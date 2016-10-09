#if 0
//http://www.nowcoder.com/practice/8380c8cf28954a188362206b1991b5d6?tpId=8&tqId=11038&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking

class Permutation {
public:
	vector<string> getPermutation(string A) {
		// write code here       
		vector<string> ans = deal(A, 0, A.size() - 1);
		sort(ans.begin(), ans.end(), greater<string>());
		return ans;
	}
	vector<string> deal_error(string str, int b, int e){
		vector<string> svec;
		if (str.empty() || b < 0 || e >= str.size())
			return svec;
		if (b == e){
			svec.push_back(str);
			return svec;
		}
		for (int i = b; i <= e; ++i){
			swap(str[i], str[b]);
			svec = deal(str, b + 1, e);
			swap(str[i], str[b]);
		}
		return svec;
	}

	vector<string> deal(string str, int b, int e){
		vector<string> svec;
		if (str.empty() || b < 0 || e >= str.size())
			return svec;
		if (b == e){
			svec.push_back(str);
			return svec;
		}
		for (int i = b; i <= e; ++i){
			swap(str[i], str[b]);
			vector<string> tmp;
			tmp = deal(str, b + 1, e);
			swap(str[i], str[b]);
			svec.insert(svec.end(), tmp.begin(), tmp.end());
		}
		return svec;
	}
};
#endif