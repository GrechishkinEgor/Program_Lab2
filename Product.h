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

	static int TotalCost;	//Совокупная стоимость всех товаров
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
	bool IncreaseCount();
	bool DecreaseCount();

	void GetName(char* Name);
	void GetCompany(char* Company);
	int GetPrice();
	int GetCount();
	void OutputAllInfo();

	/*Добавляет стоимость товара к совокупной стоимости всех товаров
	Возврат: истина, если успешно; ложь, если произошла ошибка (совокупная стоимость не изменится)*/
	bool AddInTotalCost();
	static int GetTotalCost();
	static void ResetTotalCost();	//Устанавливает совокупную стоимость в 0
	/*Считает совокупную стоимость товаров из массива и добавляет её к совокупной стоимости всех товаров. 
	Возврат: истина, если успешно. В этом случае посчитанная стоимость добавляется к совокупной стоимости; 
	Ложь, если произошла ошибка - совокупная стоимость остается без изменений*/
	static bool CalculateTotalCost(Product* ArrayOfProduct, int Size);

	friend void OutputTableOfProduct(Product* List, int size);

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