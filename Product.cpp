#include "Product.h"

Product InitProduct()
{
	Product Init;
	Init.Name[0] = '\0';
	Init.Company[0] = '\0';
	Init.Price = 0;
	Init.Count = 0;
	Init.Type = IsNotDefined;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price)
{
	Product Init = InitProduct();
	if (Name != NULL && strlen(Name) < PRODUCT_NAME_SIZE)
		strcpy(Init.Name, Name);
	if (Company != NULL && strlen(Company) < PRODUCT_COMPANY_SIZE)
		strcpy(Init.Company, Company);
	if (Price >= 0)
		Init.Price = Price;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price, Mouse Info)
{
	Product Init = InitProduct(Name, Company, Price);
	Init.Type = IsMouse;
	Init.Information.AboutMouse = Info;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price, Keyboard Info)
{
	Product Init = InitProduct(Name, Company, Price);
	Init.Type = IsKeyboard;
	Init.Information.AboutKeyboard = Info;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price, Monitor Info)
{
	Product Init = InitProduct(Name, Company, Price);
	Init.Type = IsMonitor;
	Init.Information.AboutMonitor = Info;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price, Printer Info)
{
	Product Init = InitProduct(Name, Company, Price);
	Init.Type = IsPrinter;
	Init.Information.AboutPrinter = Info;
	return Init;
}

int IncreaseCountOfProduct(Product* CurrentProduct)
{
	if (CurrentProduct->Count + 1 > 0)
		CurrentProduct->Count++;
	return CurrentProduct->Count;
}

int DecreaseCountOfProduct(Product* CurrentProduct)
{
	if (CurrentProduct->Count - 1 >= 0)
		CurrentProduct->Count--;
	return CurrentProduct->Count;
}

void OutputAllInfoAboutProduct(Product CurrentProduct)
{
	printf("Название товара: %s\n", CurrentProduct.Name);
	printf("Компания-производитель: %s\n", CurrentProduct.Company);
	printf("Цена товара (в рублях): %g\n", CurrentProduct.Price / 100.0);
	printf("Количество товара (штук): %d\n", CurrentProduct.Count);
	switch (CurrentProduct.Type)
	{
	case IsKeyboard:
		OutputAllInfoAboutKeyboard(CurrentProduct.Information.AboutKeyboard);
		break;
	case IsPrinter:
		OutputAllInfoAboutPrinter(CurrentProduct.Information.AboutPrinter);
		break;
	case IsMouse:
		OutputAllInfoAboutMouse(CurrentProduct.Information.AboutMouse);
		break;
	case IsMonitor:
		OutputAllInfoAboutMonitor(CurrentProduct.Information.AboutMonitor);
		break;
	}
	return;
}

void InputAllInfoAboutProduct(Product* CurrentProduct)
{
	printf("Введите название товара: ");
	scanf_s("%s", CurrentProduct->Name, PRODUCT_NAME_SIZE);
	while (getchar() != '\n');
	printf("Введите компанию-производителя: ");
	scanf_s("%s", CurrentProduct->Company, PRODUCT_COMPANY_SIZE);
	while (getchar() != '\n');
	printf("Введите цену товара (в копейках!): ");
	scanf("%d", &CurrentProduct->Price);
	while (getchar() != '\n');
	printf("Введите количество товара (штук): ");
	scanf("%d", &CurrentProduct->Count);
	while (getchar() != '\n');
	int UserChoiceOfType = 0;
	while (UserChoiceOfType < 1 || UserChoiceOfType > 4)
	{
		printf("Выберите тип товара: \n"
			"1 - Клавиатура\n"
			"2 - Монитор\n"
			"3 - Мышь\n"
			"4 - Принтер\n"
			"Ваш выбор: "
		);
		scanf("%d", &UserChoiceOfType);
		while (getchar() != '\n');
	}
	switch (UserChoiceOfType)
	{
	case 1: 
		CurrentProduct->Type = IsKeyboard;
		InputAllInfoAboutKeyboard(&CurrentProduct->Information.AboutKeyboard);
		break;
	case 2:
		CurrentProduct->Type = IsMonitor;
		InputAllInfoAboutMonitor(&CurrentProduct->Information.AboutMonitor);
		break;
	case 3:
		CurrentProduct->Type = IsMouse;
		InputAllInfoAboutMouse(&CurrentProduct->Information.AboutMouse);
		break;
	case 4:
		CurrentProduct->Type = IsPrinter;
		InputAllInfoAboutPrinter(&CurrentProduct->Information.AboutPrinter);
		break;
	}
	
	return;
}

/*Записать информацию о товаре в новый файл (путь - Path)
Возврат: 0 - успешно; 1 - файл существует; -1 - файл не открылся*/
int WriteProductInFile(Product CurrentProduct, char* Path)
{
	if (Path == NULL)
		return -1;
	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct == NULL)
		return SaveProduct(CurrentProduct, Path);
	else
	{
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
}

/*Записать информацию о товаре в файл (путь - Path)
Возврат: 0 - успешно; -1 - файл не открылся*/
int SaveProduct(Product CurrentProduct, char* Path)
{
	FILE* FileOfProduct = fopen(Path, "wb");
	if (FileOfProduct != NULL)
	{
		fwrite(&CurrentProduct, sizeof(Product), 1, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 0;
	}
	else
		return -1;
}

/*Считать данные о товаре из файла (путь - Path)
Возврат: 0 - успешно; -1 - файла не существует или недоступен*/
int ReadProductFromFile(Product* CurrentProduct, char* Path)
{
	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct != NULL)
	{
		fread(CurrentProduct, sizeof(Product), 1, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 0;
	}
	else
		return -1;
}

int SetPriceOfProduct(Product* CurrentProduct, int NewPrice)
{
	if (NewPrice >= 0)
		CurrentProduct->Price = NewPrice;
	return CurrentProduct->Price;
}

int SetCountOfProduct(Product* CurrentProduct, int NewCount)
{
	if (NewCount >= 0)
		CurrentProduct->Count = NewCount;
	return CurrentProduct->Count;
}
