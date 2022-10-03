#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	Product General;
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;										//Длина кабеля в сантиметрах (если нет кабеля - равно 0)
	int Sensitivity;										//Чувствительность (разрешение датчика) - dpi
	int CountOfButtons;										//Количество кнопок
}Mouse;

Mouse InitMouse();
Mouse InitMouse(Product General);
Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection);

int SetMouseTypeOfConnection(Mouse* CurrentMouse, char* TypeOfConnection);
int SetMouseLengthOfCable(Mouse* CurrentMouse, int LenghtOfCable);
int SetMouseSensitivity(Mouse* CurrentMouse, int Sensitivity);
int SetMouseCountOfButtons(Mouse* CurrentMouse, int Count);

void GetMouseTypeOfConnection(Mouse CurrentMouse, char* TypeOfConnection);
int GetMouseLenghtOfCable(Mouse CurrentMouse);
int GetMouseSensitivity(Mouse CurrentMouse);
int GetMouseCountOfButtons(Mouse CurrentMouse);

/*Вывод всей информации о мыши на экран*/
void OutputAllInfoAboutMouse(Mouse CurrentMouse);

/*Сохраняет информацию в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся*/
int SaveMouse(Mouse CurrentProduct, char* Path);
/*Сохраняет информацию в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл уже существует*/
int SaveNewMouse(Mouse CurrentProduct, char* Path);
/*Записывает данные в открытый для записи бинарный поток
Возврат: 1 - данные были записаны; 0 - передан нулевой указатель на поток*/
int WriteMouseInFile(Mouse CurrentProduct, FILE* BinaryWriterFile);

/*Считать данные из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int LoadMouse(Mouse* CurrentProduct, char* Path);
/*Считывает данные из бинарного потока, открытого на чтение
Возврат: 1 - успешно; -1 - достигнут конец потока; 0 - передан нулевой указатель на файл или структуру*/
int ReadMouseFromFile(Mouse* CurrentProduct, FILE* BinaryReaderFile);