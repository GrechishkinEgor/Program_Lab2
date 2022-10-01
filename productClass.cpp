#include "productClass.h"

bool product::WriteInFile(FILE* BinaryWriteOnlyFile)
{
	if (BinaryWriteOnlyFile != NULL)
	{
		fwrite(this->Name, PRODUCT_NAME_MAX_SIZE, 1, BinaryWriteOnlyFile);
		fwrite(this->Company, PRODUCT_COMPANY_MAX_SIZE, 1, BinaryWriteOnlyFile);
		fwrite(&this->Price, sizeof(int), 1, BinaryWriteOnlyFile);
		fwrite(&this->Count, sizeof(int), 1, BinaryWriteOnlyFile);
		return true;
	}
	else
		return false;
}

bool product::ReadFromFile(FILE* BinaryReadOnlyFile)
{
	if (BinaryReadOnlyFile != NULL)
	{
		fread(this->Name, PRODUCT_NAME_MAX_SIZE, 1, BinaryReadOnlyFile);
		fread(this->Company, PRODUCT_COMPANY_MAX_SIZE, 1, BinaryReadOnlyFile);
		fread(&this->Price, sizeof(int), 1, BinaryReadOnlyFile);
		fread(&this->Count, sizeof(int), 1, BinaryReadOnlyFile);
		return true;
	}
	else
		return false;
}

product::product()
{
	this->Name[0] = '\0';
	this->Company[0] = '\0';
	this->Price = 0;
	this->Count = 0;
	strcpy(this->StringIdentificator, PRODUCT_STRING_IDENTIFICATOR);
	return;
}

product::product(char* Name) : product()
{
	SetName(Name);
	return;
}

product::product(char* Name, char* Company) : product(Name)
{
	SetCompany(Company);
	return;
}

product::product(char* Name, char* Company, int Price) : product(Name, Company)
{
	SetPrice(Price);
	return;
}

product::product(char* Name, char* Company, int Price, int Count) : product(Name, Company, Price)
{
	SetCount(Count);
	return;
}

product::product(char* Name, int Price) : product(Name)
{
	SetPrice(Price);
	return;
}

product::product(const product& obj)
{
	strcpy(this->Name, obj.Name);
	strcpy(this->Company, obj.Company);
	this->Price = obj.Price;
	this->Count = obj.Count;
	strcpy(this->StringIdentificator, obj.StringIdentificator);
	return;
}

product::~product()
{
	return;
}

bool product::SetName(char* Name)
{
	if (Name != NULL && strlen(Name) < PRODUCT_NAME_MAX_SIZE)
	{
		strcpy(this->Name, Name);
		return true;
	}
	else
		return false;
}

bool product::SetCompany(char* Company)
{
	if (Company != NULL && strlen(Company) < PRODUCT_COMPANY_MAX_SIZE)
	{
		strcpy(this->Company, Company);
		return true;
	}
	else
		return false;
}

bool product::SetPrice(int Price)
{
	if (Price >= 0)
	{
		this->Price = Price;
		return true;
	}
	else
		return false;
}

bool product::SetCount(int Count)
{
	if (Count >= 0)
	{
		this->Count = Count;
		return true;
	}
	else
		return false;
}

void product::GetName(char Name[PRODUCT_NAME_MAX_SIZE])
{
	strcpy(Name, this->Name);
	return;
}

void product::GetCompany(char Company[PRODUCT_COMPANY_MAX_SIZE])
{
	strcpy(Company, this->Company);
	return;
}

int product::GetPrice()
{
	return this->Price;
}

int product::GetCount()
{
	return this->Count;
}

void product::GetStringIdentificator(char Identificator[PRODUCT_STRING_IDENTIFICATOR_MAX_SIZE])
{
	strcpy(Identificator, this->StringIdentificator);
	return;
}

bool product::IncreaseCount()
{
	if (this->Count + 1 > 0)
	{
		this->Count++;
		return true;
	}
	else
		return false;
}

bool product::DecreaseCount()
{
	if (this->Count - 1 >= 0)
	{
		this->Count--;
		return true;
	}
	else
		return false;
}

void product::OutputAllInfo()
{
	printf("Тип товара: %s\n", this->StringIdentificator);
	printf("Название товара: %s\n", this->Name);
	printf("Компания-производитель: %s\n", this->Company);
	printf("Цена: %g\n", this->Price / 100.0);
	printf("В наличии: %d штук\n", this->Count);
	return;
}

void product::InputAllInfo()
{
	char Name[PRODUCT_NAME_MAX_SIZE] = "\0";
	while (strlen(Name) == 0)
	{
		printf("Введите название товара: ");
		scanf_s("%s", Name, PRODUCT_NAME_MAX_SIZE);
		while (getchar() != '\n');
		if (!this->SetName(Name))
			Name[0] = '\0';
	}
	char Company[PRODUCT_COMPANY_MAX_SIZE] = "\0";
	while (strlen(Company) == 0)
	{
		printf("Введите название компании-производителя: ");
		scanf_s("%s", Company, PRODUCT_COMPANY_MAX_SIZE);
		while (getchar() != '\n');
		if (!this->SetCompany(Company))
			Company[0] = '\0';
	}
	int Price = -1;
	while (Price < 0)
	{
		printf("Введите цену (в копейках!): ");
		scanf("%d", &Price);
		while (getchar() != '\n');
		if (!SetPrice(Price))
			Price = -1;
	}
	int Count = -1;
	while (Count < 0)
	{
		printf("Введите количество товара (штук): ");
		scanf("%d", &Count);
		while (getchar() != '\n');
		if (!SetCount(Count))
			Count = -1;
	}

	return;
}
