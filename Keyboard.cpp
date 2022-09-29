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
	printf("��� ����������: %s\n", CurrentKeyboard.TypeOfConnection);
	if (CurrentKeyboard.LengthOfCable > 0)
		printf("����� ������: %d\n", CurrentKeyboard.LengthOfCable);
	return;
}

void InputAllInfoAboutKeyboard(Keyboard* CurrentKeyboard)
{
	printf("������� ��� ���������� (���������/������������): ");
	scanf_s("%s", CurrentKeyboard->TypeOfConnection, KEYBOARD_TYPE_OF_CONNECTION_SIZE);
	printf("������� ����� ������ (� ��; ���� ��� ������, ������� 0): ");
	scanf("%d", &CurrentKeyboard->LengthOfCable);
	return;
}

