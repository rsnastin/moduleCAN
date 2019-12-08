#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <winbase.h>

#include "cansim.h"
#include "frame.h"

string calaRamka=" ";

using namespace std;
void funkcja(string readFunkcja)
{
	string str1 = readFunkcja.substr(0, 2);
	string str2 = readFunkcja.substr(2, 3);
	string str3 = readFunkcja.substr(5, 7);
	cout << str1 << " " << str2 << " " << str3 << " :: ";
	frame Ramka(str1, str2, str3);
	Ramka.wyswietlFrame();
	calaRamka = str1 + " " + str2 + " " + str3;
}


int main()
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	ofstream plik;
	plik.open("can.log", ios::out | ios::app);
	if (plik.good() == true)
	{
		for (int i = 0; i < 998; i++)
		{
			funkcja(readCANNetwork());
			plik << st.wHour+1<<":"<< st.wMinute << "  " <<st.wDay<<":"<<st.wMonth<<":"<<st.wYear<<"   ::    "<<calaRamka<<endl;
		}
	}
	cout <<endl<< "END"<<endl;
	plik.close();
	int a = 0;
	cin >> a;

	return 0;
}