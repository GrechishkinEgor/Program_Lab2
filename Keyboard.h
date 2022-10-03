#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	Product General;
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//���������/������������
	int LengthOfCable;											//����� ������ � ������ (���� ��� ������ - ����� 0)
}Keyboard;

Keyboard InitKeyboard();
Keyboard InitKeyboard(Product General);
Keyboard InitKeyboard(Product General, char* TypeOfConnection, int LengthOfCable);

int SetKeyboardGeneral(Keyboard* CurrentKeyboard, Product General);
int SetKeyboardTypeOfConnection(Keyboard* CurrentKeyboard, char* Type);
int SetKeyboardLengthOfCable(Keyboard* CurrentKeyboard, int Length);

Product GetKeyboardGeneral(Keyboard CurrentKeyboard);
void GetKeyboardTypeOfConnection(Keyboard CurrentKeyboard, char* Type);
int GetKeyboardLengthOfCable(Keyboard CurrentKeyboard);

void OutputAllInfoAboutKeyboard(Keyboard CurrentKeyboard);

/*��������� ���������� � ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������*/
int SaveKeyboard(Keyboard CurrentProduct, char* Path);
/*��������� ���������� � ����� ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ��� ����������*/
int SaveNewKeyboard(Keyboard CurrentProduct, char* Path);
/*���������� ������ � ������ � �������� ��� ������ �������� �����
�������: 1 - ������ ���� ��������; 0 - ������� ������� ��������� �� �����*/
int WriteKeyboardInFile(Keyboard CurrentProduct, FILE* BinaryWriterFile);

/*������� ������ � ������ �� ����� (���� - Path)
�������: 1 - �������; 0 - ����� �� ���������� ��� ����������; -1 - ������� ������� ��������� �� ���������*/
int LoadKeyboard(Keyboard* CurrentProduct, char* Path);
/*��������� ������ � ������ �� ��������� ������, ��������� �� ������
�������: 1 - �������; -1 - ��������� ����� ������; 0 - ������� ������� ��������� �� ���� ��� ���������*/
int ReadKeyboardFromFile(Keyboard* CurrentProduct, FILE* BinaryReaderFile);