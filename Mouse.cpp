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
	printf("��� ����������: %s\n", CurrentMouse.TypeOfConnection);
	if (CurrentMouse.LengthOfCable > 0)
		printf("����� ������ (��): %d\n", CurrentMouse.LengthOfCable);
	printf("���������� ������� (dpi): %d\n", CurrentMouse.Sensitivity);
	printf("���������� ������: %d\n", CurrentMouse.CountOfButtons);
	return;
}

void InputAllInfoAboutMouse(Mouse* CurrentMouse)
{
	*CurrentMouse = InitMouse();
	printf("������� ��� ���������� (���������, ������������): ");
	scanf_s("%s", CurrentMouse->TypeOfConnection, MOUSE_TYPE_OF_CONNECTION_SIZE);
	while (getchar() != '\n');
	printf("������� ����� ������ (� ��; ���� ��� ������ - ������� 0): ");
	scanf("%d", &CurrentMouse->LengthOfCable);
	while (getchar() != '\n');
	printf("������� ���������� ������� (dpi): ");
	scanf("%d", &CurrentMouse->Sensitivity);
	while (getchar() != '\n');
	printf("������� ���������� ������: ");
	scanf("%d", &CurrentMouse->CountOfButtons);
	while (getchar() != '\n');
	return;
}
