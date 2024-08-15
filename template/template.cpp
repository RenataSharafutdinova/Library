#include "Function.h"

int stateMenu;
void Menu() {
	cout << "Выберите действие: " << endl
		<< "0 - Выход из программы" << endl
		<< "1 - Ввод данных" << endl
		<< "2 - Вывод данных" << endl
		<< "3 - Изменение данных" << endl
		<< "4 - Удаление данных" << endl
		<< "5 - Добавление данных" << endl
		<< "6 - Сохранение данных" << endl
		<< "Ваш выбор: ";
	cin >> stateMenu;

}
/*Учет книг в библиотеке
  -название книги
	-автор книги
	-год издания
	-жанр книги*/

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DataInitialization();

	Menu();

	int actions;
	string fileName;

	while (stateMenu != 0) {
		switch (stateMenu)
		{
		case 1:
			system("cls");
			cout << "ввод вручную или из файла?";
			cin >> actions;

			system("cls");

			if (actions == 1) {
				DataEntry();//вручную
			}
			else {
				//чтение из файла
				cout << "Введите название файла: ";
				cin >> fileName;

				DataReading(fileName);

			}
			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////
		case 2:
			system("cls");

			Print();

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////
		case 3:
			system("cls");

			DataChange();

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////
		case 4:
			system("cls");

			DeleteData();

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////
		case 5:
			system("cls");

			AddData();

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////
		case 6:
			system("cls");

			cout << "Введите название файла: ";
			cin >> fileName;

			SaveData(fileName);

			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
	system("cls");//очищение консоли

	if (DataCleaning()) {
		cout << "Данные очищены"<<endl;

	}
	else {
		cout << "Данные не очищены"<<endl;
	}
	cout << "Работа завершена" << endl;
	system("pause");
}
