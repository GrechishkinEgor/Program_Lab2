#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define PRINTER_TYPE_OF_PRINT_SIZE 64
class Printer : public Product
{
private:
	char TypeOfPrint[PRINTER_TYPE_OF_PRINT_SIZE];	//Матричный/струйный/лазерный
	int DPI;										//Разрешение
	int PaperFormat;								//Размер бумаги (А4, А5...)
public:
	Printer();
	Printer(Product General);
	Printer(Product General, const char* Type, int DPI, int PaperFormat);
	Printer(const Printer& Obj);
	~Printer();

	bool SetTypeOfPrint(const char* Type);
	bool SetDPI(int DPI);
	bool SetPaperFormat(int PaperFormat);

	void GetTypeOfPrint(char* Type);
	int GetDPI();
	int GetPaperFormat();

	void OutputAllInfo();

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