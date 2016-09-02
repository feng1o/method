#if 0
http://blog.csdn.net/wdxin1322/article/details/9501163
#include <stdio.h>  
#include <iostream>  

using namespace std;

void makeChange(int values[], int types, int total, int coinUsed[], int cointTrack[]){
	coinUsed[0] = 0;
	cointTrack[0] = 0;
	for (int i = 1; i <= total; i++){
		int mincoin = i; //Ϊi����Ǯ�������i��1Ԫ���꣬�������Ҹ�����Ϊ��ʱ�����
		int lastin = 0;
		for (int j = 0; j < types; j++){
			if (values[j] <= i){  //�����iС������
				if (coinUsed[i - values[j]] + 1 < mincoin){
					mincoin = coinUsed[i - values[j]] + 1; //���£�����ǰ��С�����ҵ���С��
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
	//Ӳ����ֵ  
	int value[] = { 1, 2, 5, 21, 25 };
	//Ӳ�������С  
	size_t size = sizeof(value) / sizeof(*value);
	//Ҫ�������  
	int money = 63;
	//����ÿ����ֵ��Ӧ��Сֵ����Ϊ0��λ���������ʼ�1  
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
        // ���ٿ���ȫ��ʹ��1Ԫ������
        int minChangeCount = dollars;
        int newChange = 1;

        for (int j = 0; j < changes.Length; j++)
        {
            if (changes[j] > dollars)
            {
                continue; // ����ʹ�ø�����������
            }

            // ���ʹ�����������������Ҫ����Ŀ��С
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