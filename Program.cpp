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
    char Path[] = "New";
    SaveMouse(FirstMouse, Path);
    char TypeOfConnection[] = "Проводная";
    Mouse SecondMouse = InitMouse(FirstProduct, 5, 5, TypeOfConnection);
    LoadMouse(&SecondMouse, Path);
    OutputAllInfoAboutMouse(SecondMouse);
    return 0;
}