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

   /* Product FirstProduct, SecondProduct;
    FirstProduct++;
    SecondProduct++;
    FirstProduct.SetPrice(500000);
    SecondProduct.SetPrice(600000);
    FirstProduct.AddInTotalCost();
    SecondProduct.AddInTotalCost();
    printf("Общая стоимость товаров: %g\n", Product::GetTotalCost() / 100.0);
    Product* Array = new Product[3];
    for (int i = 0; i < 3; i++)
    {
        Array[i].SetPrice(200000);
        Array[i].SetCount(i + 1);
    }
    //Product::ResetTotalCost();
    Product::CalculateTotalCost(Array, 3);
    printf("Общая стоимость товаров: %g", Product::GetTotalCost() / 100.0);*/

    Mouse FirstMouse;
    FirstMouse.SetName("Mouse");
    FirstMouse.SetSensitivity(500);
    Product* MouseLikeProduct = &FirstMouse;
    MouseLikeProduct->Save("MouseLikeProduct.txt");
    Mouse SecondMouse;
    SecondMouse.Load("MouseLikeProduct.txt");
    SecondMouse.OutputAllInfo();

    return 0;
}