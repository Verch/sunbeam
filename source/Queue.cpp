#include "Queue.h"
#include <iostream>
using namespace std;

 
List::~List()
{
	Node *temp = Head;
	while (temp != NULL)
	{
		temp = Head->Next;
		delete Head;
		Head = temp;
	}
}


void List::Add(int x, int id_packed, int ServerCarId, float X_Pos, float Y_Pos, float Z_Pos, float Go_X, float Go_Y, float Go_Z, int VehAngle, float Veh_Speed, int Healch, int Color_1, int Color_2)
{
	Node *temp = new Node;

	temp-> x = x;
	temp->id_packed = id_packed;
	 
	temp->X_Pos = X_Pos;// float Pos[2];
	temp->Y_Pos = Y_Pos;  // float Pos[2];
	temp->Z_Pos = Z_Pos; // float Pos[2];

	temp->Go_X = Go_X;	   // float GoPos[2]
	temp->Go_Y = Go_Y;	   // float GoPos[2];
	temp->Go_Z = Go_Z;	   // float GoPos[2];

	temp->VehAngle = VehAngle;
	temp->Veh_Speed = Veh_Speed;
	temp->Healch = Healch;

	temp->Color_1 = Color_1;
	temp->Color_2 = Color_2; 

	temp->Next = NULL;
	if (Head != NULL) 
	{
		Tail->Next = temp; 
		Tail = temp;
	}
	else Head = Tail = temp; 
}

void List::Spawn(int vehmodel, float X_Pos, float Y_Pos, float Z_Pos) 
{
	Node *temp = new Node;
	count++;
	temp->carmodel = vehmodel;
	temp->X_Pos			= X_Pos;// float Pos[2];
	temp->Y_Pos			= Y_Pos;  // float Pos[2];
	temp->Z_Pos			= Z_Pos; // float Pos[2];*/

	temp->Next = NULL;  
	if (Head != NULL)  
	{
		Tail->Next = temp;   
		Tail = temp;
	}
	else Head = Tail = temp;  
}

void List::Show()
{
	Node *temp = Head; 
	while (temp != NULL)  
	{
		cout <<   "\n--------------------------\n"; 
		cout << "X"			<< temp-> x			<< endl;
		cout << "id_packed" << temp-> id_packed	<< endl;
		cout << "carmodel\t"	<< temp-> carmodel		<< endl;
		cout << "X_Pos\t"		<< temp-> X_Pos		<< endl;
		cout << "Y_Pos\t"		<< temp-> Y_Pos		<< endl;
		cout << "Z_Pos\t"		<< temp-> Z_Pos		<< endl;
		cout << "Go_X"		<< temp-> Go_X			<< endl;
		cout << "Go_Y"		<< temp-> Go_Y			<< endl;
		cout << "Go_Z"		<< temp-> Go_Z			<< endl;
		cout << "VehAngle"	<< temp-> VehAngle		<< endl;
		cout << "Veh_Speed" << temp-> Veh_Speed	<< endl;
		cout << "Healch"	<< temp-> Healch		<< endl;
		cout << "Color_1"	<< temp-> Color_1		<< endl;
		cout << "Color_2"	<< temp->Color_2		<< endl;
		cout << "\n-----------	в списке " << count << endl;
		temp = temp->Next; 
		
	}
}


void List::del(){
	if (Head != NULL)
	{
		Node *temp = Head; 
		Head = Head->Next;  
		delete temp;  
	}
}



//------
