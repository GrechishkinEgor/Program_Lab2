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
	Printer(Product General, std::string Type, int DPI, int PaperFormat);
	Printer(const Printer& Obj);
	~Printer();

	bool SetTypeOfPrint(const char* Type);
	bool SetTypeOfPrint(std::string Type);
	bool SetDPI(int DPI);
	bool SetPaperFormat(int PaperFormat);

	void GetTypeOfPrint(char* Type);
	std::string GetTypeOfPrint();
	int GetDPI();
	int GetPaperFormat();

	void OutputAllInfo();

	/*Записывает данные в открытый для записи бинарный поток.
	Возврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*Прочитать содержимое бинарного потока, открытого на чтение
	Возврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile);
};