#include<iostream>
#include "Myfunction.h"
using namespace std;


int main()
{	
	srand(static_cast<unsigned int>(time(nullptr)));
	Board myboard;
	InitBoard(myboard);
	PrintBoard(myboard);
	int num = 0;
	
	while (true)
	{
		cout << "�ǂ������炵�܂���(�ԍ����w��)�F";
		cin >> num;
		SwapTile(num, myboard);
		cout << "���ʁF" << endl;
		PrintBoard(myboard);
		if (ClearJudgement(myboard) == 16)//���ׂẴ^�C���̈ʒu����������
		{
			break;
		}
	}
	cout << "�N���A���߂łƂ��I�I�I" << endl;
	return 0;
}