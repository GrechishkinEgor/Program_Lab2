#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;											//Длина кабеля в метрах (если нет кабеля - равно 0)
}Keyboard;

Keyboard InitKeyboard();
Keyboard InitKeyboard(char* TypeOfConnection, int LengthOfCable);

void OutputAllInfoAboutKeyboard(Keyboard CurrentKeyboard);
void InputAllInfoAboutKeyboard(Keyboard* CurrentKeyboard);