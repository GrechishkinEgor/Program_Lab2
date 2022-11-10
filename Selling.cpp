#include "Selling.h"
/*
template<class ProductType>
Selling<ProductType>::Selling()
{
	this->date[0] = 0;
	this->date[1] = 0;
	this->date[2] = 0;
	this->customer[0] = '\0';
}

template<class ProductType>
Selling<ProductType>::Selling(ProductType* info) : Selling()
{
	this->info = new ProductType(*info);
}

template<class ProductType>
Selling<ProductType>::Selling(ProductType* info, const int date[3], const char* customer) : Selling(info)
{
	this->SetDate(date);
	this->SetCustomer(customer);
}

template<class ProductType>
Selling<ProductType>::Selling(const Selling& obj) : Selling(obj.info, obj.date, obj.customer)
{

}

template<class ProductType>
Selling<ProductType>::~Selling()
{
}

template<class ProductType>
bool Selling<ProductType>::SetDate(const int date[3])
{
	if (date[0] >= 1 && date[0] <= 31 && date[1] >= 1 && date[1] <= 12 && date[2] > 0)
	{
		this->date[0] = date[0];
		this->date[1] = date[1];
		this->date[2] = date[2];
		return true;
	}
	else
		return false;
}

template<class ProductType>
bool Selling<ProductType>::SetCustomer(const char* customer)
{
	if (customer != NULL && strlen(customer) < SELLING_CUSTOMER_MAX_SIZE)
	{
		strcpy(this->customer, customer);
		return true;
	}
	else
		return false;
}

template<class ProductType>
int* Selling<ProductType>::GetDate(int* date)
{
	if (date != NULL)
	{
		date[0] = this->date[0];
		date[1] = this->date[1];
		date[2] = this->date[2];
	}
	return date;
}

template<class ProductType>
char* Selling<ProductType>::GetCustomer(char* customer)
{
	if (customer != NULL)
		strcpy(customer, this->customer);
	return customer;
}

template<class ProductType>
void Selling<ProductType>::OutputAllInfo()
{
	info->OutputAllInfo();
	printf("Дата сделки: %d:%d:%d\n", date[0], date[1], date[2]);
	printf("Покупатель: %s\n", customer);
	return;
}

template<class ProductType>
int Selling<ProductType>::WriteInFile(FILE* BinaryWriterFile)
{
	if (BinaryWriterFile == NULL)
		return 0;
	info->WriteInFile(BinaryWriterFile);
	fwrite(this->date, sizeof(int), 3, BinaryWriterFile);
	fwrite(this->customer, sizeof(char), SELLING_CUSTOMER_MAX_SIZE, BinaryWriterFile);
	return 1;
}

template<class ProductType>
int Selling<ProductType>::ReadFromFile(FILE* BinaryReaderFile)
{
	if (BinaryReaderFile == NULL)
		return 0;
	info->ReadFromFile(BinaryReaderFile);
	fread(this->date, sizeof(int), 3, BinaryReaderFile);
	fread(this->customer, sizeof(char), SELLING_CUSTOMER_MAX_SIZE, BinaryReaderFile);
	return 1;
}
*/