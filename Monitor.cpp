#include "Monitor.h"

void Monitor::OutputAllInfo()
{
	Product::OutputAllInfo();
	printf("Диагональ матрицы (в дюймах): %d\n", this->Diagonal);
	printf("Частота обновления экрана (в герцах): %d\n", this->Frequency);
	printf("Разрешение экрана: %d x %d\n", this->Size[0], this->Size[1]);
	printf("Соотношение сторон: %d:%d\n", this->AspectRatio[0], this->AspectRatio[1]);
	return;
}

int Monitor::Save(const char* Path)
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

int Monitor::SaveNew(const char* Path)
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

int Monitor::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile == NULL)
		return 0;
	Product::WriteInFile(BinaryWriterFile);
	fwrite(&this->Diagonal, sizeof(this->Diagonal), 1, BinaryWriterFile);
	fwrite(&this->Frequency, sizeof(this->Frequency), 1, BinaryWriterFile);
	fwrite(this->Size, sizeof(this->Size), 1, BinaryWriterFile);
	fwrite(this->AspectRatio, sizeof(this->AspectRatio), 1, BinaryWriterFile);
	return 1;
}

int Monitor::Load(const char* Path)
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

int Monitor::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile == NULL)
		return 0;
	Product::ReadFromFile(BinaryReaderFile);
	fread(&this->Diagonal, sizeof(this->Diagonal), 1, BinaryReaderFile);
	fread(&this->Frequency, sizeof(this->Frequency), 1, BinaryReaderFile);
	fread(this->Size, sizeof(this->Size), 1, BinaryReaderFile);
	fread(this->AspectRatio, sizeof(this->AspectRatio), 1, BinaryReaderFile);
	return 1;
}

Monitor::Monitor() : Product()
{
	this->Diagonal = 0;
	this->Frequency = 0;
	this->Size[0] = 0;
	this->Size[1] = 0;
	this->AspectRatio[0] = 0;
	this->AspectRatio[1] = 0;
	return;
}

Monitor::Monitor(Product General) : Product(General)
{
	this->Diagonal = 0;
	this->Frequency = 0;
	this->Size[0] = 0;
	this->Size[1] = 0;
	this->AspectRatio[0] = 0;
	this->AspectRatio[1] = 0;
	return;
}

Monitor::Monitor(Product General, int Diagonal, int Frequency, int Size[2], int AspectRatio[2]) : Monitor(General)
{
	SetDiagonal(Diagonal);
	SetFrequency(Frequency);
	SetSize(Size[0], Size[1]);
	SetAspectRatio(AspectRatio[0], AspectRatio[1]);
	return;
}

Monitor::Monitor(const Monitor& Obj) : Product(Obj)
{
	SetDiagonal(Obj.Diagonal);
	SetFrequency(Obj.Frequency);
	SetSize(Obj.Size[0], Obj.Size[1]);
	SetAspectRatio(Obj.AspectRatio[0], Obj.AspectRatio[1]);
	return;
}

Monitor::~Monitor()
{
	return;
}

bool Monitor::SetDiagonal(int Diagonal)
{
	if (Diagonal >= 0)
	{
		this->Diagonal = Diagonal;
		return true;
	}
	else
		return false;
}

bool Monitor::SetFrequency(int Frequency)
{
	if (Frequency >= 0)
	{
		this->Frequency = Frequency;
		return true;
	}
	else
		return false;
}

bool Monitor::SetSize(int Width, int Height)
{
	if (Width >= 0 && Height >= 0)
	{
		this->Size[0] = Width;
		this->Size[1] = Height;
		return true;
	}
	else
		return false;
}

bool Monitor::SetAspectRatio(int AspectRatio1, int AspectRatio2)
{
	if (AspectRatio1 >= 0 && AspectRatio2 >= 0)
	{
		this->AspectRatio[0] = AspectRatio1;
		this->AspectRatio[1] = AspectRatio2;
		return true;
	}
	else
		return false;
}

int Monitor::GetDiagonal()
{
	return this->Diagonal;
}

int Monitor::GetFrequency()
{
	return this->Frequency;
}

void Monitor::GetSize(int* Width, int* Height)
{
	if (Width != NULL)
		*Width = this->Size[0];
	if (Height != NULL)
		*Height = this->Size[1];
	return;
}

void Monitor::GetAspectRation(int* AspectRatio1, int* AspectRatio2)
{
	if (AspectRatio1 != NULL)
		*AspectRatio1 = this->AspectRatio[0];
	if (AspectRatio2 != NULL)
		*AspectRatio2 = this->AspectRatio[1];
	return;
}
