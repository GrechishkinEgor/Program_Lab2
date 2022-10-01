#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "keyboardClass.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	keyboard FirstKeyb;
	FirstKeyb.InputAllInfo();
	FirstKeyb.OutputAllInfo();
	printf("-------");
	keyboard SecondKeyb = FirstKeyb;
	SecondKeyb.OutputAllInfo();
	return 0;
}