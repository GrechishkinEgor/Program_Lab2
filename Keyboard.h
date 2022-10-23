#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
class Keyboard : public Product {
private:
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//���������/������������
	int LengthOfCable;											//����� ������ � ������ (���� ��� ������ - ����� 0)
public:
	Keyboard();
	Keyboard(Product General);
	Keyboard(Product General, const char* TypeOfConnection);
	Keyboard(Product General, const char* TypeOfConnection, int LengthOfCable);
	Keyboard(const Keyboard& Obj);
	~Keyboard();

	bool SetTypeOfConnection(const char* Type);
	bool SetLengthOfCable(int Length);

	void GetTypeOfConnection(char* Type);
	int GetLengthOfCable();

	void OutputAllInfo();

	/*���������� ������ � �������� ��� ������ �������� �����.
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	int ReadFromFile(FILE* BinaryReaderFile);
};
