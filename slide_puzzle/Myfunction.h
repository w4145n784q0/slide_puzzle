#pragma once  
const int BOARD_WIDTH = 4;
const int BOARD_HEIGHT = 4;
const int BLANK_POS = 16;

//タイルでの位置
struct Board
{
	int tile[BOARD_HEIGHT][BOARD_WIDTH];
};

//整数で2次元配列のインデックスや整数座標を表す構造体
struct Position
{
	int x, y;
};

//関数の宣言

//numの番号をさがしてタイルの二次元配列のインデックスをPosition型｛,｝で返す
//_num　変換前の整数
//_board タイルの位置を参照渡し
//return Position型で整数の場所を返す
Position SearchTileNum(int num, Board& _board);

//指定した番号は動かせるタイルか
//_num　変換前の整数
//_board タイルの位置を参照渡し
//return 動かせるかTrueかFalseで返す
bool CanMoveIt(int _num, Board& _board);

//タイル移動(その番号と空白セルを交換する)関数
//_num　変換前の整数
//_board タイルの位置を参照渡し
void SwapTile(int _num, Board& _board);

//問題作成関数 規定回数タイルを入れ替える
//_board タイルの位置を参照渡し
void MakeProblem(Board& _board);

//初期化関数　1~16までの数字を代入
//_board タイルの位置を参照渡し
void InitBoard(Board& _board);

//表示関数　コンソールに数字・空白を表示
//_board タイルの位置を参照渡し
void PrintBoard(Board& _board);

//クリア判定　タイルの位置が合っている分をカウント
//_board タイルの位置を参照渡し
int ClearJudgement(Board& _board);