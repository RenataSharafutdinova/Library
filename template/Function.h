#pragma once

#include <iostream> // поток ввода и вывода
#include <fstream> // работа с файлом
#include <string>
#include <Windows.h>

using namespace std;

//прототипы функций
void DataInitialization(); //инициализация данных
void DataEntry(); //ввод вручную
void DataReading(string fileName); //чтение
void Print(); //вывод
bool DataCleaning(); //очистка данных
void DataChange(); //редактирование данных
void Copy(); //копирование
int AmounthOfData(); //количество данных
void DeleteData(); //удаление
void AddData(); //добавление
void SaveData(string fileName); //сохранение

