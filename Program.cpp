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
    FirstProduct.OutputAllInfo();
    printf("----\n");
    FirstProduct.Save("Product1");
    try
    {
        Product SecondProduct("Product1");
        SecondProduct.OutputAllInfo();
    }
    catch (const char* e)
    {
        printf("Произошла ошибка: %s\n", e);
    }

    try
    {
        Product ThirdProduct("Product2");
        ThirdProduct.OutputAllInfo();
    }
    catch (const char* e)
    {
        printf("Произошла ошибка: %s\n", e);
    }
    return 0;
}