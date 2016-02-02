#pragma once

#include "Queue.h"
#include <iostream>

 

struct Node  //��������� ����� ��������� ������
{

	int		x;
	int		id_packed;
	int		carmodel;
	float	X_Pos, Y_Pos, Z_Pos; // float Pos[2];
	float	Go_X, Go_Y, Go_Z;	   // float GoPos[2];
	float	VehAngle;
	int		Veh_Speed;
	int		Healch;
	int		Color_1, Color_2;
	Node *Next; //��������� �� ��������� �����
};


//����� ������
class List
{
	Node *Head, *Tail; //��������� �� ������ ������ � �� �����
public:
    int  count;

	List() :Head(NULL), Tail(NULL){}; //������������� ���������� ��� ������
	~List();
	void Add(int x, int id_packed, int ServerCarId, float X_Pos, float Y_Pos, float Z_Pos, float Go_X, float Go_Y, float Go_Z, int VehAngle, float Veh_Speed, int Healch, int Color_1, int Color_2);
	void Spawn(int carmodel, float X_Pos, float Y_Pos, float Z_Pos);
	void Show();
	void del(); //������� ������� ��������
	int  GetCount();
};
