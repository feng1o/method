#include "stdlib.h"
#include "stdio.h"

class A {
public:
	int n;
	void print(){ cout << ".."; };
};

int lps_bl(char str[], int len){
	if (str == NULL || len <= 0){
		return 0;
	}
	int i, j;
	int start, end;
	int max_lps = 0;
	for (i = 0; i < len; i++){
		for (j = 1; j < len; j++){
			start = 0;
			end = j - 1;
			while (start <= end && str[start] == str[end]){
				start++;
				end--;
			}
			if (start >= end){
				if (j > max_lps){
					max_lps = j;
				}
			}
		}
	}
	printf("lps_bl:%d\n", max_lps);
	return max_lps;
}

int main(){
	//A* a = 2;
	//a->print();
	char *str = "abaef";
	lps_bl(str, 5);
	return 0;
}