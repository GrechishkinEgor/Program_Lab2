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
/*Считать данные о товаре из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int ReadProductFromFile(Product* CurrentProduct, char* Path);