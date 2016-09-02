#if 0
http://blog.csdn.net/wdxin1322/article/details/9501163
#include <stdio.h>  
#include <iostream>  

using namespace std;

void makeChange(int values[], int types, int total, int coinUsed[], int cointTrack[]){
	coinUsed[0] = 0;
	cointTrack[0] = 0;
	for (int i = 1; i <= total; i++){
		int mincoin = i; //为i的零钱，最多有i张1元找完，，所以找个保存为暂时的最大
		int lastin = 0;
		for (int j = 0; j < types; j++){
			if (values[j] <= i){  //必须必i小才能用
				if (coinUsed[i - values[j]] + 1 < mincoin){
					mincoin = coinUsed[i - values[j]] + 1; //更新，，当前最小，，找到最小的
					lastin = values[j];
				}
			}
		}
		coinUsed[i] = mincoin;
		cointTrack[i] = lastin;
	}
	while (total > 0)
	{
		cout << cointTrack[total] << " ";
		total -= cointTrack[total];
	}
}

int main(int argc, char *argv[])
{
	//硬币面值  
	int value[] = { 1, 2, 5, 21, 25 };
	//硬币数组大小  
	size_t size = sizeof(value) / sizeof(*value);
	//要找零的数  
	int money = 63;
	//保存每个面值对应最小值，因为0号位置舍弃，故加1  
	int* coinsUsed = new int[money + 1];
	int* coinsTrack = new int[money + 1];
	makeChange(value, size, money, coinsUsed, coinsTrack);
}

/* cankao
public static void MakeChangeDynamically(int money, int[] changes, int[] changesUsed, int[] lastChange)
{
    changesUsed[0] = 0;
    lastChange[0] = 1;
    for (int dollars = 1; dollars <= money; dollars++)
    {
        // 至少可以全部使用1元来找零
        int minChangeCount = dollars;
        int newChange = 1;

        for (int j = 0; j < changes.Length; j++)
        {
            if (changes[j] > dollars)
            {
                continue; // 不能使用该数额来找零
            }

            // 如果使用这个数额来找所需要的数目更小
            if (changesUsed[dollars - changes[j]] + 1 < minChangeCount)
            {
                minChangeCount = changesUsed[dollars - changes[j]] + 1;
                newChange = changes[j];
            }
        }

        changesUsed[dollars] = minChangeCount;
        lastChange[dollars] = newChange;
    }
}
*/
#endif