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

    Product FirstProduct("FirstProduct", "ProdInc", 500000);
    FirstProduct.OutputAllInfo();
    _getch();
    system("cls");

    FirstProduct.IncreaseCount();
    FirstProduct.OutputAllInfo();
    _getch();
    system("cls");

    FirstProduct.DecreaseCount();
    FirstProduct.OutputAllInfo();
    _getch();
    system("cls");

    FirstProduct.Save("NewProduct");
    Product SecondProduct;
    SecondProduct.Load("NewProduct");
    SecondProduct.OutputAllInfo();
    _getch();
    system("cls");


    return 0;
}