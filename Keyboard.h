#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
class Keyboard : public Product {
private:
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;											//Длина кабеля в метрах (если нет кабеля - равно 0)
public:
	Keyboard();
	Keyboard(Product General);
	Keyboard(Product General, const char* TypeOfConnection);
	Keyboard(Product General, const char* TypeOfConnection, int LengthOfCable);
	Keyboard(const Keyboard& Obj);
	~Keyboard();

	bool SetTypeOfConnection(const char* Type);
	bool SetLengthOfCable(int Length);

	void GetTypeOfConnection(char* Type);
	int GetLengthOfCable();

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
