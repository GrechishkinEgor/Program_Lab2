#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define PRINTER_TYPE_OF_PRINT_SIZE 64
typedef struct {
	Product General;
	char TypeOfPrint[PRINTER_TYPE_OF_PRINT_SIZE];	//���������/��������/��������
	int DPI;										//����������
	int PaperFormat;								//������ ������ (�4, �5...)
}Printer;

Printer InitPrinter();
Printer InitPrinter(Product General);
Printer InitPrinter(Product General, char* Type, int DPI, int PaperFormat);

int SetPrinterTypeOfPrint(Printer* CurrentPrinter, char* TypeOfPrint);
int SetPrinterDPI(Printer* CurrentPrinter, int DPI);
int SetPrinterPaperFormat(Printer* CurrentPrinter, int PaperFormat);
int SetPrinterGeneral(Printer* CurrentPrinter, Product General);

void GetPrinterTypeOfPrint(Printer CurrentPrinter, char* TypeOfPrint);
int GetPrinterDPI(Printer CurrentPrinter);
int GetPrinterPaperFormat(Printer CurrentPrinter);
Product GetPrinterGeneral(Printer CurrentPrinter);

/*����� ���� ���������� � CurrentPrinter �� �����*/
void OutputAllInfoAboutPrinter(Printer CurrentPrinter);

/*��������� ���������� � �������� � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������*/
int SavePrinter(Printer CurrentProduct, char* Path);
/*��������� ���������� � ����� �������� � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ��� ����������*/
int SaveNewPrinter(Printer CurrentProduct, char* Path);
/*���������� ������ � �������� � �������� ��� ������ �������� �����
�������: 1 - ������ ���� ��������; 0 - ������� ������� ��������� �� �����*/
int WritePrinterInFile(Printer CurrentProduct, FILE* BinaryWriterFile);

/*������� ������ � �������� �� ����� (���� - Path)
�������: 1 - �������; 0 - ����� �� ���������� ��� ����������; -1 - ������� ������� ��������� �� ���������*/
int LoadPrinter(Printer* CurrentProduct, char* Path);
/*��������� ������ � �������� �� ��������� ������, ��������� �� ������
�������: 1 - �������; -1 - ��������� ����� ������; 0 - ������� ������� ��������� �� ���� ��� ���������*/
int ReadPrinterFromFile(Printer* CurrentProduct, FILE* BinaryReaderFile);