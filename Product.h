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

	static long long int TotalCost;	//���������� ��������� ���� �������
public:
	Product();
	Product(const char* Name, const char* Company, int Price);
	Product(std::string Name, std::string Company, int Price);
	Product(const char* Name, const char* Company, int Price, int Count);
	Product(std::string Name, std::string Company, int Price, int Count);
	Product(const Product& Obj);
	~Product();

	bool SetName(const char* Name);
	bool SetName(std::string Name);
	bool SetCompany(const char* Company);
	bool SetCompany(std::string Company);
	bool SetPrice(int Price);
	bool SetCount(int Count);
	bool IncreaseCount();
	bool DecreaseCount();

	void GetName(char* Name);
	std::string GetName();
	void GetCompany(char* Company);
	std::string GetCompany();
	int GetPrice();
	int GetCount();
	void OutputAllInfo();

	/*��������� ��������� ������ � ���������� ��������� ���� �������
	�������: ������, ���� �������; ����, ���� ��������� ������ (���������� ��������� �� ���������)*/
	bool AddInTotalCost();
	static long long int GetTotalCost();
	static void ResetTotalCost();	//������������� ���������� ��������� � 0
	/*������� ���������� ��������� ������� �� ������� � ��������� � � ���������� ��������� ���� �������. 
	�������: ������, ���� �������. � ���� ������ ����������� ��������� ����������� � ���������� ���������; 
	����, ���� ��������� ������ - ���������� ��������� �������� ��� ���������*/
	static bool CalculateTotalCost(Product* ArrayOfProduct, int Size);

	int operator++();
	int operator++(int);
	int operator--();
	int operator--(int);
	int operator+(Product obj);
	int operator+(int Num);
	friend int operator+ (int Num, Product obj);

	/*��������� ������ � ���� (���� - Path)
	�������: 1 - �������; 0 - ���� �� ��������*/
	int Save(const char* Path);
	int Save(std::string Path);
	/*���������� ������ � ����� ����.
	�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ����������*/
	int SaveNew(const char* Path);
	int SaveNew(std::string Path);
	/*���������� ������ � �������� ��� ������ �������� �����. 
	�������: 1 - �������; 0 - ������� ������� ��������� �� �����*/
	virtual int WriteInFile(FILE* BinaryWriterFile);
	/*�������: 1 - �������; 0 - ��������� ������ (������� ������� ��������� ���� �����); -1 - ���� �� ������*/
    int Load(const char* Path);
	int Load(std::string Path);
	/*��������� ���������� ��������� ������, ��������� �� ������
	�������: 0 - ������� ������� ��������� �� �����; 1 - �������*/
	virtual int ReadFromFile(FILE* BinaryReaderFile);
};
