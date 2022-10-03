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

    char Type[] = "Беспроводная";
    Product FirstProduct = InitProduct();
    Mouse FirstMouse = InitMouse(FirstProduct, 500, 2, Type);
    Monitor FirstMonitor = InitMonitor();
    Keyboard FirstKeyboard = InitKeyboard();
    Printer FirstPrinter = InitPrinter();

    OutputAllInfoAboutProduct(FirstProduct);
    _getch();
    system("cls");

    IncreaseCountOfProduct(&FirstProduct);
    OutputAllInfoAboutProduct(FirstProduct);
    _getch();
    system("cls");

    DecreaseCountOfProduct(&FirstProduct);
    OutputAllInfoAboutProduct(FirstProduct);
    _getch();
    system("cls");

    Product* SecondProduct = (Product*)malloc(sizeof(Product));
    if (SecondProduct != NULL)
    {
        char Name[] = "Name";
        char Company[] = "Company";
        *SecondProduct = InitProduct(Name, Company, 200000, -1);
        OutputAllInfoAboutProduct(*SecondProduct);
        _getch();
        system("cls");

        char Path[] = "NewProduct";
        if (SaveNewProduct(FirstProduct, Path) == 1)
            printf("Файл успешно создан.\n");
        else
            printf("Ошибка: файл недоступен.\n");

        LoadProduct(SecondProduct, Path);
        OutputAllInfoAboutProduct(*SecondProduct);
        _getch();
        system("cls");

        free(SecondProduct);
        SecondProduct = NULL;
    }

    OutputAllInfoAboutMouse(FirstMouse);
    _getch();
    system("cls");
    char PathMouse[] = "NewMouse";
    FILE* Output = fopen(PathMouse, "wb");
    if (Output != NULL)
    {
        WriteMouseInFile(FirstMouse, Output);
        SetMouseLengthOfCable(&FirstMouse, 120);
        OutputAllInfoAboutMouse(FirstMouse);
        _getch();
        system("cls");
        WriteMouseInFile(FirstMouse, Output);
        fclose(Output);
        Output = NULL;
    }
    Mouse* ArrayOfMouse = (Mouse*)malloc(sizeof(Mouse) * 2);
    if (ArrayOfMouse != NULL)
    {
        FILE* Input = fopen(PathMouse, "rb");
        if (Input != NULL)
        {
            ReadMouseFromFile(ArrayOfMouse, Input);
            ReadMouseFromFile(ArrayOfMouse + 1, Input);
            OutputAllInfoAboutMouse(*ArrayOfMouse);
            printf("-----");
            OutputAllInfoAboutMouse(*(ArrayOfMouse + 1));
            _getch();
            system("cls");
            fclose(Input);
            Input = NULL;
        }
        free(ArrayOfMouse);
        ArrayOfMouse = NULL;
    }

    
    return 0;
}