#include "Printer.h"

Printer::Printer() : Product()
{
	this->TypeOfPrint[0] = '\0';
	this->DPI = 0;
	this->PaperFormat = 0;
	return;
}

Printer::Printer(Product General) : Product(General)
{
	this->TypeOfPrint[0] = '\0';
	this->DPI = 0;
	this->PaperFormat = 0;
	return;
}

Printer::Printer(Product General, char* Type, int DPI, int PaperFormat) : Printer(General)
{
	this->SetTypeOfPrint(Type);
	this->SetDPI(DPI);
	this->SetPaperFormat(PaperFormat);
	return;
}

Printer::Printer(const Printer& Obj) : Product(Obj)
{
	this->SetTypeOfPrint(Obj.TypeOfPrint);
	this->SetDPI(Obj.DPI);
	this->SetPaperFormat(Obj.PaperFormat);
	return;
}

Printer::~Printer()
{
	return;
}

bool Printer::SetTypeOfPrint(const char* Type)
{
	if (Type != NULL && strlen(Type) < PRINTER_TYPE_OF_PRINT_SIZE)
	{
		strcpy(this->TypeOfPrint, Type);
		return true;
	}
	else
		return false;
}

bool Printer::SetDPI(int DPI)
{
	if (DPI >= 0)
	{
		this->DPI = DPI;
		return true;
	}
	else
		return false;
}

bool Printer::SetPaperFormat(int PaperFormat)
{
	if (PaperFormat >= 0)
	{
		this->PaperFormat = PaperFormat;
		return true;
	}
	else
		return false;
}

void Printer::GetTypeOfPrint(char* Type)
{
	if (Type != NULL)
		strcpy(Type, this->TypeOfPrint);
	return;
}

int Printer::GetDPI()
{
	return this->DPI;
}

int Printer::GetPaperFormat()
{
	return this->PaperFormat;
}

void Printer::OutputAllInfo()
{
	Product::OutputAllInfo();
	printf("Тип по способу печати: %s\n", this->TypeOfPrint);
	printf("Разрешение (dpi): %d\n", this->DPI);
	printf("Формат бумаги: A%d\n", this->PaperFormat);
	return;
}

int Printer::Save(char* Path)
{
	if (Path != NULL)
	{
		FILE* Writer = fopen(Path, "wb");
		if (Writer != NULL)
		{
			this->WriteInFile(Writer);
			fclose(Writer);
			Writer = NULL;
			return 1;
		}
		else
			return 0;
	}
	else 
		return 0;
}

int Printer::SaveNew(char* Path)
{
	if (Path != NULL)
	{
		FILE* Check = fopen(Path, "rb");
		if (Check != NULL)
		{
			fclose(Check);
			Check = NULL;
			return -1;
		}
		else
			return this->Save(Path);
	}
	else
		return 0;
}

int Printer::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile == NULL)
		return 0;
	Product::WriteInFile(BinaryWriterFile);
	fwrite(this->TypeOfPrint, sizeof(this->TypeOfPrint), 1, BinaryWriterFile);
	fwrite(&this->DPI, sizeof(this->DPI), 1, BinaryWriterFile);
	fwrite(&this->PaperFormat, sizeof(this->PaperFormat), 1, BinaryWriterFile);
	return 1;
}

int Printer::Load(char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* Reader = fopen(Path, "rb");
	if (Reader != NULL)
	{
		this->ReadFromFile(Reader);
		fclose(Reader);
		Reader = NULL;
		return 1;
	}
	else
		return -1;
	return 0;
}

int Printer::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile == NULL)
		return 0;
	Product::ReadFromFile(BinaryReaderFile);
	fread(this->TypeOfPrint, sizeof(this->TypeOfPrint), 1, BinaryReaderFile);
	fread(&this->DPI, sizeof(this->DPI), 1, BinaryReaderFile);
	fread(&this->PaperFormat, sizeof(this->PaperFormat), 1, BinaryReaderFile);
	return 1;
}
