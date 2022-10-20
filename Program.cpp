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
    printf("Общее количество товаров: %d\n", Product::GetTotalCount());
    _getch();
    system("cls");

    Product FirstProduct("FirstProduct", "ProdInc", 500000);
    FirstProduct++;
    FirstProduct--;
    FirstProduct.OutputAllInfo();
    _getch();
    system("cls");

    FirstProduct.IncreaseCount();
    --FirstProduct;
    FirstProduct.OutputAllInfo();
    _getch();
    system("cls");

    ++FirstProduct;
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

    Product FirstAndSecond[2] = { FirstProduct, SecondProduct };
    OutputTableOfProduct(FirstAndSecond, 2);
    _getch();
    system("cls");

    Keyboard* KeybArray = new Keyboard[5];
    KeybArray[0].OutputAllInfo();
    _getch();
    system("cls");
    for (int i = 0; i < 5; i++)
    {
        KeybArray[i].SetCount(i);
        KeybArray[i]++;
        KeybArray[i].SetLengthOfCable(i * 10 + 100);
        KeybArray[i].SetTypeOfConnection("Проводная");
        KeybArray[i].OutputAllInfo();
        printf("----\n");
        printf("Общее количество товаров: %d\n", Product::GetTotalCount());
    }
    _getch();
    system("cls");

    FILE* Writer = fopen("NewKeyboards", "wb");
    for (int i = 0; i < 5 && Writer != NULL; i++)
        KeybArray[i].WriteInFile(Writer);
    if (Writer != NULL)
    {
        fclose(Writer);
        Writer = NULL;
        FILE* Reader = fopen("NewKeyboards", "rb");
        for (int i = 4; i >= 0 && Reader != NULL; i--)
            KeybArray[i].ReadFromFile(Reader);
        if (Reader != NULL)
        {
            fclose(Reader);
            Reader = NULL;
            for (int i = 0; i < 5; i++)
            {
                KeybArray[i].OutputAllInfo();
                printf("---\n");
            }
            _getch();
            system("cls");
        }
    }

    delete[] KeybArray;
    return 0;
}