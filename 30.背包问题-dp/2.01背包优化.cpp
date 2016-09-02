

//http://www.hawstein.com/posts/dp-knapsack.html
#define  _CRT_SECURE_NO_WARNINGS

#include "iostream"
#include "string"
#include "cctype"
#include "new"

enum {
	NUM = 1,
	MAX=100
};
using namespace std;

int cover[MAX];

int main(){
	freopen("data.txt", "r", stdin);
	freopen("data.out", "w", stdout);
	int n, C, V = 0, W = 0;
	//while (scanf("%d %d", &n, &C) != EOF){
	while (cin >> n >> C){
		int* d = new int[C + 1];
		memset(d, 0, (C + 1)*sizeof(int));

		for (int i = 0; i <= n; ++i){
			if (i > 0)
				cin >> V >> W;
			for (int j = C; j >= 0; --j){
				if (j >= V && i > 0)	
					d[j] = d[j] > d[j - V] + W ? d[j] : d[j - V] + W;
			}
		}
		printf("%d\n", d[C]);
		delete[] d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}