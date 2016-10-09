#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cgreater(pair<int, int> pair_1, pair<int, int> pair_2){
	return pair_1.second > pair_2.second;
}

int main(){
	int n, m, tmp;
	cin >> n >> m;
	if (n <= 0 || m <= 0){
		cout << 0 << endl;
		return 0;
	}
	vector<int> Tables;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		Tables.push_back(tmp);
	}
	sort(Tables.begin(), Tables.end());
	vector<pair<int, int>> customer;
	pair<int, int> tpair;
	for (int i = 0; i < m; i++)
	{
		cin >> tpair.first;// ren
		cin >> tpair.second;  //Ǯ
		customer.push_back(tpair);
	}
	sort(customer.begin(), customer.end(), cgreater);
	/*for (auto it : customer)
	cout << "ren=" << it.first << " qian= " << it.second << endl;
	*/
	int max = 0;
	for (auto it = customer.begin(); it != customer.end(); it++){
		if (it->second > 0){
			if (Tables.empty())
				break;
			int size = it->first;
			if (size > Tables[Tables.size() - 1])
				continue;
			for (int i = 0; i < Tables.size(); ++i){
				if (Tables[i] >= size){
					max += it->second;
					Tables.erase(Tables.begin() + i);
					break;
				}
			}
			/*auto it2 = lower_bound(Tables.begin(), Tables.end(), size);
			//if (it2 == Tables.end())
			//	continue;
			Tables.erase(it2);
			max += it->second;*/
		}
	}
	cout << max << endl;
	return 0;
}
