#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Mouse.h"
#include "Printer.h"
#include "Keyboard.h"
#include "Monitor.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string Name = "TestString";
    std::string Company = "TestString2";
    Product FirstProduct(Name, Company, 100000, 10);
    //FirstProduct.OutputAllInfo();
    Product* ArrayOfProduct = new Product[5];
    for (int i = 0; i < 5; i++)
    {
        ArrayOfProduct[i].SetCount(i + 1);
        ArrayOfProduct[i].SetPrice((i + 1) * 1000);
    }

    std::string ReturnName = FirstProduct.GetName();
    std::string ReturnCompany = FirstProduct.GetCompany();
    std::cout << "Название: " << ReturnName << "; Компания: " << ReturnCompany << std::endl;

    Product::CalculateTotalCost(ArrayOfProduct, 5);
    printf("Совокупная стоимость 1: %g\n", Product::GetTotalCost() / 100.0);
    FirstProduct.AddInTotalCost();
    printf("Совокупная стоимость 2: %g\n", Product::GetTotalCost() / 100.0);
    Product::ResetTotalCost();
    printf("Совокупная стоимость 3: %g\n", Product::GetTotalCost() / 100.0);
    delete[] ArrayOfProduct;
    return 0;
}