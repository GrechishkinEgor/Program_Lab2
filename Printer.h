#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define PRINTER_TYPE_OF_PRINT_SIZE 64
class Printer : public Product
{
private:
	char TypeOfPrint[PRINTER_TYPE_OF_PRINT_SIZE];	//���������/��������/��������
	int DPI;										//����������
	int PaperFormat;								//������ ������ (�4, �5...)
public:
	Printer();
	Printer(Product General);
	Printer(Product General, const char* Type, int DPI, int PaperFormat);
	Printer(const Printer& Obj);
	~Printer();

	bool SetTypeOfPrint(const char* Type);
	bool SetDPI(int DPI);
	bool SetPaperFormat(int PaperFormat);

	void GetTypeOfPrint(char* Type);
	int GetDPI();
	int GetPaperFormat();

	void OutputAllInfo();

	/*��������� ������ � ���� (���� - Path)
	�������: 1 - �������; 0 - ���� �� ��������*/
	int Save(const char* Path);
	/*���������� ������ � ����� ����.
	�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ����������*/
	int SaveNew(const char* Path);
	/*���������� ������ � �������� ��� ������ �������� �����.
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*�������: 1 - �������; 0 - ������� ������� ��������� ���� �����; -1 - ���� �� ������*/
	int Load(const char* Path);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	int ReadFromFile(FILE* BinaryReaderFile);
};