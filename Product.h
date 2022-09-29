#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Monitor.h"
#include "Printer.h"
#include "Mouse.h"
#include "Keyboard.h"

typedef enum {
	IsNotDefined,
	IsMouse,
	IsKeyboard,
	IsMonitor,
	IsPrinter,
}TypeOfProduct;

#define PRODUCT_NAME_SIZE 64
#define PRODUCT_COMPANY_SIZE 64
typedef struct {
	char Name[PRODUCT_NAME_SIZE];
	char Company[PRODUCT_COMPANY_SIZE];
	int Price;
	int Count;
	TypeOfProduct Type;
	union {
		Mouse AboutMouse;
		Keyboard AboutKeyboard;
		Monitor AboutMonitor;
		Printer AboutPrinter;
	}Information;
}Product;

/*Инициализаторы*/
Product InitProduct();
Product InitProduct(char* Name, char* Company, int Price);
Product InitProduct(char* Name, char* Company, int Price, Mouse Info);
Product InitProduct(char* Name, char* Company, int Price, Keyboard Info);
Product InitProduct(char* Name, char* Company, int Price, Monitor Info);
Product InitProduct(char* Name, char* Company, int Price, Printer Info);

/*Увеличивает на один количество товара. Возврат - количество товара после увеличения*/
int IncreaseCountOfProduct(Product* CurrentProduct);
/*Уменьшает на один количество товара. Возврат - количество товара после уменьшения*/
int DecreaseCountOfProduct(Product* CurrentProduct);
/*Выводит всю информацию о товаре на экран*/
void OutputAllInfoAboutProduct(Product CurrentProduct);
/*Ввод всей информации о товаре пользователем*/
void InputAllInfoAboutProduct(Product* CurrentProduct);
/*Записать информацию о товаре в новый файл (путь - Path)
Возврат: 0 - успешно; 1 - файл существует; -1 - файл не открылся*/
int WriteProductInFile(Product CurrentProduct, char* Path);
/*Сохраняет информацию о товаре в файл (путь - Path
Возврат: 0 - успешно; -1 - файл не открылся*/
int SaveProduct(Product CurrentProduct, char* Path);
/*Считать данные о товаре из файла (путь - Path)
Возврат: 0 - успешно; -1 - файла не существует или недоступен*/
int ReadProductFromFile(Product* CurrentProduct, char* Path);
/*Изменить цену товара. Возврат - новая цена*/
int SetPriceOfProduct(Product* CurrentProduct, int NewPrice);
/*Изменить число штук товара. Возврат - новое число штук товара*/
int SetCountOfProduct(Product* CurrentProduct, int NewCount);