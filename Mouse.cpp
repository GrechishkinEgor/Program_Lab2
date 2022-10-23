#include "Mouse.h"

Mouse::Mouse() : Product()
{
	this->TypeOfConnection[0] = '\0';
	this->LengthOfCable = 0;
	this->Sensitivity = 0;
	this->CountOfButtons = 0;
	return;
}

Mouse::Mouse(Product General) : Product(General)
{
	this->TypeOfConnection[0] = '\0';
	this->LengthOfCable = 0;
	this->Sensitivity = 0;
	this->CountOfButtons = 0;
	return;
}

Mouse::Mouse(Product General, int Sensitivity, int CountButtons, const char* TypeOfConnection) : Mouse(General)
{
	this->SetSensitivity(Sensitivity);
	this->SetCountOfButtons(CountButtons);
	this->SetTypeOfConnection(TypeOfConnection);
	return;
}

Mouse::Mouse(Product General, int Sensitivity, int CountButtons, const char* TypeOfConnection, int LengthOfCable) : Mouse(General, Sensitivity, CountButtons, TypeOfConnection)
{
	this->SetLengthOfCable(LengthOfCable);
	return;
}

Mouse::Mouse(const Mouse& Obj) : Product(Obj)
{
	this->SetSensitivity(Obj.Sensitivity);
	this->SetCountOfButtons(Obj.CountOfButtons);
	this->SetTypeOfConnection(Obj.TypeOfConnection);
	this->SetLengthOfCable(Obj.LengthOfCable);
	return;
}

Mouse::~Mouse()
{
	return;
}

bool Mouse::SetTypeOfConnection(const char* Type)
{
	if (Type != NULL && strlen(Type) < MOUSE_TYPE_OF_CONNECTION_SIZE)
	{
		strcpy(this->TypeOfConnection, Type);
		return true;
	}
	else
		return false;
}

bool Mouse::SetLengthOfCable(int Length)
{
	if (Length >= 0)
	{
		this->LengthOfCable = Length;
		return true;
	}
	else
		return false;
}

bool Mouse::SetSensitivity(int Sensitivity)
{
	if (Sensitivity >= 0)
	{
		this->Sensitivity = Sensitivity;
		return true;
	}
	else
		return false;
}

bool Mouse::SetCountOfButtons(int Count)
{
	if (Count >= 0)
	{
		this->Count = Count;
		return true;
	}
	else
		return false;
}

void Mouse::GetTypeOfConnection(char* Type)
{
	if (Type != NULL)
		strcpy(Type, this->TypeOfConnection);
	return;
}

int Mouse::GetLengthOfCable()
{
	return this->LengthOfCable;
}

int Mouse::GetSensitivity()
{
	return this->Sensitivity;
}

int Mouse::GetCountOfButtons()
{
	return this->CountOfButtons;
}

void Mouse::OutputAllInfo()
{
	Product::OutputAllInfo();
	printf("Тип соединения: %s\n", this->TypeOfConnection);
	if (this->LengthOfCable > 0)
		printf("Длина кабеля (см): %d\n", this->LengthOfCable);
	printf("Разрешение датчика (dpi): %d\n", this->Sensitivity);
	printf("Количество кнопок: %d\n", this->CountOfButtons);
	return;
}

int Mouse::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile == NULL)
		return 0;
	Product::WriteInFile(BinaryWriterFile);
	fwrite(this->TypeOfConnection, sizeof(this->TypeOfConnection), 1, BinaryWriterFile);
	fwrite(&this->LengthOfCable, sizeof(this->LengthOfCable), 1, BinaryWriterFile);
	fwrite(&this->Sensitivity, sizeof(this->Sensitivity), 1, BinaryWriterFile);
	fwrite(&this->CountOfButtons, sizeof(this->CountOfButtons), 1, BinaryWriterFile);
	return 1;
}

int Mouse::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile == NULL)
		return 0;
	Product::ReadFromFile(BinaryReaderFile);
	fread(this->TypeOfConnection, sizeof(this->TypeOfConnection), 1, BinaryReaderFile);
	fread(&this->LengthOfCable, sizeof(this->LengthOfCable), 1, BinaryReaderFile);
	fread(&this->Sensitivity, sizeof(this->Sensitivity), 1, BinaryReaderFile);
	fread(&this->CountOfButtons, sizeof(this->CountOfButtons), 1, BinaryReaderFile);
	return 1;
}
