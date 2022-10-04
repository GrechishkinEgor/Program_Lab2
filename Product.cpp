#include "Product.h"

Product::Product()
{
	this->Name[0] = '\0';
	this->Company[0] = '\0';
	this->Price = 0;
	this->Count = 0;
	return;
}

Product::Product(const char* Name, const char* Company, int Price) : Product()
{
	this->SetName(Name);
	this->SetCompany(Company);
	this->SetPrice(Price);
	return;
}

Product::Product(const char* Name, const char* Company, int Price, int Count) : Product(Name, Company, Price)
{
	this->SetCount(Count);
	return;
}

Product::Product(const Product& Obj) : Product()
{
	this->SetName(Obj.Name);
	this->SetCompany(Obj.Company);
	this->SetPrice(Obj.Price);
	this->SetCount(Obj.Count);
	return;
}

Product::~Product()
{
	return;
}

bool Product::SetName(const char* Name)
{
	if (Name != NULL && strlen(Name) < PRODUCT_NAME_MAX_SIZE)
	{
		strcpy(this->Name, Name);
		return true;
	}
	else
		return false;
}

bool Product::SetCompany(const char* Company)
{
	if (Company != NULL && strlen(Company) < PRODUCT_COMPANY_MAX_SIZE)
	{
		strcpy(this->Company, Company);
		return true;
	}
	return false;
}

bool Product::SetPrice(int Price)
{
	if (Price >= 0)
	{
		this->Price = Price;
		return true;
	}
	else
		return false;
}

bool Product::SetCount(int Count)
{
	if (Count >= 0)
	{
		this->Count = Count;
		return true;
	}
	else
		return false;
}

void Product::GetName(char* Name)
{
	if (Name != NULL)
		strcpy(Name, this->Name);
	return;
}

void Product::GetCompany(char* Company)
{
	if (Company != NULL)
		strcpy(Company, this->Company);
	return;
}

int Product::GetPrice()
{
	return this->Price;
}

int Product::GetCount()
{
	return this->Count;
}

bool Product::IncreaseCount()
{
	return this->SetCount(this->Count + 1);
}

bool Product::DecreaseCount()
{
	return this->SetCount(this->Count - 1);
}

void Product::OutputAllInfo()
{
	printf("Название товара: %s\n", this->Name);
	printf("Компания-производитель: %s\n", this->Company);
	printf("Цена товара (в рублях): %g\n", this->Price / 100.0);
	printf("Количество товара (штук): %d\n", this->Count);
	return;
}

int Product::Save(const char* Path)
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

int Product::SaveNew(const char* Path)
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

int Product::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile != NULL)
	{
		fwrite(this->Name, sizeof(this->Name), 1, BinaryWriterFile);
		fwrite(this->Company, sizeof(this->Company), 1, BinaryWriterFile);
		fwrite(&this->Price, sizeof(this->Price), 1, BinaryWriterFile);
		fwrite(&this->Count, sizeof(this->Count), 1, BinaryWriterFile);
		return 1;
	}
	else
		return 0;
}

int Product::Load(const char* Path)
{
	if (Path != NULL)
	{
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
	}
	else
		return 0;
}

int Product::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile != NULL)
	{
		fread(this->Name, sizeof(this->Name), 1, BinaryReaderFile);
		fread(this->Company, sizeof(this->Company), 1, BinaryReaderFile);
		fread(&this->Price, sizeof(this->Price), 1, BinaryReaderFile);
		fread(&this->Count, sizeof(this->Count), 1, BinaryReaderFile);
		return 1;
	}
	else
		return 0;
}
