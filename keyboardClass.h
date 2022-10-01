#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "productClass.h"

#define KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE 64
#define KEYBOARD_STRING_IDENTIFICATOR "Keyboard"
class keyboard : public product {
private:
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE];
	int LengthOfCable;
public:
	keyboard();
	keyboard(char* Name);
	keyboard(char* Name, char* Company);
	keyboard(char* Name, char* Company, int Price);
	keyboard(char* Name, char* Company, int Price, int Count);
	keyboard(char* Name, int Price);
	keyboard(product General, char* TypeOfConnection, int LengthOfCable);
	keyboard(const keyboard& obj);
	~keyboard();

	bool SetTypeOfConnection(char* Type);
	bool SetLengthOfCable(int Length);

	void GetTypeOfConnection(char Type[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE]);
	int GetLengthOfCable();

	/*������� ��� ���������� �� �����*/
	void OutputAllInfo();
	/*���� ���� ���������� � ����������*/
	void InputAllInfo();
	/*��������� ��� ���������� � ���� (���� - Path).
	�������: 1 - ������ ������ �������; 0 - ���� �� ��������*/
	int SaveInFile(char* Path);
	/*��������� ���������� � ����� ���� (���� - Path)
	�������: 1 - ������ ������ �������; 0 - ���� �� ��������; -1 - ���� ��� ����������; -2 - ������� ��������� ����*/
	int SaveInNewFile(char* Path);
	/*��������� ���������� �� ����� (���� - Path).
	�������: 1 - �������; 0 - ���� �� ��������; -1 - ���������� ������������� ����� ������ (���� ������������� ������)*/
	int ReadFromFile(char* Path);
};