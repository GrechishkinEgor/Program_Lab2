#include "Monitor.h"

Monitor InitMonitor()
{
	Monitor Init;
	Init.Diagonal = 0;
	Init.Frequency = 0;
	Init.Size[0] = 0;
	Init.Size[1] = 0;
	Init.AspectRatio[0] = 0;
	Init.AspectRatio[1] = 0;
	Init.General = InitProduct();
	return Init;
}

Monitor InitMonitor(Product General)
{
	Monitor Init = InitMonitor();
	SetMonitorGeneral(&Init, General);
	return Init;
}

Monitor InitMonitor(Product General, int Diagonal, int Frequency, int Size[2], int AspectRatio[2])
{
	Monitor Init = InitMonitor(General);
	SetMonitorDiagonal(&Init, Diagonal);
	SetMonitorFrequency(&Init, Frequency);
	SetMonitorSize(&Init, Size[0], Size[1]);
	SetMonitorAspectRatio(&Init, AspectRatio[0], AspectRatio[1]);
	return Init;
}

int SetMonitorGeneral(Monitor* CurrentMonitor, Product General)
{
	if (CurrentMonitor != NULL)
	{
		CurrentMonitor->General = General;
		return 1;
	}
	else
		return 0;
}

int SetMonitorDiagonal(Monitor* CurrentMonitor, int Diagonal)
{
	if (CurrentMonitor != NULL)
	{
		CurrentMonitor->Diagonal = Diagonal;
		return 1;
	}
	else
		return 0;
}

int SetMonitorFrequency(Monitor* CurrentMonitor, int Frequency)
{
	if (CurrentMonitor != NULL)
	{
		CurrentMonitor->Frequency = Frequency;
		return 1;
	}
	else
		return 0;
}

int SetMonitorSize(Monitor* CurrentMonitor, int Width, int Height)
{
	if (CurrentMonitor != NULL)
	{
		CurrentMonitor->Size[0] = Width;
		CurrentMonitor->Size[1] = Height;
		return 1;
	}
	else
		return 0;
}

int SetMonitorAspectRatio(Monitor* CurrentMonitor, int AspectRatio1, int AspectRatio2)
{
	if (CurrentMonitor != NULL)
	{
		CurrentMonitor->AspectRatio[0] = AspectRatio1;
		CurrentMonitor->AspectRatio[1] = AspectRatio2;
		return 1;
	}
	else
		return 0;
}

Product GetMonitorGeneral(Monitor CurrentMonitor)
{
	return CurrentMonitor.General;
}

int GetMonitorDiagonal(Monitor CurrentMonitor)
{
	return CurrentMonitor.Diagonal;
}

int GetMonitorFrequency(Monitor CurrentMonitor)
{
	return CurrentMonitor.Frequency;
}

void GetMonitorSize(Monitor CurrentMonitor, int* Width, int* Height)
{
	*Width = CurrentMonitor.Size[0];
	*Height = CurrentMonitor.Size[1];
	return;
}

void GetMonitorAspectRatio(Monitor CurrentMonitor, int* AspectRatio1, int* AspectRatio2)
{
	*AspectRatio1 = CurrentMonitor.AspectRatio[0];
	*AspectRatio2 = CurrentMonitor.AspectRatio[1];
	return;
}

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor)
{
	OutputAllInfoAboutProduct(CurrentMonitor.General);
	printf("Диагональ матрицы (в дюймах): %d\n", CurrentMonitor.Diagonal);
	printf("Частота обновления экрана (в герцах): %d\n", CurrentMonitor.Frequency);
	printf("Разрешение экрана: %d x %d\n", CurrentMonitor.Size[0], CurrentMonitor.Size[1]);
	printf("Соотношение сторон: %d:%d\n", CurrentMonitor.AspectRatio[0], CurrentMonitor.AspectRatio[1]);
	return;
}

int SaveMonitor(Monitor CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* FileOfProduct = fopen(Path, "wb");
	if (FileOfProduct != NULL)
	{
		WriteMonitorInFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int SaveNewMonitor(Monitor CurrentProduct, char* Path)
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
		return SaveMonitor(CurrentProduct, Path);
}

int WriteMonitorInFile(Monitor CurrentProduct, FILE* BinaryWriterFile)
{
	if (BinaryWriterFile != NULL)
	{
		fwrite(&CurrentProduct, sizeof(Monitor), 1, BinaryWriterFile);
		return 1;
	}
	else
		return 0;
}

int LoadMonitor(Monitor* CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	if (CurrentProduct == NULL)
		return -1;

	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct != NULL)
	{
		ReadMonitorFromFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int ReadMonitorFromFile(Monitor* CurrentProduct, FILE* BinaryReaderFile)
{
	if (CurrentProduct == NULL || BinaryReaderFile == NULL)
		return 0;
	if (fread(CurrentProduct, sizeof(Monitor), 1, BinaryReaderFile) == 1)
		return 1;
	else
		return -1;
}
