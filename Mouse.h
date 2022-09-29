#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;										//Длина кабеля в сантиметрах (если нет кабеля - равно 0)
	int Sensitivity;										//Чувствительность (разрешение датчика) - dpi
	int CountOfButtons;										//Количество кнопок
}Mouse;

Mouse InitMouse();
Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection);

/*Вывод всей информации о мыши на экран*/
void OutputAllInfoAboutMouse(Mouse CurrentMouse);
/*Ввод всей информации о мыши пользователем*/
void InputAllInfoAboutMouse(Mouse* CurrentMouse);