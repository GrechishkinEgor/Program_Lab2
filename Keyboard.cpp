#include "Keyboard.h"

Keyboard::Keyboard() : Product()
{
	this->TypeOfConnection[0] = '\0';
	this->LengthOfCable = 0;
	return;
}

Keyboard::Keyboard(Product General) : Product(General)
{
	this->TypeOfConnection[0] = '\0';
	this->LengthOfCable = 0;
	return;
}

Keyboard::Keyboard(Product General, const char* TypeOfConnection) : Keyboard(General)
{
	SetTypeOfConnection(TypeOfConnection);
	return;
}

Keyboard::Keyboard(Product General, const char* TypeOfConnection, int LengthOfCable) : Keyboard(General)
{
	SetTypeOfConnection(TypeOfConnection);
	SetLengthOfCable(LengthOfCable);
	return;
}

Keyboard::Keyboard(const Keyboard& Obj) : Product(Obj)
{
	SetTypeOfConnection(Obj.TypeOfConnection);
	SetLengthOfCable(Obj.LengthOfCable);
	return;
}

Keyboard::~Keyboard()
{
	return;
}

bool Keyboard::SetTypeOfConnection(const char* Type)
{
	if (Type != NULL && strlen(Type) < KEYBOARD_TYPE_OF_CONNECTION_SIZE)
	{
		strcpy(this->TypeOfConnection, Type);
		return true;
	}
	else
		return false;
}

bool Keyboard::SetLengthOfCable(int Length)
{
	if (Length >= 0)
	{
		this->LengthOfCable = Length;
		return true;
	}
	else
		return false;
}

void Keyboard::GetTypeOfConnection(char* Type)
{
	if (Type != NULL)
		strcpy(Type, this->TypeOfConnection);
	return;
}

int Keyboard::GetLengthOfCable()
{
	return this->LengthOfCable;
}

void Keyboard::OutputAllInfo()
{
	Product::OutputAllInfo();
	printf("Тип соединения: %s\n", this->TypeOfConnection);
	if (this->LengthOfCable > 0)
		printf("Длина кабеля: %d\n", this->LengthOfCable);
	return;
}

int Keyboard::Save(char* Path)
{
	if (Path != NULL)
	{
		FILE* Writer = fopen(Path, "wb");
		if (Writer != NULL)
		{
			this->WriteInFile(Writer);
			fclose(Writer);
			Writer = NULL;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

int Keyboard::SaveNew(char* Path)
{
	if (Path != NULL)
	{
		FILE* Check = fopen(Path, "rb");
		if (Check != NULL)
		{
			fclose(Check);
			Check = NULL;
			return -1;
		}
		else
			return this->Save(Path);
	}
	else
		return 0;
}

int Keyboard::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile == NULL)
		return 0;
	Product::WriteInFile(BinaryWriterFile);
	fwrite(this->TypeOfConnection, sizeof(this->TypeOfConnection), 1, BinaryWriterFile);
	fwrite(&this->LengthOfCable, sizeof(this->LengthOfCable), 1, BinaryWriterFile);
	return;
}

int Keyboard::Load(char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* Reader = fopen(Path, "rb");
	if (Reader != NULL)
	{
		this->ReadFromFile(Reader);
		fclose(Reader);
		Reader = NULL;
		return 1;
	}
	else
		return -1;
	return 0;
}

int Keyboard::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile == NULL)
		return 0;
	Product::ReadFromFile(BinaryReaderFile);
	fread(this->TypeOfConnection, sizeof(this->TypeOfConnection), 1, BinaryReaderFile);
	fread(&this->LengthOfCable, sizeof(this->LengthOfCable), 1, BinaryReaderFile);
	return;
}
