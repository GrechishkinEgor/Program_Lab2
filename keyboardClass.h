#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "productClass.h"

#define KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE 64
#define KEYBOARD_STRING_IDENTIFICATOR "Keyboard"
class keyboard : public product {
private:
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE];
	int LengthOfCable;
public:
	keyboard();
	keyboard(char* Name);
	keyboard(char* Name, char* Company);
	keyboard(char* Name, char* Company, int Price);
	keyboard(char* Name, char* Company, int Price, int Count);
	keyboard(char* Name, int Price);
	keyboard(product General, char* TypeOfConnection, int LengthOfCable);
	keyboard(const keyboard& obj);
	~keyboard();

	bool SetTypeOfConnection(char* Type);
	bool SetLengthOfCable(int Length);

	void GetTypeOfConnection(char Type[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE]);
	int GetLengthOfCable();

	/*Выводит всю информацию на экран*/
	void OutputAllInfo();
	/*Ввод всей информации о клавиатуре*/
	void InputAllInfo();
	/*Сохраняет всю информацию в файл (путь - Path).
	Возврат: 1 - запись прошла успешно; 0 - файл не открылся*/
	int SaveInFile(char* Path);
	/*Сохраняет информацию в новый файл (путь - Path)
	Возврат: 1 - запись прошла успешно; 0 - файл не открылся; -1 - файл уже существует; -2 - нулевой указатель пути*/
	int SaveInNewFile(char* Path);
	/*Считывает информацию из файла (путь - Path).
	Возврат: 1 - успешно; 0 - файл не открылся; -1 - информация соответствует иному классу (иной идентификатор класса)*/
	int ReadFromFile(char* Path);
};