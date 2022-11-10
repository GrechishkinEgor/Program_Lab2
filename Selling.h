#pragma once
#include "Product.h"
#include <iostream>

#define SELLING_CUSTOMER_MAX_SIZE 256
template <class ProductType> class Selling : public ProductType
{
private:
	int date[3];
	char customer[SELLING_CUSTOMER_MAX_SIZE];
public:
	Selling() : ProductType()
	{
		this->date[0] = 0;
		this->date[1] = 0;
		this->date[2] = 0;
		this->customer[0] = '\0';
	}
	Selling(ProductType info) : ProductType(info)
	{
		this->date[0] = 0;
		this->date[1] = 0;
		this->date[2] = 0;
		this->customer[0] = '\0';
	}
	Selling(ProductType info, const int date[3], const char* customer) : Selling(info)
	{
		this->SetDate(date);
		this->SetCustomer(customer);
	}
	Selling(const Selling& obj) : Selling(obj, obj.date, obj.customer)
	{

	}
	~Selling()
	{

	}

	bool SetDate(const int date[3])
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
	bool SetCustomer(const char* customer)
	{
		if (customer != NULL && strlen(customer) < SELLING_CUSTOMER_MAX_SIZE)
		{
			strcpy(this->customer, customer);
			return true;
		}
		else
			return false;
	}

	int* GetDate(int* date)
	{
		if (date != NULL)
		{
			date[0] = this->date[0];
			date[1] = this->date[1];
			date[2] = this->date[2];
		}
		return date;
	}
	char* GetCustomer(char* customer)
	{
		if (customer != NULL)
			strcpy(customer, this->customer);
		return customer;
	}
	void OutputAllInfo()
	{
		ProductType::OutputAllInfo();
		printf("ƒата сделки: %d:%d:%d\n", date[0], date[1], date[2]);
		printf("ѕокупатель: %s\n", customer);
		return;
	}

	/*«аписывает данные в открытый дл€ записи бинарный поток.
	¬озврат: 1 - успешно; 0 - передан нулевой указатель на поток*/
	int WriteInFile(FILE* BinaryWriterFile)
	{
		if (BinaryWriterFile == NULL)
			return 0;
		ProductType::WriteInFile(BinaryWriterFile);
		fwrite(this->date, sizeof(int), 3, BinaryWriterFile);
		fwrite(this->customer, sizeof(char), SELLING_CUSTOMER_MAX_SIZE, BinaryWriterFile);
		return 1;
	}
	/*ѕрочитать содержимое бинарного потока, открытого на чтение
	¬озврат: 0 - передан нулевой указатель на поток; 1 - успешно*/
	int ReadFromFile(FILE* BinaryReaderFile)
	{
		if (BinaryReaderFile == NULL)
			return 0;
		ProductType::ReadFromFile(BinaryReaderFile);
		fread(this->date, sizeof(int), 3, BinaryReaderFile);
		fread(this->customer, sizeof(char), SELLING_CUSTOMER_MAX_SIZE, BinaryReaderFile);
		return 1;
	}
};
