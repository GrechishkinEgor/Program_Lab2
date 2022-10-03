#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	Product General;
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//���������/������������
	int LengthOfCable;										//����� ������ � ����������� (���� ��� ������ - ����� 0)
	int Sensitivity;										//���������������� (���������� �������) - dpi
	int CountOfButtons;										//���������� ������
}Mouse;

Mouse InitMouse();
Mouse InitMouse(Product General);
Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection);

int SetMouseTypeOfConnection(Mouse* CurrentMouse, char* TypeOfConnection);
int SetMouseLengthOfCable(Mouse* CurrentMouse, int LenghtOfCable);
int SetMouseSensitivity(Mouse* CurrentMouse, int Sensitivity);
int SetMouseCountOfButtons(Mouse* CurrentMouse, int Count);

void GetMouseTypeOfConnection(Mouse CurrentMouse, char* TypeOfConnection);
int GetMouseLenghtOfCable(Mouse CurrentMouse);
int GetMouseSensitivity(Mouse CurrentMouse);
int GetMouseCountOfButtons(Mouse CurrentMouse);

/*����� ���� ���������� � ���� �� �����*/
void OutputAllInfoAboutMouse(Mouse CurrentMouse);

/*��������� ���������� � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������*/
int SaveMouse(Mouse CurrentProduct, char* Path);
/*��������� ���������� � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ��� ����������*/
int SaveNewMouse(Mouse CurrentProduct, char* Path);
/*���������� ������ � �������� ��� ������ �������� �����
�������: 1 - ������ ���� ��������; 0 - ������� ������� ��������� �� �����*/
int WriteMouseInFile(Mouse CurrentProduct, FILE* BinaryWriterFile);

/*������� ������ �� ����� (���� - Path)
�������: 1 - �������; 0 - ����� �� ���������� ��� ����������; -1 - ������� ������� ��������� �� ���������*/
int LoadMouse(Mouse* CurrentProduct, char* Path);
/*��������� ������ �� ��������� ������, ��������� �� ������
�������: 1 - �������; -1 - ��������� ����� ������; 0 - ������� ������� ��������� �� ���� ��� ���������*/
int ReadMouseFromFile(Mouse* CurrentProduct, FILE* BinaryReaderFile);