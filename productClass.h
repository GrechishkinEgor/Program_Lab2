#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PRODUCT_NAME_MAX_SIZE 64
#define PRODUCT_COMPANY_MAX_SIZE 64
#define PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE 64
#define PRODUCT_STRING_IDENTIFICATOR "Product"
class product {
private:
protected:
	char Name[PRODUCT_NAME_MAX_SIZE];
	char Company[PRODUCT_COMPANY_MAX_SIZE];
	int Price;
	int Count;
	
	/*����� �������� ��� ������. ���������������� ������ � ������������. 
	������������ ��� ������ � ���� � �������-�����������*/
	char StringIdentificator[PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE];
	/*���������� ���������� � ������ � �������� �����, �������� �� ������. 
	����� �������� � ������� �������-�����������, ������������ ���������� � ����.
	�������: ����, ���� ��������� �������, ����� ������.
	��� �������� �������� ����������� ����� ReadFromFile()*/
	bool WriteInFile(FILE* BinaryWriteOnlyFile);
	/*��������� ���������� � ������ �� ��������� ������, ��������� �� ������.
	����� �������� � ������� �������-�����������, ����������� ���������� �� �����.
	�������: ����, ���� ��������� �������, ����� ������
	��� �������� �������� ����������� ����� WriteInFile()*/
	bool ReadFromFile(FILE* BinaryReadOnlyFile);
public:
	product(void);
	product(char* Name);
	product(char* Name, char* Company);
	product(char* Name, char* Company, int Price, int Count);
	product(char* Name, char* Company, int Price);
	product(char* Name, int Price);
	product(const product& obj);
	~product();

	bool SetName(char* Name);
	bool SetCompany(char* Company);
	bool SetPrice(int Price);
	bool SetCount(int Count);

	void GetName(char Name[PRODUCT_NAME_MAX_SIZE]);
	void GetCompany(char Company[PRODUCT_COMPANY_MAX_SIZE]);
	int GetPrice();
	int GetCount();
	void GetStringIdentificator(char Identificator[PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE]);

	/*����������� ���������� ������ �� �������. �������: ������ - �������, ���� - ���������� ���������� ����������*/
	bool IncreaseCount();
	/*��������� ���������� ������ �� �������. �������: ������ - �������, ���� - ���������� ���������� ����������*/
	bool DecreaseCount();
	/*������� ��� ���������� � ������ �� �����*/
	void OutputAllInfo();
	/*���� ���� ���������� � ������*/
	void InputAllInfo();
};