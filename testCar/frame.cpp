#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "frame.h"


using namespace std;
int iloscRamek = 0;

frame::frame()
{
	id = "00";
	fun = "000";
	data = "000000";

}

frame::frame(string i, string f, string d)
{
	srand(time(NULL));
	id = i;
	fun = f;
	data = d;
}

void frame::wyswietlFrame()
{
	iloscRamek++;
	cout << "*" << iloscRamek << "*";
	if (id.compare("01") == 0)                                  //engine
	{
		if (fun.compare("001") == 0)
		{
			cout << "Speed: " << data << endl;
		}
		else if (fun.compare("020") == 0)
		{
			cout << "Gear indicator: " << data << endl;
		}
	}
	else if (id.compare("46") == 0)							// comfort
	{
		if (fun.compare("010") == 0)
		{
			cout << "Windows: " << data << endl;
		}
		else if (fun.compare("100") == 0)
		{
			cout << "Mirrors: " << data << endl;
		}
	}
	else if (id.compare("03") == 0)							//module
	{
		if (fun.compare("001") == 0)
		{
			cout << "ABS: " << data << endl;
		}
		else if (fun.compare("010") == 0)
		{
			cout << "ESP: " << data << endl;
		}
		else if (fun.compare("100") == 0)
		{
			cout << "TC: " << data << endl;
		}
	}
	else if (id.compare("08") == 0)							//HVAC
	{
		if (fun.compare("001") == 0)
		{
			cout << "Temp: " << data << endl;
		}
		else if (fun.compare("010") == 0)
		{
			cout << "Fan speed: " << data << endl;
		}
		else if (fun.compare("100") == 0)
		{
			cout << "Zone: " << data << endl;
		}
	}
	else if (id.compare("16") == 0)							//STEERING
	{
		if (fun.compare("001") == 0)
		{
			cout << "Rotation (degree): " << data << endl;
		}
		else if (fun.compare("010") == 0)
		{
			cout << "Mode (Race, Comfort, Auto): " << data << endl;
		}
	}
	else if (id.compare("37") == 0)							//NAVIGATION
	{
		if (fun.compare("001") == 0)
		{
			cout << "Height above see level " << data << endl;
		}
		else if (fun.compare("010") == 0)
		{
			cout << "Latitude: " << data << endl;
		}
		else if (fun.compare("020") == 0)
		{
			cout << "Longitude: " << data << endl;
		}
		else if (fun.compare("100") == 0)
		{
			cout << "number of satelites: " << data << endl;
		}
	}
	else if (id.compare("56") == 0)							//RADIO
	{
		if (fun.compare("010") == 0)
		{
			cout << "Band (AM/FM): " << data << endl;
		}
		else if (fun.compare("050") == 0)
		{
			cout << "Current Frequency: " << data << endl;
		}
		else if (fun.compare("100") == 0)
		{
			cout << "RDS: " << data << endl;
		}

	}
	else if (id.compare("35") == 0)							//CENTRAL LOCK
	{
		if (fun.compare("001") == 0)
		{
			cout << "door lock status: " << data << endl;
		}
	}

}
