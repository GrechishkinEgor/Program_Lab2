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
    Product FirstProduct;
    FirstProduct.SetName(Name);
    FirstProduct.SetCompany(Company);
    FirstProduct.OutputAllInfo();
    std::string ReturnName = FirstProduct.GetName();
    std::string ReturnCompany = FirstProduct.GetCompany();
    std::cout << "Название: " << ReturnName << "; Компания: " << ReturnCompany << std::endl;

    return 0;
}