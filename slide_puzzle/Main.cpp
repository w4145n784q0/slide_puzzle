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
		cout << "どこをずらしますか(番号を指定)：";
		cin >> num;
		SwapTile(num, myboard);
		cout << "結果：" << endl;
		PrintBoard(myboard);
		if (ClearJudgement(myboard) == 16)//すべてのタイルの位置が揃ったら
		{
			break;
		}
	}
	cout << "クリアおめでとう！！！" << endl;
	return 0;
}