#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
typedef struct {
	Product General;
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;											//Длина кабеля в метрах (если нет кабеля - равно 0)
}Keyboard;

Keyboard InitKeyboard();
Keyboard InitKeyboard(Product General);
Keyboard InitKeyboard(Product General, char* TypeOfConnection, int LengthOfCable);

int SetKeyboardGeneral(Keyboard* CurrentKeyboard, Product General);
int SetKeyboardTypeOfConnection(Keyboard* CurrentKeyboard, char* Type);
int SetKeyboardLengthOfCable(Keyboard* CurrentKeyboard, int Length);

Product GetKeyboardGeneral(Keyboard CurrentKeyboard);
void GetKeyboardTypeOfConnection(Keyboard CurrentKeyboard, char* Type);
int GetKeyboardLengthOfCable(Keyboard CurrentKeyboard);

void OutputAllInfoAboutKeyboard(Keyboard CurrentKeyboard);

/*Сохраняет информацию о товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся*/
int SaveKeyboard(Keyboard CurrentProduct, char* Path);
/*Сохраняет информацию о новом товаре в файл (путь - Path)
Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл уже существует*/
int SaveNewKeyboard(Keyboard CurrentProduct, char* Path);
/*Записывает данные о товаре в открытый для записи бинарный поток
Возврат: 1 - данные были записаны; 0 - передан нулевой указатель на поток*/
int WriteKeyboardInFile(Keyboard CurrentProduct, FILE* BinaryWriterFile);

/*Считать данные о товаре из файла (путь - Path)
Возврат: 1 - успешно; 0 - файла не существует или недоступен; -1 - передан нулевой указатель на структуру*/
int LoadKeyboard(Keyboard* CurrentProduct, char* Path);
/*Считывает данные о товаре из бинарного потока, открытого на чтение
Возврат: 1 - успешно; -1 - достигнут конец потока; 0 - передан нулевой указатель на файл или структуру*/
int ReadKeyboardFromFile(Keyboard* CurrentProduct, FILE* BinaryReaderFile);