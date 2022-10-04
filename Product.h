#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PRODUCT_NAME_MAX_SIZE 64
#define PRODUCT_COMPANY_MAX_SIZE 64
class Product {
private:
protected:
	char Name[PRODUCT_NAME_MAX_SIZE];
	char Company[PRODUCT_COMPANY_MAX_SIZE];
	int Price;
	int Count;
public:
	Product();
	Product(char* Name, char* Company, int Price);
	Product(char* Name, char* Company, int Price, int Count);
	Product(const Product& Obj);
	~Product();

	bool SetName(const char* Name);
	bool SetCompany(const char* Company);
	bool SetPrice(int Price);
	bool SetCount(int Count);

	void GetName(char* Name);
	void GetCompany(char* Company);
	int GetPrice();
	int GetCount();

	bool IncreaseCount();
	bool DecreaseCount();

	void OutputAllInfo();

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