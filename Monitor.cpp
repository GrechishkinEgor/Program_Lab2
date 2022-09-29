#include "Monitor.h"

Monitor InitMonitor()
{
	Monitor Init;
	Init.Diagonal = 0;
	Init.Frequency = 0;
	Init.Size[0] = 0;
	Init.Size[1] = 0;
	Init.AspectRatio[0] = 0;
	Init.AspectRatio[1] = 0;
	return Init;
}

Monitor InitMonitor(int Diagonal, int Frequency, int Size[2], int AspectRatio[2])
{
	Monitor Init = InitMonitor();
	if (Diagonal > 0)
		Init.Diagonal = Diagonal;
	if (Frequency > 0)
		Init.Frequency = Frequency;
	if (Size[0] > 0 && Size[1] > 0)
	{
		Init.Size[0] = Size[0];
		Init.Size[1] = Size[1];
	}
	if (AspectRatio[0] > 0 && AspectRatio[1] > 0)
	{
		Init.AspectRatio[0] = AspectRatio[0];
		Init.AspectRatio[1] = AspectRatio[1];
	}
	return Init;
}

void OutputAllInfoAboutMonitor(Monitor CurrentMonitor)
{
	printf("��������� ������� (� ������): %d\n", CurrentMonitor.Diagonal);
	printf("������� ���������� ������ (� ������): %d\n", CurrentMonitor.Frequency);
	printf("���������� ������: %d x %d\n", CurrentMonitor.Size[0], CurrentMonitor.Size[1]);
	printf("����������� ������: %d:%d\n", CurrentMonitor.AspectRatio[0], CurrentMonitor.AspectRatio[1]);
	return;
}

void InputAllInfoAboutMonitor(Monitor* CurrentMonitor)
{
	printf("������� ��������� ������� (� ������): ");
	scanf("%d", &CurrentMonitor->Diagonal);
	while (getchar() != '\n');
	printf("������� ������� ���������� ������ (� ������): ");
	scanf("%d", &CurrentMonitor->Frequency);
	while (getchar() != '\n');
	printf("������� ���������� ������ (��������, 1600 � 900; � - ���������): ");
	scanf("%d � %d", &CurrentMonitor->Size[0], &CurrentMonitor->Size[1]);
	while (getchar() != '\n');
	printf("������� ����������� ������ (��������, 16:9): ");
	scanf("%d : %d", &CurrentMonitor->AspectRatio[0], &CurrentMonitor->AspectRatio[1]);
	while (getchar() != '\n');
	return;
}
