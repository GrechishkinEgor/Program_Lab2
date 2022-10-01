#include "keyboardClass.h"

keyboard::keyboard() : product()
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(char* Name) : product(Name)
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(char* Name, char* Company) : product(Name, Company)
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(char* Name, char* Company, int Price) : product(Name, Company, Price)
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(char* Name, char* Company, int Price, int Count) : product(Name, Company, Price, Count)
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(char* Name, int Price) : product(Name, Price)
{
	this->LengthOfCable = 0;
	this->TypeOfConnection[0] = '\0';
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(product General, char* TypeOfConnection, int LengthOfCable) : product(General)
{
	SetTypeOfConnection(TypeOfConnection);
	SetLengthOfCable(LengthOfCable);
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::keyboard(const keyboard& obj) : product(obj)
{
	strcpy(this->TypeOfConnection, obj.TypeOfConnection);
	this->LengthOfCable = obj.LengthOfCable;
	strcpy(this->StringIdentificator, KEYBOARD_STRING_IDENTIFICATOR);
	return;
}

keyboard::~keyboard()
{
	return;
}

bool keyboard::SetTypeOfConnection(char* Type)
{
	if (Type != NULL && strlen(Type) < KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE)
	{
		strcpy(this->TypeOfConnection, Type);
		return true;
	}
	else
		return false;
}

bool keyboard::SetLengthOfCable(int Length)
{
	if (Length >= 0)
	{
		this->LengthOfCable = Length;
		return true;
	}
	else
		return false;
}

void keyboard::GetTypeOfConnection(char Type[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE])
{
	strcpy(Type, this->TypeOfConnection);
	return;
}

int keyboard::GetLengthOfCable()
{
	return this->LengthOfCable;
}

void keyboard::OutputAllInfo()
{
	product::OutputAllInfo();
	printf("Тип соединения: %s\n", this->TypeOfConnection);
	if (this->LengthOfCable > 0)
		printf("Длина кабеля (см): %d\n", this->LengthOfCable);
	return;
}

void keyboard::InputAllInfo()
{
	product::InputAllInfo();
	char TypeOfConnection[KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE] = "\0";
	while (strlen(TypeOfConnection) == 0)
	{
		printf("Введите тип соединения (проводная/беспроводная/...): ");
		scanf_s("%s", TypeOfConnection, KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE);
		while (getchar() != '\n');
		if (!SetTypeOfConnection(TypeOfConnection))
			TypeOfConnection[0] = '\0';
	}
	int LengthOfCable = -1;
	while (LengthOfCable < 0)
	{
		printf("Введите длину кабеля (в см; если нет кабеля - введите 0): ");
		scanf("%d", &LengthOfCable);
		while (getchar() != '\n');
		if (!SetLengthOfCable(LengthOfCable))
			LengthOfCable = -1;
	}
	return;
}

int keyboard::SaveInFile(char* Path)
{
	FILE* Writer = fopen(Path, "wb");
	if (Writer != NULL)
	{
		fwrite(StringIdentificator, PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE, 1, Writer);
		product::WriteInFile(Writer);
		fwrite(TypeOfConnection, KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE, 1, Writer);
		fwrite(&LengthOfCable, sizeof(int), 1, Writer);
		fclose(Writer);
		Writer = NULL;
		return 1;
	}
	else
		return 0;
}

int keyboard::SaveInNewFile(char* Path)
{
	if (Path == NULL)
		return -2;
	FILE* NewFile = fopen(Path, "rb");
	if (NewFile != NULL)
	{
		fclose(NewFile);
		NewFile = NULL;
		return -1;
	}
	return SaveInFile(Path);
}

int keyboard::ReadFromFile(char* Path)
{
	FILE* Reader = fopen(Path, "rb");
	if (Reader == NULL)
		return 0;
	char Identificator[PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE];
	fread(Identificator, PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE, 1, Reader);
	if (strcmp(Identificator, StringIdentificator))
	{
		product::ReadFromFile(Reader);
		fread(TypeOfConnection, KEYBOARD_TYPE_OF_CONNECTION_MAX_SIZE, 1, Reader);
		fread(&LengthOfCable, sizeof(int), 1, Reader);
		fclose(Reader);
		Reader = NULL;
		return 1;
	}
	else
	{
		fclose(Reader);
		Reader = NULL;
		return -1;
	}
	return 0;
}
