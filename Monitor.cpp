#include "Monitor.h"

void Monitor::OutputAllInfo()
{
	Product::OutputAllInfo();
	printf("��������� ������� (� ������): %d\n", this->Diagonal);
	printf("������� ���������� ������ (� ������): %d\n", this->Frequency);
	printf("���������� ������: %d x %d\n", this->Size[0], this->Size[1]);
	printf("����������� ������: %d:%d\n", this->AspectRatio[0], this->AspectRatio[1]);
	return;
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

void Monitor::operator=(Product& General)
{
	this->SetName(General.GetName());
	this->SetCompany(General.GetCompany());
	this->SetCount(General.GetCount());
	this->SetPrice(General.GetPrice());
	return;
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

void operator<<(std::ostream& o, Monitor obj)
{
	std::cout << obj.GetGeneral();
	std::cout << "��������� �������(� ������): " << obj.Diagonal << std::endl;
	std::cout << "������� ���������� ������ (� ������): " << obj.Frequency << std::endl;
	std::cout << "���������� ������: " << obj.Size[0] << " x " << obj.Size[1] << std::endl;
	std::cout << "����������� ������: " << obj.AspectRatio[0] << ":" << obj.AspectRatio[1] << std::endl;
	return;
}
