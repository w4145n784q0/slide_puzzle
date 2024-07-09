#pragma once  
const int BOARD_WIDTH = 4;
const int BOARD_HEIGHT = 4;
const int BLANK_POS = 16;

//�^�C���ł̈ʒu
struct Board
{
	int tile[BOARD_HEIGHT][BOARD_WIDTH];
};

//������2�����z��̃C���f�b�N�X�␮�����W��\���\����
struct Position
{
	int x, y;
};

//�֐��̐錾

//num�̔ԍ����������ă^�C���̓񎟌��z��̃C���f�b�N�X��Position�^�o,�p�ŕԂ�
//_num�@�ϊ��O�̐���
//_board �^�C���̈ʒu���Q�Ɠn��
//return Position�^�Ő����̏ꏊ��Ԃ�
Position SearchTileNum(int num, Board& _board);

//�w�肵���ԍ��͓�������^�C����
//_num�@�ϊ��O�̐���
//_board �^�C���̈ʒu���Q�Ɠn��
//return �������邩True��False�ŕԂ�
bool CanMoveIt(int _num, Board& _board);

//�^�C���ړ�(���̔ԍ��Ƌ󔒃Z������������)�֐�
//_num�@�ϊ��O�̐���
//_board �^�C���̈ʒu���Q�Ɠn��
void SwapTile(int _num, Board& _board);

//���쐬�֐� �K��񐔃^�C�������ւ���
//_board �^�C���̈ʒu���Q�Ɠn��
void MakeProblem(Board& _board);

//�������֐��@1~16�܂ł̐�������
//_board �^�C���̈ʒu���Q�Ɠn��
void InitBoard(Board& _board);

//�\���֐��@�R���\�[���ɐ����E�󔒂�\��
//_board �^�C���̈ʒu���Q�Ɠn��
void PrintBoard(Board& _board);

//�N���A����@�^�C���̈ʒu�������Ă��镪���J�E���g
//_board �^�C���̈ʒu���Q�Ɠn��
int ClearJudgement(Board& _board);