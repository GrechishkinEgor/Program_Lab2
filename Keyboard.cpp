#include "Keyboard.h"

Keyboard InitKeyboard()
{
	Keyboard Init;
	Init.TypeOfConnection[0] = '\0';
	Init.LengthOfCable = 0;
	Init.General = InitProduct();
	return Init;
}

Keyboard InitKeyboard(Product General)
{
	Keyboard Init = InitKeyboard();
	SetKeyboardGeneral(&Init, General);
	return Init;
}

Keyboard InitKeyboard(Product General, char* TypeOfConnection, int LengthOfCable)
{
	Keyboard Init = InitKeyboard(General);
	SetKeyboardTypeOfConnection(&Init, TypeOfConnection);
	SetKeyboardLengthOfCable(&Init, LengthOfCable);
	return Init;
}

int SetKeyboardGeneral(Keyboard* CurrentKeyboard, Product General)
{
	if (CurrentKeyboard != NULL)
	{
		CurrentKeyboard->General = General;
		return 1;
	}
	else
		return 0;
}

int SetKeyboardTypeOfConnection(Keyboard* CurrentKeyboard, char* Type)
{
	if (CurrentKeyboard != NULL && Type != NULL && strlen(Type) < KEYBOARD_TYPE_OF_CONNECTION_SIZE)
	{
		strcpy(CurrentKeyboard->TypeOfConnection, Type);
		return 1;
	}
	else
		return 0;
}

int SetKeyboardLengthOfCable(Keyboard* CurrentKeyboard, int Length)
{
	if (CurrentKeyboard != NULL)
	{
		CurrentKeyboard->LengthOfCable = Length;
		return 1;
	}
	else
		return 0;
}

Product GetKeyboardGeneral(Keyboard CurrentKeyboard)
{
	return CurrentKeyboard.General;
}

void GetKeyboardTypeOfConnection(Keyboard CurrentKeyboard, char* Type)
{
	if (Type != NULL)
		strcpy(Type, CurrentKeyboard.TypeOfConnection);
	return;
}

int GetKeyboardLengthOfCable(Keyboard CurrentKeyboard)
{
	return CurrentKeyboard.LengthOfCable;
}

Keyboard InitKeyboard(char* TypeOfConnection, int LengthOfCable)
{
	Keyboard Init = InitKeyboard();
	if (TypeOfConnection != NULL && strlen(TypeOfConnection) < KEYBOARD_TYPE_OF_CONNECTION_SIZE)
		strcpy(Init.TypeOfConnection, TypeOfConnection);
	if (LengthOfCable > 0)
		Init.LengthOfCable = LengthOfCable;
	return Init;
}

void OutputAllInfoAboutKeyboard(Keyboard CurrentKeyboard)
{
	OutputAllInfoAboutProduct(CurrentKeyboard.General);
	printf("Тип соединения: %s\n", CurrentKeyboard.TypeOfConnection);
	if (CurrentKeyboard.LengthOfCable > 0)
		printf("Длина кабеля: %d\n", CurrentKeyboard.LengthOfCable);
	return;
}


int SaveKeyboard(Keyboard CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* FileOfProduct = fopen(Path, "wb");
	if (FileOfProduct != NULL)
	{
		WriteKeyboardInFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int SaveNewKeyboard(Keyboard CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* NewProduct = fopen(Path, "rb");
	if (NewProduct != NULL)
	{
		fclose(NewProduct);
		NewProduct = NULL;
		return -1;
	}
	else
		return SaveKeyboard(CurrentProduct, Path);
}

int WriteKeyboardInFile(Keyboard CurrentProduct, FILE* BinaryWriterFile)
{
	if (BinaryWriterFile != NULL)
	{
		fwrite(&CurrentProduct, sizeof(Keyboard), 1, BinaryWriterFile);
		return 1;
	}
	else
		return 0;
}

int LoadKeyboard(Keyboard* CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	if (CurrentProduct == NULL)
		return -1;

	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct != NULL)
	{
		ReadKeyboardFromFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int ReadKeyboardFromFile(Keyboard* CurrentProduct, FILE* BinaryReaderFile)
{
	if (CurrentProduct == NULL || BinaryReaderFile == NULL)
		return 0;
	if (fread(CurrentProduct, sizeof(Keyboard), 1, BinaryReaderFile) == 1)
		return 1;
	else
		return -1;
}