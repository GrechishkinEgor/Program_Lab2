#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

class Monitor : public Product {
private:
	Product General;
	int Diagonal;		//��������� ������� � ������
	int Frequency;		//������� ���������� ������ �������� � ������
	int Size[2];		//���������� ������ (����� �������� �� ����������� � ���������)
	int AspectRatio[2];	//����������� ������ (16:9/16:10...)
public:
	Monitor();
	Monitor(Product General);
	Monitor(Product General, int Diagonal, int Frequency, int Size[2], int AspectRatio[2]);
	Monitor(const Monitor& Obj);
	~Monitor();

	bool SetDiagonal(int Diagonal);
	bool SetFrequency(int Frequency);
	bool SetSize(int Width, int Height);
	bool SetAspectRatio(int AspectRatio1, int AspectRatio2);

	int GetDiagonal();
	int GetFrequency();
	void GetSize(int* Width, int* Height);
	void GetAspectRation(int* AspectRatio1, int* AspectRatio2);
	void OutputAllInfo();

	void operator=(Product& General);
	friend void operator<<(std::ostream& o, Monitor obj);

	/*���������� ������ � �������� ��� ������ �������� �����.
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	int ReadFromFile(FILE* BinaryReaderFile);

	
};
