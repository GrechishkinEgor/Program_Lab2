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

	static long long int TotalCost;	//Совокупная стоимость всех товаров
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

	/*Добавляет стоимость товара к совокупной стоимости всех товаров
	Возврат: истина, если успешно; ложь, если произошла ошибка (совокупная стоимость не изменится)*/
	bool AddInTotalCost();
	static long long int GetTotalCost();
	static void ResetTotalCost();	//Устанавливает совокупную стоимость в 0
	/*Считает совокупную стоимость товаров из массива и добавляет её к совокупной стоимости всех товаров. 
	Возврат: истина, если успешно. В этом случае посчитанная стоимость добавляется к совокупной стоимости; 
	Ложь, если произошла ошибка - совокупная стоимость остается без изменений*/
	static bool CalculateTotalCost(Product* ArrayOfProduct, int Size);

	int operator++();
	int operator++(int);
	int operator--();
	int operator--(int);
	int operator+(Product obj);
	int operator+(int Num);
	friend int operator+ (int Num, Product obj);

	/*Сохраняет данные в файл (путь - Path)
	Возврат: 1 - успешно; 0 - файл не открылся*/
	int Save(const char* Path);
	int Save(std::string Path);
	/*Записывает данные в новый файл.
	Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл существует*/
	int SaveNew(const char* Path);
	int SaveNew(std::string Path);
	/*Записывает данные в открытый для записи бинарный поток. 
	Возврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	virtual int WriteInFile(FILE* BinaryWriterFile);
	/*Возврат: 1 - успешно; 0 - произошла ошибка (передан нулевой указатель пути файла); -1 - файл не найден*/
    int Load(const char* Path);
	int Load(std::string Path);
	/*Прочитать содержимое бинарного потока, открытого на чтение
	Возврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	virtual int ReadFromFile(FILE* BinaryReaderFile);
};
