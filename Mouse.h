#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
class Mouse : public Product
{
private:
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//���������/������������
	int LengthOfCable;										//����� ������ � ����������� (���� ��� ������ - ����� 0)
	int Sensitivity;										//���������������� (���������� �������) - dpi
	int CountOfButtons;										//���������� ������

public:
	Mouse();
	Mouse(Product General);
	Mouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection);
	Mouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
	Mouse(const Mouse& Obj);
	~Mouse();

	bool SetTypeOfConnection(const char* Type);
	bool SetLengthOfCable(int Length);
	bool SetSensitivity(int Sensitivity);
	bool SetCountOfButtons(int Count);

	void GetTypeOfConnection(char* Type);
	int GetLengthOfCable();
	int GetSensitivity();
	int GetCountOfButtons();

	void OutputAllInfo();

	/*��������� ������ � ���� (���� - Path)
	�������: 1 - �������; 0 - ���� �� ��������*/
	int Save(char* Path);
	/*���������� ������ � ����� ����.
	�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ����������*/
	int SaveNew(char* Path);
	/*���������� ������ � �������� ��� ������ �������� �����.
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*�������: 1 - �������; 0 - ������� ������� ��������� ���� �����; -1 - ���� �� ������*/
	int Load(char* Path);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	int ReadFromFile(FILE* BinaryReaderFile);
};