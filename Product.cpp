#include "Product.h"
int Product::TotalCost = 0;

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

Product::Product(std::string Name, std::string Company, int Price) : Product()
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

Product::Product(std::string Name, std::string Company, int Price, int Count) : Product(Name, Company, Price)
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

bool Product::SetName(std::string Name)
{
	if (Name.length() < PRODUCT_NAME_MAX_SIZE)
	{
		Name.copy(this->Name, Name.length());
		this->Name[Name.length()] = '\0';
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

bool Product::SetCompany(std::string Company)
{
	if (Company.length() < PRODUCT_COMPANY_MAX_SIZE)
	{
		Company.copy(this->Company, Company.length());
		this->Company[Company.length()] = '\0';
		return true;
	}
	else
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
		int PreviousCount = this->Count;
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

std::string Product::GetName()
{
	return std::string(this->Name);
}

void Product::GetCompany(char* Company)
{
	if (Company != NULL)
		strcpy(Company, this->Company);
	return;
}

std::string Product::GetCompany()
{
	return std::string(this->Company);
}

int Product::GetPrice()
{
	return this->Price;
}

int Product::GetCount()
{
	return this->Count;
}

int Product::operator++()
{
	this->IncreaseCount();
	return this->GetCount();
}

int Product::operator++(int)
{
	int LastCount = this->GetCount();
	this->IncreaseCount();
	return LastCount;
}

int Product::operator--()
{
	this->DecreaseCount();
	return this->GetCount();
}

int Product::operator--(int)
{
	int LastCount = this->GetCount();
	this->DecreaseCount();
	return LastCount;
}

int Product::operator+(Product obj)
{
	return this->Count + obj.Count;
}

int Product::operator+(int Num)
{
	return this->Count + Num;
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

bool Product::AddInTotalCost()
{
	if (Product::TotalCost + this->Count * this->Price >= 0)
	{
		Product::TotalCost += this->Count * this->Price;
		return true;
	}
	else
		return false;
}

int Product::GetTotalCost()
{
	return Product::TotalCost;
}

void Product::ResetTotalCost()
{
	Product::TotalCost = 0;
	return;
}

bool Product::CalculateTotalCost(Product* ArrayOfProduct, int Size)
{
	if (ArrayOfProduct == NULL)
		return false;
	int Cost = 0;
	for (int i = 0; i < Size && Cost >= 0; i++)
		Cost += ArrayOfProduct[i].Count * ArrayOfProduct[i].Price;
	if (Cost >= 0 && Product::TotalCost + Cost >= 0)
	{
		Product::TotalCost += Cost;
		return true;
	}
	else
		return false;
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

int Product::Save(std::string Path)
{
	char* CPath = (char*)malloc(Path.length() + 1);
	if (CPath != NULL)
	{
		Path.copy(CPath, Path.length());
		CPath[Path.length()] = '\0';
		int Result = this->Save(CPath);
		free(CPath);
		return Result;
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

int Product::SaveNew(std::string Path)
{
	char* CPath = (char*)malloc(Path.length() + 1);
	if (CPath != NULL)
	{
		Path.copy(CPath, Path.length());
		CPath[Path.length()] = '\0';
		int Result = this->SaveNew(CPath);
		free(CPath);
		return Result;
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

int Product::Load(std::string Path)
{
	char* CPath = (char*)malloc(Path.length() + 1);
	if (CPath != NULL)
	{
		Path.copy(CPath, Path.length());
		CPath[Path.length()] = '\0';
		int Result = this->Load(CPath);
		free(CPath);
		return Result;
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

int operator+(int Num, Product obj)
{
	return Num + obj.Count;
}
