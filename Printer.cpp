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
	printf("Тип по способу печати: %s\n", CurrentPrinter.TypeOfPrint);
	printf("Разрешение (dpi): %d\n", CurrentPrinter.DPI);
	printf("Формат бумаги: A%d\n", CurrentPrinter.PaperFormat);
	return;
}

void InputAllInfoAboutPrinter(Printer* CurrentPrinter)
{
	*CurrentPrinter = InitPrinter();
	printf("Введите тип принтера по принципу печати (например, струйный): ");
	scanf_s("%s", CurrentPrinter->TypeOfPrint, PRINTER_TYPE_OF_PRINT_SIZE);
	while (getchar() != '\n');
	printf("Введите разрешение печати (dpi): ");
	scanf("%d", &CurrentPrinter->DPI);
	while (getchar() != '\n');
	printf("Введите размер бумаги (А4/А5/...; введите букву А кириллицей): ");
	scanf("А%d", &CurrentPrinter->PaperFormat);
	return;
}
