#include <iostream>
#include <cstring>
#include <Windows.h>
#include <time.h>
#include <iomanip>
#include "Queue.h"
using namespace std;

void ThreadPackedDataArival();
void CarManager(float *fPtrArr, int cnt);
void PopPackForCleo();

List veh;
//------

int main()
{
	setlocale(LC_ALL, "RUS");
	HANDLE		hThread;
	DWORD		IDThread;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadPackedDataArival, NULL, 0, &IDThread);
	cout << endl;
	Sleep(1000);
	system("pause");
	return 0;
}


void PopPackForCleo()
{

}

void CarManager(float *fPtrArr, int cnt)
{
	int carmodel = 411;// GetRandomCarModel();

	//for (int j = 0; j < cnt; j++)
	//	cout << fPtrArr[j] << endl;

	veh.Spawn((int)carmodel, fPtrArr[1], fPtrArr[2], fPtrArr[3]);

	veh.Spawn((int)carmodel, fPtrArr[1], fPtrArr[2], fPtrArr[3]);
	//veh.Spawn((int)carmodel, fPtrArr[1], fPtrArr[2], fPtrArr[3]);
	//void List::Spawn(int carmodel, float X_Pos, float Y_Pos, float Z_Pos)
//	veh.Show();

}

void ThreadPackedDataArival()
{
	int i = 0, prms, cnt=0;
	float Arr[22];

	char *buf = "|50|2046.469971|1463.300049|10.113900|";// нам пришло
	char Packed[333];

	for (i = 0; buf[i] != '\0'; i++)
		Packed[i] = buf[i];	//i++;
	Packed[i] = '\0';	

	for (i = 0; Packed[i] != '\0'; i++) // а для преоброзования в double(atof) надо "123,0 234,23 999,666"
		if (Packed[i] == '.') Packed[i] = ',';

	cout << "Packed:\t" << Packed << endl << endl; // itog
 
	char *token1 = NULL, *next_token1 = NULL,	seps[] = "|";
	token1 = strtok_s(Packed, seps, &next_token1);	
	if (token1 != NULL)
	{
		prms = (int)atof(token1); //    тут то, с чем работаем, obj, car, ped, bullet, и тд	
		i = 0; cnt = 0;
		while ((token1 != NULL))
		{
			if (token1 != NULL)
			{
				Arr[i++] = (float)atof(token1);
				cout << "char: " << token1<<endl;
				token1 = strtok_s(NULL, seps, &next_token1);
				cnt++;
			}
		}
	}
	cout << "итак прочли " << cnt << " вызываем " << prms<< endl <<
		"-------------------\n";
//	for (int j = 0; j < cnt; j++)
//		cout << Arr[j] << endl;

	switch (prms) // цель этого блока:   вызова соответствующего конструктора
	{
		case 50: { 
			cout << "работаем с тачкой"<< endl;
			CarManager(Arr, cnt);
			 
		} break;

		default:
			cout << "не один из вариантов не подошел" << endl;
		break;
	}

}
			
