//https://sites.google.com/a/chaoskey.com/algorithm/02/04
/*
【解题思路】：将2^k x 2^k的棋盘，先分成相等的四块子棋盘，其中特殊方格位于四个中的一个，构造剩下没特殊方格三个子棋盘，将他们中的也假一个方格设为特殊方格。如果是：

左上的子棋盘（若不存在特殊方格）----则将该子棋盘右下角的那个方格假设为特殊方格
右上的子棋盘（若不存在特殊方格）----则将该子棋盘左下角的那个方格假设为特殊方格
左下的子棋盘（若不存在特殊方格）----则将该子棋盘右上角的那个方格假设为特殊方格
右下的子棋盘（若不存在特殊方格）----则将该子棋盘左上角的那个方格假设为特殊方格

当然上面四种，只可能且必定只有三个成立，那三个假设的特殊方格刚好构成一个L型骨架，我们可以给它们作上相同的标记。这样四个子棋盘就分别都和原来的大棋盘类似，我们就可以用递归算法解决。http://note.youdao.com/noteshare?id=d93199129c29ac8622a77faf07ea0267
*/

#include<iostream>
using namespace std;
int tile = 1;
int board[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size) //dr,dc是特殊位置 tr,tc起点
{
	if (size == 1)
		return;
	int t = tile++; //t相同表示  一个图覆盖,
	//主要利用了，覆盖的是3个方格组成的图像，那么，分为4个块，每个块里面最多只有一个，另外3个就构成一个，
	int s = size / 2;
	if (dr < tr + s && dc < tc + s) //特殊点在第一个块里面，，，，
		chessBoard(tr, tc, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s - 1] = t;//不在第一个块，那右下角标记
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);//右下角作为新的快的特殊点
	}
	if (dr < tr + s && dc >= tc + s) //在第二块快，左上角那个块
		chessBoard(tr, tc + s, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s] = t;
		chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}

	if (dr >= tr + s && dc < tc + s) //左下角块里面，，
		chessBoard(tr + s, tc, dr, dc, s);
	else
	{
		board[tr + s][tc + s - 1] = t;
		chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s)//右下角第四个块里面，，，
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
	cout << "输入棋盘的size(大小必须是2的n次幂): ";
	cin >> size;
	int index_x, index_y;
	cout << "输入特殊方格位置的坐标: ";
	cin >> index_x >> index_y;
	chessBoard(0, 0, index_x, index_y, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << board[i][j] << "\t";
		cout << endl;
	}
}