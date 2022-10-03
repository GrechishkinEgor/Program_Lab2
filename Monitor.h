#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

typedef struct {
	Product General;
	int Diagonal;		//Диагональ матрицы в дюймах
	int Frequency;		//Частота обновления экрана монитора в герцах
	int Size[2];		//Разрешение экрана (число пикселей по горизонтали и вертикали)
	int AspectRatio[2];	//Соотношение сторон (16:9/16:10...)
}Monitor;

Monitor InitMonitor();
Monitor InitMonitor(Product General);
Monitor InitMonitor(Product General, int Diagonal, int Frequency, int Size[2], int AspectRatio[2]);

int SetMonitorGeneral(Monitor* CurrentMonitor, Product General);
int SetMonitorDiagonal(Monitor* CurrentMonitor, int Diagonal);
int SetMonitorFrequency(Monitor* CurrentMonitor, int Frequency);
int SetMonitorSize(Monitor* CurrentMonitor, int Width, int Height);
int SetMonitorAspectRatio(Monitor* CurrentMonitor, int AspectRatio1, int AspectRatio2);

Product GetMonitorGeneral(Monitor CurrentMonitor);
int GetMonitorDiagonal(Monitor CurrentMonitor);
int GetMonitorFrequency(Monitor CurrentMonitor);
void GetMonitorSize(Monitor CurrentMonitor, int* Width, int* Height);
void GetMonitorAspectRatio(Monitor CurrentMonitor, int* AspectRatio1, int* AspectRatio2);

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor);

/*Сохраняет информацию о товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся*/
int SaveMonitor(Monitor CurrentProduct, char* Path);
/*Сохраняет информацию о новом товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл уже существует*/
int SaveNewMonitor(Monitor CurrentProduct, char* Path);
/*Записывает данные о товаре в открытый для записи бинарный поток
Возврат: 1 - данные были записаны; 0 - передан нулевой указатель на поток*/
int WriteMonitorInFile(Monitor CurrentProduct, FILE* BinaryWriterFile);

/*Считать данные о товаре из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int LoadMonitor(Monitor* CurrentProduct, char* Path);
/*Считывает данные о товаре из бинарного потока, открытого на чтение
Возврат: 1 - успешно; -1 - достигнут конец потока; 0 - передан нулевой указатель на файл или структуру*/
int ReadMonitorFromFile(Monitor* CurrentProduct, FILE* BinaryReaderFile);