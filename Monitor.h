#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct {
	int Diagonal;		//Диагональ матрицы в дюймах
	int Frequency;		//Частота обновления экрана монитора в герцах
	int Size[2];		//Разрешение экрана (число пикселей по горизонтали и вертикали)
	int AspectRatio[2];	//Соотношение сторон (16:9/16:10...)
}Monitor;

Monitor InitMonitor();
Monitor InitMonitor(int Diagonal, int Frequency, int Size[2], int AspectRatio[2]);

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor);
void InputAllInfoAboutMonitor(Monitor* CurrentMonitor);