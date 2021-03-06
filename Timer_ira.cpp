#include <iostream>
#include "stdio.h"
#include "stdafx.h"
#include "locale.h"
#include "iostream"
#include <string.h>
#include <conio.h>
using namespace std;

char on[] = "shutdown /s /t ";
const char off[50] = "shutdown -a";
char buffer[200] = { 0 };


char* concat(int minutes)
{
	buffer[0] = '\0';
	int second = minutes * 60;//перевела в секунды
	char string[200] = { 0 };
	sprintf_s(string, "%d", second);//перевела секунды (int) в тип char
	strcat_s(buffer, on);//конкатенация строк
	strcat_s(buffer, string);//конкатенация строк
	return buffer;
}



void switcher(int minutes)
{
	if (minutes == 0) {
		system(off);
	}
	else {
		system(concat(minutes));
	}

}



int main()
{
	setlocale(LC_ALL, "Russian");
	int minute = 0;

start:cout << "______________________________________________________________________  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tТАЙМЕР ОТКЛЮЧЕНИЯ ПК\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\nСправка: если ввести 0 (ноль), таймер отключится \n\n\n";
	cout << "Введите количество минут: ";
	cin >> minute; //ввела минуты


	if (minute == 0)
	{
		cout << "\n\nОтключить таймер выключения ПК?:\n" << "Да - ENTER\nНет - ESC\n" << endl;
		int code = _getch();
		if (code == 27) { system("cls"); goto start; }
		cout << "Таймер будет выключен" << endl;
		switcher(0);
		system("cls");
		goto start;

	}



	else if (minute>0 && minute<600)
	{
		cout << "\n\nУстановить таймер выключения ПК на: " << minute << " минут?\n" << "Да - ENTER\n Нет - ESC\n" << endl;
		int code = _getch();
		if (code == 27) { system("cls"); goto start; }
		cout << "Таймер будет установлен на - " << minute << " минут " << endl;
		switcher(0);
		switcher(minute);
		system("cls");
		goto start;

	}
	else {

		cout << "Превышенно допустимое количество минут\n";
		system("cls");
		goto start;
	}




	system("pause");
	return 0;
}