#include "Keyboard.h"

Keyboard InitKeyboard()
{
	Keyboard Init;
	Init.TypeOfConnection[0] = '\0';
	Init.LengthOfCable = 0;
	return Init;
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
	printf("Тип соединения: %s\n", CurrentKeyboard.TypeOfConnection);
	if (CurrentKeyboard.LengthOfCable > 0)
		printf("Длина кабеля: %d\n", CurrentKeyboard.LengthOfCable);
	return;
}

void InputAllInfoAboutKeyboard(Keyboard* CurrentKeyboard)
{
	printf("Введите тип соединения (проводная/беспроводная): ");
	scanf_s("%s", CurrentKeyboard->TypeOfConnection, KEYBOARD_TYPE_OF_CONNECTION_SIZE);
	printf("Введите длину кабеля (в см; если нет кабеля, введите 0): ");
	scanf("%d", &CurrentKeyboard->LengthOfCable);
	return;
}

