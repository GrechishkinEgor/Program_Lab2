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

	/*Сохраняет данные в файл (путь - Path)
	Возврат: 1 - успешно; 0 - файл не открылся*/
	int Save(const char* Path);
	/*Записывает данные в новый файл.
	Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл существует*/
	int SaveNew(const char* Path);
	/*Записывает данные в открытый для записи бинарный поток. 
	Возврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*Возврат: 1 - успешно; 0 - передан нулевой указатели пути файла; -1 - файл не найден*/
	int Load(const char* Path);
	/*Прочитать содержимое бинарного потока, открытого на чтение
	Возврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile);
};

void OutputTableOfProduct(Product* List, int size);