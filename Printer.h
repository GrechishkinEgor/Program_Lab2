#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define PRINTER_TYPE_OF_PRINT_SIZE 64
typedef struct {
	Product General;
	char TypeOfPrint[PRINTER_TYPE_OF_PRINT_SIZE];	//Матричный/струйный/лазерный
	int DPI;										//Разрешение
	int PaperFormat;								//Размер бумаги (А4, А5...)
}Printer;

Printer InitPrinter();
Printer InitPrinter(Product General);
Printer InitPrinter(Product General, char* Type, int DPI, int PaperFormat);

int SetPrinterTypeOfPrint(Printer* CurrentPrinter, char* TypeOfPrint);
int SetPrinterDPI(Printer* CurrentPrinter, int DPI);
int SetPrinterPaperFormat(Printer* CurrentPrinter, int PaperFormat);
int SetPrinterGeneral(Printer* CurrentPrinter, Product General);

void GetPrinterTypeOfPrint(Printer CurrentPrinter, char* TypeOfPrint);
int GetPrinterDPI(Printer CurrentPrinter);
int GetPrinterPaperFormat(Printer CurrentPrinter);
Product GetPrinterGeneral(Printer CurrentPrinter);

/*Вывод всей информации о CurrentPrinter на экран*/
void OutputAllInfoAboutPrinter(Printer CurrentPrinter);

/*Сохраняет информацию о принтере в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся*/
int SavePrinter(Printer CurrentProduct, char* Path);
/*Сохраняет информацию о новом принтере в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл уже существует*/
int SaveNewPrinter(Printer CurrentProduct, char* Path);
/*Записывает данные о принтере в открытый для записи бинарный поток
Возврат: 1 - данные были записаны; 0 - передан нулевой указатель на поток*/
int WritePrinterInFile(Printer CurrentProduct, FILE* BinaryWriterFile);

/*Считать данные о принтере из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int LoadPrinter(Printer* CurrentProduct, char* Path);
/*Считывает данные о принтере из бинарного потока, открытого на чтение
Возврат: 1 - успешно; -1 - достигнут конец потока; 0 - передан нулевой указатель на файл или структуру*/
int ReadPrinterFromFile(Printer* CurrentProduct, FILE* BinaryReaderFile);