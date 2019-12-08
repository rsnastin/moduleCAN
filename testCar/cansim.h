#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


using namespace std;

int SPEED = 50;
int GEAR = 0;
float LONGITUDE = 14.552;
float LATITUDE = 53.428;
int HEIGHT = 25;
int ITER = 0;
int HUD[1];
string WHEEL = "000003";

string engine()
{
	string st = "01";
	st += "001";
	int randSpeed = rand() % 11 - 5;
	
	if (SPEED > 98)
	{
		SPEED = SPEED - 20;
	}
	else if (SPEED < 20)
	{	
		SPEED = SPEED + 10;
	}
	else 
	{
		SPEED = SPEED + randSpeed;
	}
	st += "0000" + to_string(SPEED);
	HUD[0] = SPEED;
	return st;
}
string gearbox()
{
	string st = "01";
	st += "020";
	if (SPEED <= 15)
	{
		GEAR = 1;
	}
	else if (SPEED <= 40)
	{
		GEAR = 2;
	}
	else if (SPEED <= 60)
	{
		GEAR = 3;
	}
	else if (SPEED <= 75)
	{
		GEAR = 4;
	}
	else if (SPEED <= 99)
	{
		GEAR = 5;
	}
	else
	{
		GEAR = 0;
	}
	st += "00000" + to_string(GEAR);
	HUD[1] = GEAR;
	return st;
}

string comfort()
{
	string st = "46";
	st += "010";

	int randComf = rand() % 20;
	if (randComf == 5)
	{
		st += "000001";
	}
	else
	{
		st += "000000";
	}
	
	return st;
}

string abs()
{
	string st = "03";
	st += "001";
	st += "000000";

	return st;
}

string hvac()
{

	string st = "08";
	st += "001";
	
	int randTemp = rand() % 20;
	if (randTemp == 10)
	{
		st += "000018";
	}
	else
	{
		st += "000017";
	}
	return st;
}

string steeringWheel()
{
	string st = "16";
	st += "010";
	int randWheel = rand() % 50;
	if (randWheel == 10)
	{
		WHEEL = "000001";
	}
	else if(randWheel == 20)
	{
		WHEEL = "000002";
	}
	else if (randWheel == 30)
	{
		WHEEL = "000003";
	}

	st += WHEEL;
	return st;
}

string navi()
{
	string st = "37";
	st += "001";
	int randHeight = rand() % 25;
	if (randHeight == 20)
	{
		HEIGHT = HEIGHT + 2;
	}
	else if (randHeight == 10)
	{
		HEIGHT = HEIGHT - 1;
	}
	st += "0000" + to_string(HEIGHT);

	return st;
}

string radio()
{
	string st = "56";

	st += "010";
	st += "000001";

	return st;
}

string centralLock()
{
	string st = "35";
	st += "001";
	if (SPEED < 12)
	{
		st += "000000";
	}
	else
	{
		st += "000001";
	}
	
	return st;
}

string readCANNetwork()
{
	string res = "";

	switch (ITER)
	{
	case 0:
		res = engine();
		break;
	case 1:
		res = gearbox();
		break;
	case 2:
		res = comfort();
		break;
	case 3:
		res = hvac();
		break;
	case 4:
		res = steeringWheel();
		break;
	case 5:
		res = navi();
		break;
	case 6:
		res = radio();
		break;
	case 7:
		res = centralLock();
		break;
	case 8:
		res = abs();
		Sleep(10);
		system("cls");
		cout << endl << "Current gear: " << HUD[1] << " Current speed: " << HUD[0] << "km/h" << endl << "--------------------------------------" << endl;
	default:

		break;
		
	}

	if (ITER < 8)
	{

		ITER++;
	}
	else
	{

		ITER = 0;
	}


	return res;
}

/*
dummy CAN FRAME SPECIFICATION
2 bits - MODULE
4 bits - Function
6 bits - value

|----|-------|-------------|
|2   | 3     | 6           |
|1 1 | 1 1 1 | 1 1 1 1 1 1 |
|Mod | Funct.| Value       |
|----|-------|-------------|
'''
'''
01 ENGINE
*Functionality:
001 - speed
020 - gear indicator
*Value
according to selected functionality

46 COMFORT
010 - Windows
100 - Mirrors

03 ABS (module)
001 ABS
010 ESP
100 TC

08 HVAC
001 - Temp
010 - Fan speed
100 - Zone

16 STEERING
001 - Rotation (degree)
010 - Mode (Race, Comfort, Auto)

37 NAVIGATION
001 - Height above see level
010 - Latitude
020 - Longitude
100 - number of satelites

56 RADIO
010 - Band (AM/FM)
050 - Current Frequency
100 - RDS

35 CENTRAL LOCK
001 - door lock status
*/