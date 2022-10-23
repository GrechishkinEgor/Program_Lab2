#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define KEYBOARD_TYPE_OF_CONNECTION_SIZE 64
class Keyboard : public Product {
private:
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_SIZE];	//ѕроводна€/беспроводна€
	int LengthOfCable;											//ƒлина кабел€ в метрах (если нет кабел€ - равно 0)
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

	/*«аписывает данные в открытый дл€ записи бинарный поток.
	¬озврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile);
	/*ѕрочитать содержимое бинарного потока, открытого на чтение
	¬озврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile);
};
