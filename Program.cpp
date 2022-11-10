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

    /*lab5*/
    std::string Name = "TestString";
    std::string Company = "TestString2";
    Product FirstProduct(Name, Company, 100000, 10);
    FirstProduct.OutputAllInfo();
    printf("----\n");
    FirstProduct.Save("Product1");
    try
    {
        Product SecondProduct("Product1");
        //SecondProduct.OutputAllInfo();
        std::cout << SecondProduct;
        printf("-----\n");
    }
    catch (const char* e)
    {
        printf("Произошла ошибка: %s\n", e);
    }

    try
    {
        Product ThirdProduct("Product2");
        ThirdProduct.OutputAllInfo();
        printf("-----\n");
    }
    catch (const char* e)
    {
        printf("Произошла ошибка: %s\n", e);
    }

    /*lab6*/
    Monitor FirstMonitor;
    FirstMonitor = FirstProduct;
    FirstMonitor.SetDiagonal(50);
    std::cout << FirstMonitor;
    printf("-----\n");
    Product* PointerOnProduct = &FirstMonitor;
    PointerOnProduct->Save("MonitorLikeProduct");
    Product* SecondPointerOnProduct = new Monitor();
    SecondPointerOnProduct->Load("MonitorLikeProduct");
    std::cout << *SecondPointerOnProduct;
    printf("-----\n");
    std::cout << *((Monitor*)SecondPointerOnProduct);
    printf("-----'n");
    return 0;
}