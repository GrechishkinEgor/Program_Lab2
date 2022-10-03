#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Product.h"

typedef struct {
	Product General;
	int Diagonal;		//��������� ������� � ������
	int Frequency;		//������� ���������� ������ �������� � ������
	int Size[2];		//���������� ������ (����� �������� �� ����������� � ���������)
	int AspectRatio[2];	//����������� ������ (16:9/16:10...)
}Monitor;

Monitor InitMonitor();
Monitor InitMonitor(Product General);
Monitor InitMonitor(Product General, int Diagonal, int Frequency, int Size[2], int AspectRatio[2]);

int SetMonitorGeneral(Monitor* CurrentMonitor, Product General);
int SetMonitorDiagonal(Monitor* CurrentMonitor, int Diagonal);
int SetMonitorFrequency(Monitor* CurrentMonitor, int Frequency);
int SetMonitorSize(Monitor* CurrentMonitor, int Width, int Height);
int SetMonitorAspectRatio(Monitor* CurrentMonitor, int AspectRatio1, int AspectRatio2);

Product GetMonitorGeneral(Monitor CurrentMonitor);
int GetMonitorDiagonal(Monitor CurrentMonitor);
int GetMonitorFrequency(Monitor CurrentMonitor);
void GetMonitorSize(Monitor CurrentMonitor, int* Width, int* Height);
void GetMonitorAspectRatio(Monitor CurrentMonitor, int* AspectRatio1, int* AspectRatio2);

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor);

/*��������� ���������� � ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������*/
int SaveMonitor(Monitor CurrentProduct, char* Path);
/*��������� ���������� � ����� ������ � ���� (���� - Path)
�������: 1 - �������; 0 - ���� �� ��������; -1 - ���� ��� ����������*/
int SaveNewMonitor(Monitor CurrentProduct, char* Path);
/*���������� ������ � ������ � �������� ��� ������ �������� �����
�������: 1 - ������ ���� ��������; 0 - ������� ������� ��������� �� �����*/
int WriteMonitorInFile(Monitor CurrentProduct, FILE* BinaryWriterFile);

/*������� ������ � ������ �� ����� (���� - Path)
�������: 1 - �������; 0 - ����� �� ���������� ��� ����������; -1 - ������� ������� ��������� �� ���������*/
int LoadMonitor(Monitor* CurrentProduct, char* Path);
/*��������� ������ � ������ �� ��������� ������, ��������� �� ������
�������: 1 - �������; -1 - ��������� ����� ������; 0 - ������� ������� ��������� �� ���� ��� ���������*/
int ReadMonitorFromFile(Monitor* CurrentProduct, FILE* BinaryReaderFile);