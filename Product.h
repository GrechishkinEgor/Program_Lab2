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

/*Инициализаторы*/
Product InitProduct();
Product InitProduct(char* Name, char* Company, int Price);
Product InitProduct(char* Name, char* Company, int Price, int Count);

int SetProductName(Product* CurrentProduct, char* Name);
int SetProductCompany(Product* CurrentProduct, char* Company);
int SetProductPrice(Product* CurrentProduct, int Price);
int SetProductCount(Product* CurrentProduct, int Count);

void GetProductName(Product CurrentProduct, char* Name);
void GetProductCompany(Product CurrentProduct, char* Company);
int GetProductPrice(Product CurrentProduct);
int GetProductCount(Product CurrentProduct);

/*Увеличивает на один количество товара. Возврат - количество товара после увеличения*/
int IncreaseCountOfProduct(Product* CurrentProduct);
/*Уменьшает на один количество товара. Возврат - количество товара после уменьшения*/
int DecreaseCountOfProduct(Product* CurrentProduct);

/*Выводит всю информацию о товаре на экран*/
void OutputAllInfoAboutProduct(Product CurrentProduct);

/*Сохраняет информацию о товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся*/
int SaveProduct(Product CurrentProduct, char* Path);
/*Сохраняет информацию о новом товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл уже существует*/
int SaveNewProduct(Product CurrentProduct, char* Path);
/*Записывает данные о товаре в открытый для записи бинарный поток
Возврат: 1 - данные были записаны; 0 - передан нулевой указатель на поток*/
int WriteProductInFile(Product CurrentProduct, FILE* BinaryWriterFile);

/*Считать данные о товаре из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int LoadProduct(Product* CurrentProduct, char* Path);
/*Считывает данные о товаре из бинарного потока, открытого на чтение
Возврат: 1 - успешно; -1 - достигнут конец потока; 0 - передан нулевой указатель на файл или структуру*/
int ReadProductFromFile(Product* CurrentProduct, FILE* BinaryReaderFile);

