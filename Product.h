#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PRODUCT_NAME_MAX_SIZE 64
#define PRODUCT_COMPANY_MAX_SIZE 64
typedef struct {
	char Name[PRODUCT_NAME_MAX_SIZE];
	char Company[PRODUCT_COMPANY_MAX_SIZE];
	int Price;
	int Count;
}Product;

/*��������������*/
Product InitProduct();
Product InitProduct(char* Name, char* Company, int Price);
Product InitProduct(char* Name, char* Company, int Price, int Count);

int SetProductName(Product* CurrentProduct, char* Name);
int SetProductCompany(Product* CurrentProduct, char* Company);
int SetProductPrice(Product* CurrentProduct, int Price);
int SetProductCount(Product* CurrentProduct, int Count);

/*����������� �� ���� ���������� ������. ������� - ���������� ������ ����� ����������*/
int IncreaseCountOfProduct(Product* CurrentProduct);
/*��������� �� ���� ���������� ������. ������� - ���������� ������ ����� ����������*/
int DecreaseCountOfProduct(Product* CurrentProduct);
/*������� ��� ���������� � ������ �� �����*/
void OutputAllInfoAboutProduct(Product CurrentProduct);
/*��������� ���������� � ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������*/
int SaveProduct(Product CurrentProduct, char* Path);
/*��������� ���������� � ����� ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ��� ����������*/
int SaveNewProduct(Product CurrentProduct, char* Path);
/*������� ������ � ������ �� ����� (���� - Path)
�������: 1 - �������; 0 - ����� �� ���������� ��� ����������; -1 - ������� ������� ��������� �� ���������*/
int ReadProductFromFile(Product* CurrentProduct, char* Path);