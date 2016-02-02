#pragma once

#include "Queue.h"
#include <iostream>

 

struct Node  //СТРУКТУРА БУДЕТ ЭЛЕМЕНТОМ СПИСКА
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
	Node *Next; //Указатель не следующее звено
};


//КЛАСС СПИСОК
class List
{
	Node *Head, *Tail; //Указатели на начало списка и на конец
public:
    int  count;

	List() :Head(NULL), Tail(NULL){}; //Инициализация указателей как пустых
	~List();
	void Add(int x, int id_packed, int ServerCarId, float X_Pos, float Y_Pos, float Z_Pos, float Go_X, float Go_Y, float Go_Z, int VehAngle, float Veh_Speed, int Healch, int Color_1, int Color_2);
	void Spawn(int carmodel, float X_Pos, float Y_Pos, float Z_Pos);
	void Show();
	void del(); //Функция изъятия элемента
	int  GetCount();
};
