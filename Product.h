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

	static int TotalCount;
	static bool EditTotalCount(int PreviousCount, int CurrentCount);
public:
	Product();
	Product(const char* Name, const char* Company, int Price);
	Product(const char* Name, const char* Company, int Price, int Count);
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
	friend void OutputTableOfProduct(Product* List, int size);

	int operator++();
	int operator++(int);
	int operator--();
	int operator--(int);

	static int GetTotalCount();

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

void OutputTableOfProduct(Product* List, int size);