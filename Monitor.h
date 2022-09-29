#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct {
	int Diagonal;		//��������� ������� � ������
	int Frequency;		//������� ���������� ������ �������� � ������
	int Size[2];		//���������� ������ (����� �������� �� ����������� � ���������)
	int AspectRatio[2];	//����������� ������ (16:9/16:10...)
}Monitor;

Monitor InitMonitor();
Monitor InitMonitor(int Diagonal, int Frequency, int Size[2], int AspectRatio[2]);

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor);
void InputAllInfoAboutMonitor(Monitor* CurrentMonitor);