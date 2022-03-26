#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

//"FIELD_SIZE" - ������ ��������������� ����,
//�� ���������� ����� ������, �� ����������� � ������� �������
#define FIELD_SIZE 10
#define TRUE_FIELD_SIZE (FIELD_SIZE + 2)
#define STICK_SIZE 3
#define COUNT_OF_OBJECTS 5

using namespace std;

class Object
{
private:
	int area[STICK_SIZE][STICK_SIZE];	//������� "object", ��������������� "object"
	int x, y;	//���������� ������ �������� ���� ������� "Object", ������������ ������ �������� ���� "Field"

public:
	//"number" - ����� �������������� ������.
	//"area" ��������������� "TrueArea". ����� � ������
	Object(int Ay, int Ax, int number)
	{
		//����� "COUNT_OF_OBJECTS" �����
		int objects[COUNT_OF_OBJECTS][STICK_SIZE][STICK_SIZE] = {
			{ { 0, 0, 0 },
			{ 1, 1, 1 },
			{ 0, 0, 0 }, },

			{ { 0, 1, 0 },
			{ 1, 1, 1 },
			{ 0, 0, 0 }, },

			{ { 1, 1, 0 },
			{ 1, 1, 0 },
			{ 0, 0, 0 }, },

			{ { 1, 0, 0 },
			{ 1, 1, 1 },
			{ 0, 0, 0 }, },

			{ { 0, 1, 1 },
			{ 1, 1, 0 },
			{ 0, 0, 0 }, },
		};


		for (int Iy = 0; Iy < STICK_SIZE; Iy++){	// "Iy" ������ ��� "y" ��� ������� ��� ����������
			for (int Ix = 0; Ix < STICK_SIZE; Ix++)
			{
				//������������� ������ ��� ������� "number"
				area[Iy][Ix] = objects[number][Iy][Ix];
			}
		}

		y = Ay;
		x = Ax;
	}

	//���������� ���������� 
	int GetY()
	{
		return y;
	}
	int GetX()
	{
		return x;
	}


	//������������� ����������
	void SetY(int Ay)
	{
		y = Ay;
	}
	void SetX(int Ax)
	{
		x = Ax;
	}

	//���������� ������ �������
	int GetSize()
	{
		return STICK_SIZE;
	}

	//������ � ����. "y" - ������, "x" - �������
	int GetCell(int y, int x)
	{
		return area[y][x];
	}

	//���������� "y" �� 1
	void Fall() { y++; }

	//����� "x" 
	void xRightShift()
	{
		x++;
	}
	void xLeftShift()
	{
		x--;
	}

	//������� ����� (����������������)
	void TurnRight()
	{
		int area_transp[STICK_SIZE][STICK_SIZE];

		//�������� "area_transp" - ����������������� area
		for (int y = 0; y < STICK_SIZE; y++){
			for (int x = 0; x < STICK_SIZE; x++)
			{
				area_transp[y][x] = area[(STICK_SIZE - 1) - x][y];
			}
		}

		//������������ � "area" "area_transp"
		for (int y = 0; y < STICK_SIZE; y++){
			for (int x = 0; x < STICK_SIZE; x++)
			{
				area[y][x] = area_transp[y][x];
			}
		}
	}
	void TurnLeft()
	{
		int area_transp[3][3];

		//�������� "area_transp" - ����������������� area
		for (int y = 0; y < STICK_SIZE; y++){
			for (int x = 0; x < STICK_SIZE; x++)
			{
				area_transp[y][x] = area[x][(STICK_SIZE - 1) - y];
			}
		}

		//������������ � "area" "area_transp"
		for (int y = 0; y<STICK_SIZE; y++){
			for (int x = 0; x<STICK_SIZE; x++)
			{
				area[y][x] = area_transp[y][x];
			}
		}
	}
};
//-----------------------------------------------------------------------------------------

class Field
{
private:
	int area[TRUE_FIELD_SIZE][TRUE_FIELD_SIZE];	//������� ����. ��������������� ����

public:
	//"area" ��������������� "TrueArea". ����� � ������
	Field()
	{
		int TrueArea[TRUE_FIELD_SIZE][TRUE_FIELD_SIZE]{
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }, };

		for (int y = 0; y < TRUE_FIELD_SIZE; y++){
			for (int x = 0; x < TRUE_FIELD_SIZE; x++)
			{
				area[y][x] = TrueArea[y][x];
			}
		}
	}

	//������ � ����. "y" - ������, "x" - �������
	void SetCell(int y, int x, char value)
	{
		area[y][x] = value;
	}

	//������ � ����. "y" - ������, "x" - �������
	int GetCell(int y, int x)
	{
		return area[y][x];
	}

	//���������� �������� ������ �������
	int GetSize()
	{
		return TRUE_FIELD_SIZE;
	}

	//����� ������� � �������. ��� �������
	void Print_area()
	{
		for (int y = 0; y < FIELD_SIZE; y++){
			for (int x = 0; x < FIELD_SIZE; x++)
			{
				cout << area[y][x] << ' ';
			}
			cout << endl;
		}
	}

};
//-----------------------------------------------------------------------------------------

//���������� � "object", ���� ���������� � "field"
int x_from_Field_to_Stick(int FieldX, Object object)
{
	return FieldX - object.GetX();
}
int y_from_Field_to_Stick(int FieldY, Object object)
{
	return FieldY - object.GetY();
}

//���������� � "field", ���� ���������� � "object"
int x_from_Stick_to_Field(int StickX, Object object)
{
	return object.GetX() + StickX;
}
int y_from_Stick_to_Field(int StickY, Object object)
{
	return object.GetY() + StickY;
}


//����������� "object" �� ����
//������������ ������ ��������� ������
void displayStick(Field field, Object object)
{
	for (int y = 0; y < field.GetSize(); y++){	//������ �� ������� Field
		for (int x = 0; x < field.GetSize(); x++)
		{
			int stickY = object.GetY();
			int stickX = object.GetX();
			//���������� ������� �� field ������������ ������� object
			int stickCell = object.GetCell(y_from_Field_to_Stick(y, object), x_from_Field_to_Stick(x, object));

			if ((stickY <= y) && (y <= stickY + 2) && 	//���� ���������� � ������� object
				(stickX <= x) && (x <= stickX + 2) &&
				(stickCell == 1))	//� ���� ������ ����� 1
			{
				cout << stickCell << ' ';
			}
			else if (field.GetCell(y, x) != 0){
				cout << field.GetCell(y, x) << ' ';
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl;
}

//�������
//-----------------------------------------------------------------------------------------

//������ �� "object" c ������� ������� ����. ������� ����� �����, ����� ������ ������.
//���� �������� ������ � "object" �� ��������� 1 � ��� ���� ������� ���� ������ �� �������� 1, �� ������� 0
//��� ���� "object" �� ���
bool canFall(Field field, Object object)
{
	for (int x = object.GetSize() - 1; x >= 0; x--){
		for (int y = object.GetSize() - 1; y >= 0; y--)
		{
			int CellUnder = field.GetCell(y_from_Stick_to_Field(y + 1, object), x_from_Stick_to_Field(x, object));
			if (object.GetCell(y, x) == 1)
			{
				//���� "������ ���" = 1, ��� ���� ������ �� ��� 
				if (CellUnder == 1 || CellUnder == 2)
				{
					return 0;
				}
				break;	//���� ������ = 1, �� ���������� ���� �������
			}
		}
	}
	return 1; //�� �������
}

bool canRightShift(Field field, Object object)
{
	for (int x = object.GetSize() - 1; x >= 0; x--){
		for (int y = object.GetSize() - 1; y >= 0; y--)
		{
			int RightCell = field.GetCell(y_from_Stick_to_Field(y, object), x_from_Stick_to_Field(x + 1, object));
			if (object.GetCell(y, x) == 1)
			{
				//���� "������ ������" = 1, ��� ���� ������ �������� � ����� 
				if (RightCell == 1 || RightCell == 2)
				{
					return 0;
				}
				break;	//��� ���������� ��� ������
			}
		}
	}
	return 1; //�� �������
}
bool canLeftShift(Field field, Object object)
{
	for (int x = 0; x < object.GetSize(); x++){
		for (int y = object.GetSize() - 1; y >= 0; y--)
		{
			int LeftCell = field.GetCell(y_from_Stick_to_Field(y, object), x_from_Stick_to_Field(x - 1, object));
			if (object.GetCell(y, x) == 1)
			{
				//���� "������ �����" = 1, ��� ���� ������ �������� � ����� 
				if (LeftCell == 1 || LeftCell == 2)
				{
					return 0;
				}
				break;	//��� ���������� ��� ������
			}
		}
	}
	return 1; //�� �������
}


//bool canTurn(Field field, Object object)
//{
//	//������� ������ ���� "object" ������������ "field"
//	int RightUp = field.GetCell(y_from_Stick_to_Field(object.GetY(), 0), x_from_Stick_to_Field(object.GetX(), 2));
//	int LeftDown
//	if ()
//	{
//
//	}
//}

//-----------------------------------------------------------------------------------------

//������������� "object" �� "field"
//������� "object" �� field
//������� ������ ����� �� ��������� 1
void freeze(Object object, Field &field)
{
	int fieldY, fieldX;

	for (int y = 0; y < object.GetSize(); y++){	//������ �� "object"
		for (int x = 0; x < object.GetSize(); x++)
		{
			int stickCell = object.GetCell(y, x);

			if (stickCell == 1)
			{
				fieldY = y_from_Stick_to_Field(y, object); //���������� � "field"
				fieldX = x_from_Stick_to_Field(x, object);

				field.SetCell(fieldY, fieldX, stickCell);
			}
		}
	}
}

//"countToClear" - ���������� ��������� ����� 
bool needClear(Field field, int &countToClear)
{
	//������ �� "field". ������� ������ ������, ����� ����� �����
	for (int y = field.GetSize() - 2; y >= 1; y--)
	{
		for (int x = field.GetSize() - 2; x >= 1; x--)
		{
			if (field.GetCell(y, x) == 0)
			{
				//���� �� ��������� ������ ���� "0", �� return 0, �����: ��� ����������� ������ ���������
				if (y == field.GetSize() - 1){ return 0; }
				else{ return 1; }
			}
		}

		countToClear++;
	}
	//�� ������ ������
	return 0;
}

//�������� ������ ��������� ����� � ���������� "countToClear"
//�������� ����������� ����� �� "countToClear"
void clear(Field &field, int countToClear)
{
	//������ �� "y" � "field".
	int y = 0;
	for (int yReversed = 0; countToClear > yReversed; yReversed++)
	{
		y = (field.GetSize() - 2) - yReversed;	//"y" �����������

		//��������� ���� ������
		for (int x = field.GetSize() - 2; x >= 1; x--)
		{
			field.SetCell(y, x, 0);
		}
	}

	//�������� ����� �� "countToClear" ����
	//����� �� ������ ������
	for (int y = field.GetSize() - 2; y >= 1; y--){
		for (int x = field.GetSize() - 2; x >= 1; x--)
		{
			//���� ������ == 1, �� ���� ������ ������������� 0, ������ ��������� �� "y" �� "countToClear" ��� ��� ������������� 1
			if (field.GetCell(y, x) == 1)
			{
				field.SetCell(y, x, 0);
				field.SetCell(y + countToClear, x, 1);
			}
		}
	}
}

//��������� ����.
//������� "n" �����
void nextFrame(int score)
{
	int n = 0;
	while (n < 18)
	{
		cout << endl;
		n++;
	}

	//����� � �������
	cout << "����������:" << endl;
	cout << "�����: '0'." << endl;
	cout << "'9'- ������� �� �������, '7' - ������� ������ �������." << endl;
	cout << "'6'- ������, '4' - �����." << endl << endl;
	cout << "����: '5'." << endl;
	cout << "����: " << score << endl << endl;

}
//-----------------------------------------------------------------------------------------

void main()
{
	SetConsoleOutputCP(1251);

	int y0 = 0;
	int x0 = 3;
	int score = 0;
	int countOfObjects = 0;

	Object object = *new Object(y0, x0, countOfObjects);
	Field field;

	//��������� ������� ����� ��� �������� �������� "������".
	cout << "����� ~5 ������ ��� ����� ������� ���������? " << endl;
	cout << "enter - �� " << endl;
	char input = _getch();
	if (input == '\r'){
		for (int i = 0; i < 10000; i++){
			cout << endl;
		}
	}

	input = '1';
	while (input != '0')
	{
		nextFrame(score);
		displayStick(field, object);

		int countOfTime = 0;
		while (countOfTime < 50)
		{
			//���� ����� ����� �� ����� ������
			if (_kbhit())
			{
				input = _getch();

				//������� �...
				if (input == '5' || input == '0') { break; }
				//��������
				else if (input == '9'){ object.TurnRight(); }
				else if (input == '7'){ object.TurnLeft(); }
				//������ x
				else if (input == '6' && canRightShift(field, object)){ object.xRightShift(); }
				else if (input == '4' && canLeftShift(field, object)){ object.xLeftShift(); }
				//����� ��������� ��������� ����� �������� �����
				nextFrame(score);
				displayStick(field, object);
			}

			Sleep(10);
			countOfTime++;
		}

		if (canFall(field, object))
		{
			object.Fall();
		}
		//"object" ��������� ����� ��������
		else
		{
			freeze(object, field);

			//�������� ������ "object"
			//
			if (countOfObjects < COUNT_OF_OBJECTS - 1){ countOfObjects++; }
			else{ countOfObjects = 0; }
			object = *new Object(y0, x0, countOfObjects);

			int countToClear = 0;	//���������� ����� �� ��������
			if (needClear(field, countToClear))
			{
				clear(field, countToClear);
				score += countToClear * FIELD_SIZE;
				countToClear = 0;	//��������� ����� ������� ����
			}
		}
	}

	cout << "���������" << endl;
}