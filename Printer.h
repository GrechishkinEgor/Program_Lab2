#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PRINTER_TYPE_OF_PRINT_SIZE 64
typedef struct {
	char TypeOfPrint[PRINTER_TYPE_OF_PRINT_SIZE];	//Матричный/струйный/лазерный
	int DPI;										//Разрешение
	int PaperFormat;								//Размер бумаги (А4, А5...)
}Printer;

Printer InitPrinter();
Printer InitPrinter(char* Type, int DPI, int PaperFormat);

void OutputAllInfoAboutPrinter(Printer CurrentPrinter);
void InputAllInfoAboutPrinter(Printer* CurrentPrinter);