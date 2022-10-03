#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Mouse.h"
#include "Printer.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Mouse FirstMouse = InitMouse();
    OutputAllInfoAboutMouse(FirstMouse);
    Product FirstProduct = InitProduct();
    OutputAllInfoAboutProduct(FirstProduct);
    Printer FirstPrinter = InitPrinter();
    OutputAllInfoAboutPrinter(FirstPrinter);
    return 0;
}