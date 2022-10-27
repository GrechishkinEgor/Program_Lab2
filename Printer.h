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
	Printer(Product General, std::string Type, int DPI, int PaperFormat);
	Printer(const Printer& Obj);
	~Printer();

	bool SetTypeOfPrint(const char* Type);
	bool SetTypeOfPrint(std::string Type);
	bool SetDPI(int DPI);
	bool SetPaperFormat(int PaperFormat);

	void GetTypeOfPrint(char* Type);
	std::string GetTypeOfPrint();
	int GetDPI();
	int GetPaperFormat();

	void OutputAllInfo();

	/*���������� ������ � �������� ��� ������ �������� �����.
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	int ReadFromFile(FILE* BinaryReaderFile);
};