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
	
	/*Здесь хранится тип товара. Инициализируется строго в конструкторе. 
	Используется для записи в файл в классах-наследниках*/
	char StringIdentificator[PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE];
	/*Записывает информацию о товаре в бинарный поток, открытый на запись. 
	Можно вызывать в методах классов-наследников, записывающих информацию в файл.
	Возврат: ложь, если указатель нулевой, иначе истина.
	Для обратной операции используйте метод ReadFromFile()*/
	bool WriteInFile(FILE* BinaryWriteOnlyFile);
	/*Считывает информацию о товаре из бинарного потока, открытого на чтение.
	Можно вызывать в методах классов-наследников, считывающих информацию из файла.
	Возврат: ложь, если указатель нулевой, иначе истина
	Для обратной операции используйте метод WriteInFile()*/
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

	/*Увеличивает количество товара на единицу. Возврат: истина - успешно, ложь - дальнейшее увеличение невозможно*/
	bool IncreaseCount();
	/*Уменьшает количество товара на единицу. Возврат: истина - успешно, ложь - дальнейшее уменьшение невозможно*/
	bool DecreaseCount();
	/*Выводит всю информацию о товаре на экран*/
	void OutputAllInfo();
	/*Ввод всей информации о товаре*/
	void InputAllInfo();
};