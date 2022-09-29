#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//���������/������������
	int LengthOfCable;										//����� ������ � ����������� (���� ��� ������ - ����� 0)
	int Sensitivity;										//���������������� (���������� �������) - dpi
	int CountOfButtons;										//���������� ������
}Mouse;

Mouse InitMouse();
Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection);

/*����� ���� ���������� � ���� �� �����*/
void OutputAllInfoAboutMouse(Mouse CurrentMouse);
/*���� ���� ���������� � ���� �������������*/
void InputAllInfoAboutMouse(Mouse* CurrentMouse);