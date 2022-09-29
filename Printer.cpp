#include "Printer.h"

Printer InitPrinter()
{
	Printer Init;
	Init.TypeOfPrint[0] = '\0';
	Init.DPI = 0;
	Init.PaperFormat = 4;
	return Init;
}

Printer InitPrinter(char* Type, int DPI, int PaperFormat)
{
	Printer Init;
	Init = InitPrinter();
	if (Type != NULL && strlen(Type) < PRINTER_TYPE_OF_PRINT_SIZE)
		strcpy(Init.TypeOfPrint, Type);
	if (DPI > 0)
		Init.DPI = DPI;
	if (PaperFormat >= 0)
		Init.PaperFormat = PaperFormat;
	return Init;
}

void OutputAllInfoAboutPrinter(Printer CurrentPrinter)
{
	printf("��� �� ������� ������: %s\n", CurrentPrinter.TypeOfPrint);
	printf("���������� (dpi): %d\n", CurrentPrinter.DPI);
	printf("������ ������: A%d\n", CurrentPrinter.PaperFormat);
	return;
}

void InputAllInfoAboutPrinter(Printer* CurrentPrinter)
{
	*CurrentPrinter = InitPrinter();
	printf("������� ��� �������� �� �������� ������ (��������, ��������): ");
	scanf_s("%s", CurrentPrinter->TypeOfPrint, PRINTER_TYPE_OF_PRINT_SIZE);
	while (getchar() != '\n');
	printf("������� ���������� ������ (dpi): ");
	scanf("%d", &CurrentPrinter->DPI);
	while (getchar() != '\n');
	printf("������� ������ ������ (�4/�5/...; ������� ����� � ����������): ");
	scanf("�%d", &CurrentPrinter->PaperFormat);
	return;
}
