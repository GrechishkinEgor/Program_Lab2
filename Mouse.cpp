#include "Mouse.h"

Mouse InitMouse()
{
	Mouse Init;
	Init.TypeOfConnection[0] = '\0';
	Init.LengthOfCable = 0;
	Init.Sensitivity = 0;
	Init.CountOfButtons = 0;
	return Init;
}

Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection, int LengthOfCable)
{
	Mouse Init;
	Init = InitMouse(Sensitivity, CountButtons, TypeOfConnection);
	if (LengthOfCable > 0)
		Init.LengthOfCable = LengthOfCable;
	return Init;
}

Mouse InitMouse(int Sensitivity, int CountButtons, char* TypeOfConnection)
{
	Mouse Init;
	Init = InitMouse();
	if (Sensitivity > 0)
		Init.Sensitivity = Sensitivity;
	if (CountButtons > 0)
		Init.CountOfButtons = CountButtons;
	if (TypeOfConnection != NULL && strlen(TypeOfConnection) < MOUSE_TYPE_OF_CONNECTION_SIZE)
		strcpy(Init.TypeOfConnection, TypeOfConnection);
	
	return Init;
}

void OutputAllInfoAboutMouse(Mouse CurrentMouse)
{
	printf("Тип соединения: %s\n", CurrentMouse.TypeOfConnection);
	if (CurrentMouse.LengthOfCable > 0)
		printf("Длина кабеля (см): %d\n", CurrentMouse.LengthOfCable);
	printf("Разрешение датчика (dpi): %d\n", CurrentMouse.Sensitivity);
	printf("Количество кнопок: %d\n", CurrentMouse.CountOfButtons);
	return;
}

void InputAllInfoAboutMouse(Mouse* CurrentMouse)
{
	*CurrentMouse = InitMouse();
	printf("Введите тип соединения (проводная, беспроводная): ");
	scanf_s("%s", CurrentMouse->TypeOfConnection, MOUSE_TYPE_OF_CONNECTION_SIZE);
	while (getchar() != '\n');
	printf("Введите длину кабеля (в см; если нет кабеля - введите 0): ");
	scanf("%d", &CurrentMouse->LengthOfCable);
	while (getchar() != '\n');
	printf("Введите разрешение датчика (dpi): ");
	scanf("%d", &CurrentMouse->Sensitivity);
	while (getchar() != '\n');
	printf("Введите количество кнопок: ");
	scanf("%d", &CurrentMouse->CountOfButtons);
	while (getchar() != '\n');
	return;
}
