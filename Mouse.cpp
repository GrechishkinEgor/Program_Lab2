#include "Mouse.h"

Mouse InitMouse()
{
	Mouse Init;
	Init.General = InitProduct();
	Init.TypeOfConnection[0] = '\0';
	Init.LengthOfCable = 0;
	Init.Sensitivity = 0;
	Init.CountOfButtons = 0;
	return Init;
}

Mouse InitMouse(Product General)
{
	Mouse Init = InitMouse();
	Init.General = General;
	return Init;
}

Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable)
{
	Mouse Init;
	Init = InitMouse(General, Sensitivity, CountButtons, TypeOfConnection);
	if (LengthOfCable > 0)
		Init.LengthOfCable = LengthOfCable;
	return Init;
}

Mouse InitMouse(Product General, int Sensitivity, int CountButtons, char* TypeOfConnection)
{
	Mouse Init = InitMouse();
	Init.General = General;
	if (Sensitivity >= 0)
		Init.Sensitivity = Sensitivity;
	if (CountButtons >= 0)
		Init.CountOfButtons = CountButtons;
	if (TypeOfConnection != NULL && strlen(TypeOfConnection) < MOUSE_TYPE_OF_CONNECTION_SIZE)
		strcpy(Init.TypeOfConnection, TypeOfConnection);
	
	return Init;
}

int SetMouseTypeOfConnection(Mouse* CurrentMouse, char* TypeOfConnection)
{
	if (CurrentMouse != NULL && TypeOfConnection != NULL && strlen(TypeOfConnection) < MOUSE_TYPE_OF_CONNECTION_SIZE)
	{
		strcpy(CurrentMouse->TypeOfConnection, TypeOfConnection);
		return 1;
	}
	else
		return 0;
}

int SetMouseLengthOfCable(Mouse* CurrentMouse, int LenghtOfCable)
{
	if (CurrentMouse != NULL && LenghtOfCable >= 0)
	{
		CurrentMouse->LengthOfCable = LenghtOfCable;
		return 1;
	}
	else
		return 0;
}

int SetMouseSensitivity(Mouse* CurrentMouse, int Sensitivity)
{
	if (CurrentMouse != NULL && Sensitivity >= 0)
	{
		CurrentMouse->Sensitivity = Sensitivity;
		return 1;
	}
	else
		return 0;
}

int SetMouseCountOfButtons(Mouse* CurrentMouse, int Count)
{
	if (CurrentMouse != NULL && Count >= 0)
	{
		CurrentMouse->CountOfButtons = Count;
		return 1;
	}
	else 
		return 0;
}

void GetMouseTypeOfConnection(Mouse CurrentMouse, char* TypeOfConnection)
{
	if (TypeOfConnection != NULL)
		strcpy(TypeOfConnection, CurrentMouse.TypeOfConnection);
	return;
}

int GetMouseLenghtOfCable(Mouse CurrentMouse)
{
	return CurrentMouse.LengthOfCable;
}

int GetMouseSensitivity(Mouse CurrentMouse)
{
	return CurrentMouse.Sensitivity;
}

int GetMouseCountOfButtons(Mouse CurrentMouse)
{
	return CurrentMouse.CountOfButtons;
}

void OutputAllInfoAboutMouse(Mouse CurrentMouse)
{
	OutputAllInfoAboutProduct(CurrentMouse.General);
	printf("Тип соединения: %s\n", CurrentMouse.TypeOfConnection);
	if (CurrentMouse.LengthOfCable > 0)
		printf("Длина кабеля (см): %d\n", CurrentMouse.LengthOfCable);
	printf("Разрешение датчика (dpi): %d\n", CurrentMouse.Sensitivity);
	printf("Количество кнопок: %d\n", CurrentMouse.CountOfButtons);
	return;
}
