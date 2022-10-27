#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

#define MOUSE_TYPE_OF_CONNECTION_SIZE 64
class Mouse : public Product
{
private:
	char TypeOfConnection[MOUSE_TYPE_OF_CONNECTION_SIZE];	//ѕроводна€/беспроводна€
	int LengthOfCable;										//ƒлина кабел€ в сантиметрах (если нет кабел€ - равно 0)
	int Sensitivity;										//„увствительность (разрешение датчика) - dpi
	int CountOfButtons;										// оличество кнопок

public:
	Mouse();
	Mouse(Product General);
	Mouse(Product General, int Sensitivity, int CountButtons, const char* TypeOfConnection);
	Mouse(Product General, int Sensitivity, int CountButtons, std::string TypeOfConnection);
	Mouse(Product General, int Sensitivity, int CountButtons, const char* TypeOfConnection, int LengthOfCable);
	Mouse(Product General, int Sensitivity, int CountButtons, std::string TypeOfConnection, int LengthOfCable);
	Mouse(const Mouse& Obj);
	~Mouse();

	bool SetTypeOfConnection(const char* Type);
	bool SetTypeOfConnection(std::string Type);
	bool SetLengthOfCable(int Length);
	bool SetSensitivity(int Sensitivity);
	bool SetCountOfButtons(int Count);

	char* GetTypeOfConnection(char* Type);
	std::string GetTypeOfConnection();
	int GetLengthOfCable();
	int GetSensitivity();
	int GetCountOfButtons();

	void OutputAllInfo();

	/*«аписывает данные в открытый дл€ записи бинарный поток.
	¬озврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile) override;
	
	/*ѕрочитать содержимое бинарного потока, открытого на чтение
	¬озврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile) override;
};