#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
class Mouse : public Product
{
private:
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//Проводная/беспроводная
	int LengthOfCable;										//Длина кабеля в сантиметрах (если нет кабеля - равно 0)
	int Sensitivity;										//Чувствительность (разрешение датчика) - dpi
	int CountOfButtons;										//Количество кнопок

public:
	Mouse();
	Mouse(Product General);
	Mouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection);
	Mouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable);
	Mouse(const Mouse& Obj);
	~Mouse();

	bool SetTypeOfConnection(const char* Type);
	bool SetLengthOfCable(int Length);
	bool SetSensitivity(int Sensitivity);
	bool SetCountOfButtons(int Count);

	void GetTypeOfConnection(char* Type);
	int GetLengthOfCable();
	int GetSensitivity();
	int GetCountOfButtons();

	void OutputAllInfo();

	/*Сохраняет данные в файл (путь - Path)
	Возврат: 1 - успешно; 0 - файл не открылся*/
	int Save(char* Path);
	/*Записывает данные в новый файл.
	Возврат: 1 - успешно; 0 - файл не открылся; -1 - файл существует*/
	int SaveNew(char* Path);
	/*Записывает данные в открытый для записи бинарный поток.
	Возврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*Возврат: 1 - успешно; 0 - передан нулевой указатели пути файла; -1 - файл не найден*/
	int Load(char* Path);
	/*Прочитать содержимое бинарного потока, открытого на чтение
	Возврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile);
};