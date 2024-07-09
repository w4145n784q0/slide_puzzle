#include<iostream>;
#include "Myfunction.h"  //関数の定義

using namespace std;

Position SearchTileNum(int _num, Board& _board)
{
	Position p = { -1,-1 };//エラー用

	if (_num < 1 || 16 < _num)
		return p;
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (_num == _board.tile[j][i])//_numを見つけたら
			{
				p = { i,j };//Position型(x,y)で返す
				return (p);
			}
		}
	}
	return(p);
}

bool CanMoveIt(int _num, Board& _board)
{
	Position blank = SearchTileNum(BLANK_POS, _board);//BLANK_POS=16
	Position moveTile = SearchTileNum(_num, _board);//番号_numの入っているタイルのインデックスを取得
	if (blank.x == -1 || moveTile.x == -1) return false;
	int dist = (blank.x - moveTile.x) * (blank.x - moveTile.x) + (blank.y - moveTile.y) * (blank.y - moveTile.y);//blankとmovetileのマンハッタン距離の2乗を計算
	if (dist == 1)//距離が1なら)
	{
		return true;
	}
	else
	{
		return false;
	}

}
void SwapTile(int _num, Board& _board)
{
	Position blank = SearchTileNum(BLANK_POS, _board);//BLANK_POSをサーチ
	Position moveTile = SearchTileNum(_num, _board);//_numをサーチ

	if (blank.x == -1 || moveTile.x == -1)
		return;
	if (CanMoveIt(_num, _board) == true)
	{
		std::swap(_board.tile[moveTile.y][moveTile.x], _board.tile[blank.y][blank.x]);
	}
	else
	{
		cout << "そこは動かせない" << endl;
		return;
	}
}
void MakeProblem(Board& _board)
{
	int level = 50;

	Position b = SearchTileNum(BLANK_POS, _board);
	Position p;
	for (int i = 0; i < level; i++)
	{
		while (true)//動かせるタイルを発見するまでランダムでタイルを選択
		{
			int num = rand() % 15 + 1;
			if (CanMoveIt(num, _board) == true)
			{
				p = SearchTileNum(num, _board);
				break;
			}
		}
		std::swap(_board.tile[b.y][b.x], _board.tile[p.y][p.x]);//numのタイルを移動
	}
}
void InitBoard(Board& _board)
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			_board.tile[j][i] = j * BOARD_WIDTH + i + 1;//左から順に1～16までを代入
		}
	}
	MakeProblem(_board);
}
void PrintBoard(Board& _board)
{
	string ruledLine = "+--+--+--+--+";
	cout << ruledLine << endl;
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (_board.tile[j][i] != BLANK_POS)
			{
				if (_board.tile[j][i] < 10)
					cout << "| " << _board.tile[j][i];
				else
					cout << "|" << _board.tile[j][i];
			}
			else
			{
				cout << "|  ";
			}
		}
		cout << "|" << endl;
		cout << ruledLine << endl;
	}

}
int ClearJudgement(Board& _board)
{
	int count = 0;
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (j * BOARD_WIDTH + i + 1 == _board.tile[j][i])//タイルの数値とその位置が合致したら
			{
				count++;
			}
		}
	}
	return(count);
}