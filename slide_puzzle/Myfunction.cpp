#include<iostream>;
#include "Myfunction.h"  //�֐��̒�`

using namespace std;

Position SearchTileNum(int _num, Board& _board)
{
	Position p = { -1,-1 };//�G���[�p

	if (_num < 1 || 16 < _num)
		return p;
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			if (_num == _board.tile[j][i])//_num����������
			{
				p = { i,j };//Position�^(x,y)�ŕԂ�
				return (p);
			}
		}
	}
	return(p);
}

bool CanMoveIt(int _num, Board& _board)
{
	Position blank = SearchTileNum(BLANK_POS, _board);//BLANK_POS=16
	Position moveTile = SearchTileNum(_num, _board);//�ԍ�_num�̓����Ă���^�C���̃C���f�b�N�X���擾
	if (blank.x == -1 || moveTile.x == -1) return false;
	int dist = (blank.x - moveTile.x) * (blank.x - moveTile.x) + (blank.y - moveTile.y) * (blank.y - moveTile.y);//blank��movetile�̃}���n�b�^��������2����v�Z
	if (dist == 1)//������1�Ȃ�)
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
	Position blank = SearchTileNum(BLANK_POS, _board);//BLANK_POS���T�[�`
	Position moveTile = SearchTileNum(_num, _board);//_num���T�[�`

	if (blank.x == -1 || moveTile.x == -1)
		return;
	if (CanMoveIt(_num, _board) == true)
	{
		std::swap(_board.tile[moveTile.y][moveTile.x], _board.tile[blank.y][blank.x]);
	}
	else
	{
		cout << "�����͓������Ȃ�" << endl;
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
		while (true)//��������^�C���𔭌�����܂Ń����_���Ń^�C����I��
		{
			int num = rand() % 15 + 1;
			if (CanMoveIt(num, _board) == true)
			{
				p = SearchTileNum(num, _board);
				break;
			}
		}
		std::swap(_board.tile[b.y][b.x], _board.tile[p.y][p.x]);//num�̃^�C�����ړ�
	}
}
void InitBoard(Board& _board)
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			_board.tile[j][i] = j * BOARD_WIDTH + i + 1;//�����珇��1�`16�܂ł���
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
			if (j * BOARD_WIDTH + i + 1 == _board.tile[j][i])//�^�C���̐��l�Ƃ��̈ʒu�����v������
			{
				count++;
			}
		}
	}
	return(count);
}