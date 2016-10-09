#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int days[13] = { 0, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool run(int year){
	if (year % 4 != 0)
		return false;
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}
void main(){
	int year, month, day, hour, minute, second;
	int data[6];
	char in[20];
	while (cin.getline(in, 20)){
		int i = 0;
		char *pch = strtok(in, "/ :");
		while (pch != '\0'){
			data[i++] = atoi(pch);
			pch = strtok('\0', "/ :");
		}
		year = data[0];
		month = data[1];
		day = data[2];
		hour = data[3];
		minute = data[4];
		second = data[5];
		while (1){
			if (second < 59){
				second++;
				break;
			}
			second = 0;
			if (minute < 59){
				minute++;
				break;
			}
			minute = 0;
			if (hour < 23){
				hour++;
				break;
			}
			hour = 0;
			if (month == 2){
				if (run(year)){
					if (day < 29){
						day++;
						break;
					}
				}
				if (day < 28){
					day++;
					break;
				}
			}
			else if (day < days[month]){
				day++;
				break;
			}
			day = 1;
			if (month < 12){
				month++;
				break;
			}
			month = 1;
			year++;
			break;
		}
		printf("%d/%02d/%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
	}
	return;
}
#endif