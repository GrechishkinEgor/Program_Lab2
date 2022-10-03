#include "Product.h"

Product InitProduct()
{
	Product Init;
	Init.Name[0] = '\0';
	Init.Company[0] = '\0';
	Init.Price = 0;
	Init.Count = 0;
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price)
{
	Product Init = InitProduct();
	SetProductName(&Init, Name);
	SetProductCompany(&Init, Company);
	SetProductPrice(&Init, Price);
	return Init;
}

Product InitProduct(char* Name, char* Company, int Price, int Count)
{
	Product Init = InitProduct(Name, Company, Price);
	SetProductCount(&Init, Count);
	return Init;
}

int SetProductName(Product* CurrentProduct, char* Name)
{
	if (CurrentProduct != NULL && Name != NULL && strlen(Name) < PRODUCT_NAME_MAX_SIZE)
	{
		strcpy(CurrentProduct->Name, Name);
		return 1;
	}
	else
		return 0;
}

int SetProductCompany(Product* CurrentProduct, char* Company)
{
	if (CurrentProduct != NULL && Company != NULL && strlen(Company) < PRODUCT_COMPANY_MAX_SIZE)
	{
		strcpy(CurrentProduct->Company, Company);
		return 1;
	}
	else
		return 0;
}

int SetProductPrice(Product* CurrentProduct, int Price)
{
	if (CurrentProduct != NULL && Price >= 0)
	{
		CurrentProduct->Price = Price;
		return 1;
	}
	else
		return 0;
}

int SetProductCount(Product* CurrentProduct, int Count)
{
	if (CurrentProduct != NULL && Count >= 0)
	{
		CurrentProduct->Count = Count;
		return 1;
	}
	else
		return 0;
}

void GetProductName(Product CurrentProduct, char* Name)
{
	if (Name != NULL)
		strcpy(Name, CurrentProduct.Name);
	return;
}

void GetProductCompany(Product CurrentProduct, char* Company)
{
	if (Company != NULL)
		strcpy(Company, CurrentProduct.Company);
	return;
}

int GetProductPrice(Product CurrentProduct)
{
	return CurrentProduct.Price;
}

int GetProductCount(Product CurrentProduct)
{
	return CurrentProduct.Count;
}

int IncreaseCountOfProduct(Product* CurrentProduct)
{
	if (CurrentProduct != NULL)
		return SetProductCount(CurrentProduct, CurrentProduct->Count + 1);
	else
		return 0;
}

int DecreaseCountOfProduct(Product* CurrentProduct)
{
	if (CurrentProduct != NULL)
		return SetProductCount(CurrentProduct, CurrentProduct->Count - 1);
	else
		return 0;
}

void OutputAllInfoAboutProduct(Product CurrentProduct)
{
	printf("Название товара: %s\n", CurrentProduct.Name);
	printf("Компания-производитель: %s\n", CurrentProduct.Company);
	printf("Цена товара (в рублях): %g\n", CurrentProduct.Price / 100.0);
	printf("Количество товара (штук): %d\n", CurrentProduct.Count);
	return;
}

int SaveProduct(Product CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	FILE* FileOfProduct = fopen(Path, "wb");
	if (FileOfProduct != NULL)
	{
		WriteProductInFile(CurrentProduct, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int SaveNewProduct(Product CurrentProduct, char* Path)
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
		return SaveProduct(CurrentProduct, Path);
}

int WriteProductInFile(Product CurrentProduct, FILE* BinaryWriterFile)
{
	if (BinaryWriterFile != NULL)
	{
		fwrite(&CurrentProduct, sizeof(Product), 1, BinaryWriterFile);
		return 1;
	}
	else
		return 0;
}

int LoadProduct(Product* CurrentProduct, char* Path)
{
	if (Path == NULL)
		return 0;
	if (CurrentProduct == NULL)
		return -1;

	FILE* FileOfProduct = fopen(Path, "rb");
	if (FileOfProduct != NULL)
	{
		fread(CurrentProduct, sizeof(Product), 1, FileOfProduct);
		fclose(FileOfProduct);
		FileOfProduct = NULL;
		return 1;
	}
	else
		return 0;
}

int ReadProductFromFile(Product* CurrentProduct, FILE* BinaryReaderFile)
{
	if (CurrentProduct == NULL || BinaryReaderFile == NULL)
		return 0;
	if (fread(&CurrentProduct, sizeof(Product), 1, BinaryReaderFile) == 1)
		return 1;
	else
		return -1;
}
