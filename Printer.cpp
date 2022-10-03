#include "Printer.h"

Printer InitPrinter()
{
	Printer Init;
	Init.General = InitProduct();
	Init.TypeOfPrint[0] = '\0';
	Init.DPI = 0;
	Init.PaperFormat = 4;
	return Init;
}

Printer InitPrinter(Product General)
{
	Printer Init = InitPrinter();
	Init.General = General;
	return Init;
}

Printer InitPrinter(Product General, char* Type, int DPI, int PaperFormat)
{
	Printer Init;
	Init = InitPrinter();
	Init.General = General;
	SetPrinterTypeOfPrint(&Init, Type);
	SetPrinterDPI(&Init, DPI);
	SetPrinterPaperFormat(&Init, PaperFormat);
	return Init;
}

int SetPrinterTypeOfPrint(Printer* CurrentPrinter, char* TypeOfPrint)
{
	if (CurrentPrinter != NULL && TypeOfPrint != NULL && strlen(TypeOfPrint) < PRINTER_TYPE_OF_PRINT_SIZE)
	{
		strcpy(CurrentPrinter->TypeOfPrint, TypeOfPrint);
		return 1;
	}
	else
		return 0;
}

int SetPrinterDPI(Printer* CurrentPrinter, int DPI)
{
	if (CurrentPrinter != NULL && DPI >= 0)
	{
		CurrentPrinter->DPI = DPI;
		return 1;
	}
	else
		return 0;
}

int SetPrinterPaperFormat(Printer* CurrentPrinter, int PaperFormat)
{
	if (CurrentPrinter != NULL && PaperFormat >= 0)
	{
		CurrentPrinter->PaperFormat = PaperFormat;
		return 1;
	}
	else
		return 0;
}

int SetPrinterGeneral(Printer* CurrentPrinter, Product General)
{
	if (CurrentPrinter != NULL)
	{
		CurrentPrinter->General = General;
		return 1;
	}
	else
		return 0;
}

void GetPrinterTypeOfPrint(Printer CurrentPrinter, char* TypeOfPrint)
{
	if (TypeOfPrint != NULL)
		strcpy(TypeOfPrint, CurrentPrinter.TypeOfPrint);
	return;
}

int GetPrinterDPI(Printer CurrentPrinter)
{
	return CurrentPrinter.DPI;
}

int GetPrinterPaperFormat(Printer CurrentPrinter)
{
	return CurrentPrinter.PaperFormat;
}

Product GetPrinterGeneral(Printer CurrentPrinter)
{
	return CurrentPrinter.General;
}

void OutputAllInfoAboutPrinter(Printer CurrentPrinter)
{
	OutputAllInfoAboutProduct(CurrentPrinter.General);
	printf("Тип по способу печати: %s\n", CurrentPrinter.TypeOfPrint);
	printf("Разрешение (dpi): %d\n", CurrentPrinter.DPI);
	printf("Формат бумаги: A%d\n", CurrentPrinter.PaperFormat);
	return;
}

int SavePrinter(Printer CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* FileOfProduct = fopen(Path, "wb");
	if (FileOfProduct != NULL)
	{
		WritePrinterInFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int SaveNewPrinter(Printer CurrentProduct, char* Path)
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
		return SavePrinter(CurrentProduct, Path);
}

int WritePrinterInFile(Printer CurrentProduct, FILE* BinaryWriterFile)
{
	if (BinaryWriterFile != NULL)
	{
		//Можно сначала вызвывать WriteProductInFIle(CurrentProduct.General, BinaryWriterFile)
		//Затем записать оставшиеся поля Printer
		fwrite(&CurrentProduct, sizeof(Printer), 1, BinaryWriterFile);
		return 1;
	}
	else
		return 0;
}

int LoadPrinter(Printer* CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	if (CurrentProduct == NULL)
		return -1;

	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct != NULL)
	{
		ReadPrinterFromFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int ReadPrinterFromFile(Printer* CurrentProduct, FILE* BinaryReaderFile)
{
	if (CurrentProduct == NULL || BinaryReaderFile == NULL)
		return 0;
	if (fread(&CurrentProduct, sizeof(Printer), 1, BinaryReaderFile) == 1)
		return 1;
	else
		return -1;
}
