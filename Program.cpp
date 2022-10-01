#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Product.h"

//void CreateNewProduct();
//void LookInfoAboutProduct();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*int UserChoice = 0;
    while (UserChoice != 27)
    {
        UserChoice = 0;
        system("cls");
        printf("1 - Ввести информацию о новом товаре;\n"
            "2 - Посмотреть информацию о товаре;\n"
            "Esc - выйти из программы.\n"
        );
        while (UserChoice != '1' && UserChoice != '2' && UserChoice != 27)
            UserChoice = _getch();
        switch (UserChoice)
        {
        case '1':
            CreateNewProduct();
            break;
        case '2':
            LookInfoAboutProduct();
            break;
        }
    }*/



    return 0;
}



/*
void CreateNewProduct()
{
    Product CurrentProduct;
    system("cls");
    InputAllInfoAboutProduct(&CurrentProduct);
    int FlagSuccessfullWritting = 0;
    while (!FlagSuccessfullWritting)
    {
        char Path[256] = "\0";
        while (strlen(Path) == 0)
        {
            printf("Введите название файла, в который будут сохранены данные: ");
            scanf_s("%s", Path, 256);
            while (getchar() != '\n');
        }
        switch (WriteProductInFile(CurrentProduct, Path))
        {
        case 0:
            printf("Данные успешно сохранены.\n");
            FlagSuccessfullWritting = 1;
            printf("Нажмите любую клавишу, чтобы продолжить.\n");
            _getch();
            break;
        case 1:
            printf("Файл с таким именем уже существует.\n");
            break;
        case -1:
            printf("Произошла ошибка при открытии файла.\n");
            break;
        }
        if (!FlagSuccessfullWritting)
        {
            printf("Нажмите 1, чтобы повторить попытку записи.\n"
                "Нажмите любую другую клавишу, чтобы не сохранять данные.\n"
            );
            if (_getch() != '1')
                FlagSuccessfullWritting = 1;
        }
    }
    
    return;
}

void LookInfoAboutProduct()
{
    system("cls");
    Product* CurrentProduct = (Product*)malloc(sizeof(Product));
    if (CurrentProduct == NULL)
    {
        printf("Ошибка выделения памяти под товар.\n"
            "Нажмите любую клавишу, чтобы продолжить.\n"
        );
        _getch();
        return;
    }
    char Path[256] = "\0";
    while (strlen(Path) == 0)
    {
        printf("Введите имя файла с данными о товаре: ");
        scanf_s("%s", Path, 256);
        while (getchar() != '\n');
    }
    if (ReadProductFromFile(CurrentProduct, Path))
    {
        printf("Файл не найден или недоступен.\n"
            "Нажмите любую клавишу, чтобы продолжить.\n"
        );
        _getch();
        return;
    }
    int UserChoice = 0;
    while (UserChoice != 27)
    {
        UserChoice = 0;
        system("cls");
        printf("Сведения о товаре:\n");
        printf("-------\n");
        OutputAllInfoAboutProduct(*CurrentProduct);
        printf("-------\n");
        printf("1 - увеличить количество товара на один;\n"
            "2 - уменьшить количество товара на один;\n"
            "3 - задать своё количество товара;\n"
            "4 - изменить цену товара;\n"
            "Esc - сохранить данные и вернуться.\n"
        );
        while ((UserChoice < '1' || UserChoice > '4') && UserChoice != 27)
            UserChoice = _getch();
        switch (UserChoice)
        {
        case '1':
            IncreaseCountOfProduct(CurrentProduct);
            break;
        case '2':
            DecreaseCountOfProduct(CurrentProduct);
            break;
        case '3':
        {
            int NewCount = 0;
            printf("Введите количество товара (штук): ");
            scanf("%d", &NewCount);
            while (getchar() != '\n');
            SetCountOfProduct(CurrentProduct, NewCount);
            break;
        }
        case '4':
        {
            int NewPrice = 0;
            printf("Введите новую цену (в копейках!): ");
            scanf("%d", &NewPrice);
            while (getchar() != '\n');
            SetPriceOfProduct(CurrentProduct, NewPrice);
            break;
        }
        case 27:
            if (SaveProduct(*CurrentProduct, Path))
            {
                printf("Произошла ошибка при сохранении данных.\n");
                printf("Нажмите 1, чтобы вернуться.\n"
                    "Нажмите любую другую клавишу, чтобы продолжить работу.\n"
                );
                if (_getch() != '1')
                    UserChoice = 0;
            }
            break;
        }
    }
    if (CurrentProduct != NULL)
    {
        free(CurrentProduct);
        CurrentProduct = NULL;
    }
    return;
}*/