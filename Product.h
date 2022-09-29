#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Monitor.h"
#include "Printer.h"
#include "Mouse.h"
#include "Keyboard.h"

typedef enum {
	IsNotDefined,
	IsMouse,
	IsKeyboard,
	IsMonitor,
	IsPrinter,
}TypeOfProduct;

#define PRODUCT_NAME_SIZE 64
#define PRODUCT_COMPANY_SIZE 64
typedef struct {
	char Name[PRODUCT_NAME_SIZE];
	char Company[PRODUCT_COMPANY_SIZE];
	int Price;
	int Count;
	TypeOfProduct Type;
	union {
		Mouse AboutMouse;
		Keyboard AboutKeyboard;
		Monitor AboutMonitor;
		Printer AboutPrinter;
	}Information;
}Product;

/*��������������*/
Product InitProduct();
Product InitProduct(char* Name, char* Company, int Price);
Product InitProduct(char* Name, char* Company, int Price, Mouse Info);
Product InitProduct(char* Name, char* Company, int Price, Keyboard Info);
Product InitProduct(char* Name, char* Company, int Price, Monitor Info);
Product InitProduct(char* Name, char* Company, int Price, Printer Info);

/*����������� �� ���� ���������� ������. ������� - ���������� ������ ����� ����������*/
int IncreaseCountOfProduct(Product* CurrentProduct);
/*��������� �� ���� ���������� ������. ������� - ���������� ������ ����� ����������*/
int DecreaseCountOfProduct(Product* CurrentProduct);
/*������� ��� ���������� � ������ �� �����*/
void OutputAllInfoAboutProduct(Product CurrentProduct);
/*���� ���� ���������� � ������ �������������*/
void InputAllInfoAboutProduct(Product* CurrentProduct);
/*�������� ���������� � ������ � ����� ���� (���� - Path)
�������: 0 - �������; 1 - ���� ����������; -1 - ���� �� ��������*/
int WriteProductInFile(Product CurrentProduct, char* Path);
/*��������� ���������� � ������ � ���� (���� - Path
�������: 0 - �������; -1 - ���� �� ��������*/
int SaveProduct(Product CurrentProduct, char* Path);
/*������� ������ � ������ �� ����� (���� - Path)
�������: 0 - �������; -1 - ����� �� ���������� ��� ����������*/
int ReadProductFromFile(Product* CurrentProduct, char* Path);
/*�������� ���� ������. ������� - ����� ����*/
int SetPriceOfProduct(Product* CurrentProduct, int NewPrice);
/*�������� ����� ���� ������. ������� - ����� ����� ���� ������*/
int SetCountOfProduct(Product* CurrentProduct, int NewCount);