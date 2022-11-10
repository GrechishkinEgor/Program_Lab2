#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Mouse.h"
#include "Printer.h"
#include "Keyboard.h"
#include "Monitor.h"
#include <vector>
#include <algorithm>
#include "Selling.h"

bool SortByNameAfterCompany(Product* obj1, Product* obj2)
{
    if (obj1->GetCompany() < obj2->GetCompany())
        return true;
    else
        if (obj1->GetCompany() == obj2->GetCompany())
            if (obj1->GetName() < obj2->GetName())
                return true;
            else
                return false;
        else
            return false;
}

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
    printf("-----\n");

    Selling<Monitor> SoldMonitor(FirstMonitor);
    SoldMonitor.OutputAllInfo();
    printf("-----\n");
    return 0;

    /*lab7*/
    std::vector<Product*> ProductLine;
    for (int i = 0; i < 4; i++)
    {
        std::string CurrentName;
        std::cin >> CurrentName;
        ProductLine.push_back(new Product(CurrentName, std::string("Enter Inc") + std::string(1, 'a' + (char)i % 2), (i + 1) * 50000, 20 - i));
    }
    try
    {
        ProductLine.insert(ProductLine.begin(), new Monitor("MonitorLikeProduct"));
    }
    catch (...)
    {
        std::cout << "Не удалось добавить монитор в массив" << std::endl;
    }

    for (int i = 0; i < ProductLine.size(); i++)
        std::cout << ProductLine[i]->GetName() << " - " << ProductLine[i]->GetCompany() << " - " << ProductLine[i]->GetPrice() << " - " << ProductLine[i]->GetCount() << std::endl;
    std::cout << std::endl;


    /*Сортировка по названиям товаров (алфавитный порядок)*/
    std::sort(ProductLine.begin(), ProductLine.end(), [](Product* obj1, Product* obj2) -> bool {return obj1->GetName() < obj2->GetName(); });
    for (int i = 0; i < ProductLine.size(); i++)
        std::cout << ProductLine[i]->GetName() << " - " << ProductLine[i]->GetCompany() << " - " << ProductLine[i]->GetPrice() << " - " << ProductLine[i]->GetCount() << std::endl;
    std::cout << std::endl;
    
    /*Сортировка по компанию-производителю, а затем по названию товара*/
    std::sort(ProductLine.begin(), ProductLine.end(), SortByNameAfterCompany);
    for (int i = 0; i < ProductLine.size(); i++)
        std::cout << ProductLine[i]->GetName() << " - " << ProductLine[i]->GetCompany() << " - " << ProductLine[i]->GetPrice() << " - " << ProductLine[i]->GetCount() << std::endl;
    std::cout << std::endl;

    /*Сортировка по цене товаров (по убыванию)*/
    std::sort(ProductLine.begin(), ProductLine.end(), [](Product* obj1, Product* obj2) -> bool {return obj1->GetPrice() > obj2->GetPrice(); });
    for (int i = 0; i < ProductLine.size(); i++)
        std::cout << ProductLine[i]->GetName() << " - " << ProductLine[i]->GetCompany() << " - " << ProductLine[i]->GetPrice() << " - " << ProductLine[i]->GetCount() << std::endl;
    std::cout << std::endl;

    /*Сортировка по количеству товаров определенного типа (по убыванию)*/
    std::sort(ProductLine.begin(), ProductLine.end(), [](Product* obj1, Product* obj2) -> bool {return obj1->GetCount() > obj2->GetCount(); });
    for (int i = 0; i < ProductLine.size(); i++)
        std::cout << ProductLine[i]->GetName() << " - " << ProductLine[i]->GetCompany() << " - " << ProductLine[i]->GetPrice() << " - " << ProductLine[i]->GetCount() << std::endl;
    std::cout << std::endl;


    /*Поиск по названию продукта*/
    std::string SearchName;
    std::cin >> SearchName;
    std::vector<Product*>::iterator SearchResult = std::find_if(ProductLine.begin(), ProductLine.end(), [SearchName](Product* obj) {return obj->GetName() == SearchName; });
    if (SearchResult != ProductLine.end())
        std::cout << **SearchResult;
    /*Найти ещё один подходящий элемент*/
    SearchResult++;
    std::vector<Product*>::iterator SearchResult2 = std::find_if(SearchResult, ProductLine.end(), [SearchName](Product* obj) {return obj->GetName() == SearchName; });
    if (SearchResult2 != ProductLine.end())
        std::cout << **SearchResult2;
    return 0;
}