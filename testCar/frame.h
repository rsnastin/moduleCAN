#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class frame
{
protected:
	string id;
	string fun;
	string data;
public:
	frame();
	frame(string, string, string);
	void wyswietlFrame();
};