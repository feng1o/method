//https://sites.google.com/a/chaoskey.com/algorithm/02/04
/*
������˼·������2^k x 2^k�����̣��ȷֳ���ȵ��Ŀ������̣��������ⷽ��λ���ĸ��е�һ��������ʣ��û���ⷽ�����������̣��������е�Ҳ��һ��������Ϊ���ⷽ������ǣ�

���ϵ������̣������������ⷽ��----�򽫸����������½ǵ��Ǹ��������Ϊ���ⷽ��
���ϵ������̣������������ⷽ��----�򽫸����������½ǵ��Ǹ��������Ϊ���ⷽ��
���µ������̣������������ⷽ��----�򽫸����������Ͻǵ��Ǹ��������Ϊ���ⷽ��
���µ������̣������������ⷽ��----�򽫸����������Ͻǵ��Ǹ��������Ϊ���ⷽ��

��Ȼ�������֣�ֻ�����ұض�ֻ��������������������������ⷽ��պù���һ��L�͹Ǽܣ����ǿ��Ը�����������ͬ�ı�ǡ������ĸ������̾ͷֱ𶼺�ԭ���Ĵ��������ƣ����ǾͿ����õݹ��㷨�����http://note.youdao.com/noteshare?id=d93199129c29ac8622a77faf07ea0267
*/

#include<iostream>
using namespace std;
int tile = 1;
int board[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size) //dr,dc������λ�� tr,tc���
{
	if (size == 1)
		return;
	int t = tile++; //t��ͬ��ʾ  һ��ͼ����,
	//��Ҫ�����ˣ����ǵ���3��������ɵ�ͼ����ô����Ϊ4���飬ÿ�����������ֻ��һ��������3���͹���һ����
	int s = size / 2;
	if (dr < tr + s && dc < tc + s) //������ڵ�һ�������棬������
		chessBoard(tr, tc, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s - 1] = t;//���ڵ�һ���飬�����½Ǳ��
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);//���½���Ϊ�µĿ�������
	}
	if (dr < tr + s && dc >= tc + s) //�ڵڶ���죬���Ͻ��Ǹ���
		chessBoard(tr, tc + s, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s] = t;
		chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}

	if (dr >= tr + s && dc < tc + s) //���½ǿ����棬��
		chessBoard(tr + s, tc, dr, dc, s);
	else
	{
		board[tr + s][tc + s - 1] = t;
		chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s)//���½ǵ��ĸ������棬����
		chessBoard(tr + s, tc + s, dr, dc, s);
	else
	{
		board[tr + s][tc + s] = t;
		chessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}

void main()
{
	int size;
	cout << "�������̵�size(��С������2��n����): ";
	cin >> size;
	int index_x, index_y;
	cout << "�������ⷽ��λ�õ�����: ";
	cin >> index_x >> index_y;
	chessBoard(0, 0, index_x, index_y, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << board[i][j] << "\t";
		cout << endl;
	}
}