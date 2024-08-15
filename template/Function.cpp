#include "Function.h"

void DataInitialization() {

	//создаем временный файл
	ofstream _buf("Buffer.txt");

	if (!_buf) {
		cout << "Ошибка создания файла!" << endl;
	}
	_buf.close();
}

void DataEntry() {

	string NameBook;
	string AuthorBook;
	int YearOfPublication;
	string GenreBook;
	int n;

	cout << "Введите количество данных: ";
	cin >> n;

	//открывает буферный файл и записываем в него данные
	ofstream record("Buffer.txt", ios::app); //запись в конец

	if (record){ //если файл открылся
		record << n << endl;

		for (int i = 0; i < n; i++) {

			cout << "Введите название книги: ";
			cin >> NameBook;

			cout << "Введите автора книги: ";
			cin >> AuthorBook;

			cout << "Введите год издания: ";
			cin >> YearOfPublication;

			cout << "Введите жанр книги: ";
			cin >> GenreBook;

			record << NameBook << endl;
			record << AuthorBook << endl;
			record << YearOfPublication << endl;

			if (i < n - 1) {
				record << GenreBook << endl;
			}
			else {
				record << GenreBook;
			}
			cout << "______________________________" << endl;
		}
	
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
	record.close();
}

void DataReading(string fileName) {
	 //чтение данных из файла

	ifstream reading(fileName); //читать
	ofstream record("Buffer.txt", ios::out); //записывать

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n;

			//считываем данные из файла
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {

				reading >> NameBook;
				reading >> AuthorBook;
				reading >> YearOfPublication;
				reading >> GenreBook;

				record << NameBook << endl;
				record << AuthorBook << endl;
				record << YearOfPublication << endl;

				if (i < n - 1) {
					record << GenreBook << endl;
				}
				else {
					record << GenreBook;
				}

			}
			cout << "Данные считаны" << endl;
		}
		else {
			cout << " Не удалось открыть буфер";
		}
	}
	else {
		cout << "Не удалость открыть файл";
	}
	reading.close();
	record.close();

}

void Print() {

	ifstream reading("Buffer.txt");

	if (reading) {

		string NameBook;
		string AuthorBook;
		int YearOfPublication;
		string GenreBook;
		int n;

		reading >> n;
		cout << "Количество данных: " << n << endl<< endl;

		for (int i = 0; i < n; i++) {
			cout << "Данные об #" << i + 1 << endl;

			reading >> NameBook;
			cout << "Название книги - " << NameBook << endl;

			reading >> AuthorBook;
			cout << "Автор книги - " << AuthorBook << endl;

			reading >> YearOfPublication;
			cout << "Год издания - " << YearOfPublication << endl;

			reading >> GenreBook;
			cout << "Жанр книги - " << GenreBook << endl;

			cout << "______________________________"<< endl;
		 }
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
	reading.close();
}

void DataChange() {
	//изменение данных
   //очистка буфера

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n, _n;

			reading >> n;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {

					if (i != _n) {

						reading >> NameBook;
						record << NameBook << endl;

						reading >> AuthorBook;
						record << AuthorBook << endl;

						reading >> YearOfPublication;
						record << YearOfPublication << endl;

						reading >> GenreBook;
						if (i < n - 1) {
							record << GenreBook << endl;
						}
						else {
							record << GenreBook;
						}

					}
					else {

						cout << "Введите название книги: ";
						cin >> NameBook;

						cout << "Введите автора книги: ";
						cin >> AuthorBook;

						cout << "Введите год издания: ";
						cin >> YearOfPublication;

						cout << "Введите жанр книги: ";
						cin >> GenreBook;

						record << NameBook << endl;
						record << AuthorBook << endl;
						record << YearOfPublication << endl;

						if (i < n - 1) {
							record << GenreBook << endl;
						}
						else {
							record << GenreBook;
						}
						reading >> NameBook;
						reading >> AuthorBook;
						reading >> YearOfPublication;
						reading >> GenreBook;
					}

				}
				cout << "Данные изменены" << endl;
			}
			else {
				cout << "Номер введен неверно" << endl;
			}

		}
		else {
			cout << "Не удалось открыть файл" << endl;
		}
	}
	else {
		cout << "Ошибка открытия буферного файла" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//копирование в новый файл

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n;

			//считываем данные из файла
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {

				reading >> NameBook;
				record << NameBook << endl;

				reading >> AuthorBook;
				record << AuthorBook << endl;

				reading >> YearOfPublication;
				record << YearOfPublication << endl;
			
				reading >> GenreBook;
				if (i < n - 1) {
					record << GenreBook << endl;
				}
				else {
					record << GenreBook;
				}

			}
			
		}
		else {
			cout << " Не удалось открыть файл";
		}
	}
	else {
		cout << "Не удалость открыть ,буферный файл";
	}
	reading.close();
	record.close();

}

int AmounthOfData() {

	//выводит количество данных из файла

	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {

		_buf >> n;

	}
	else {

		cout << "Не удалось открыть буферный файл" << endl;
	}

	_buf.close();
	return n;
}

void DeleteData(){
	//удаление данных
	// // запоминаем данные
   //перезаписываем в исходный буфер
	//кроме удаленного


	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {

					if (i != _n) {

						reading >> NameBook;
						record << NameBook << endl;

						reading >> AuthorBook;
						record << AuthorBook << endl;

						reading >> YearOfPublication;
						record << YearOfPublication << endl;

						reading >> GenreBook;
						if (i < n - 1) {
							record << GenreBook << endl;
						}
						else {
							record << GenreBook;
						}

					}
					else {
 
						reading >> NameBook;
						reading >> AuthorBook;
						reading >> YearOfPublication;
						reading >> GenreBook;
					}

				}
				cout << "Данные удалены" << endl;
			}
			else {
				cout << "Номер введен неверно" << endl;
			}

		}
		else {
			cout << "Не удалось открыть файл" << endl;
		}
	}
	else {
		cout << "Ошибка открытия буферного файла" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");

}

void AddData() {

	string NameBook;
	string AuthorBook;
	int YearOfPublication;
	string GenreBook;
	int n = AmounthOfData() + 1;

	ofstream record("Buffer.txt", ios::app); // в конец
	ofstream record_("Buffer.txt", ios::out | ios::in); //в начало

	if (record_) {
		record_ << n << endl;
	}
	else {

		cout << "Не удвлось открыть буферный файл" << endl;
	}

	if (record) {

		record << endl;

		cout << "Введите название книги: ";
		cin >> NameBook;

		cout << "Введите автора книги: ";
		cin >> AuthorBook;

		cout << "Введите год издания: ";
		cin >> YearOfPublication;

		cout << "Введите жанр книги: ";
		cin >> GenreBook;

		record << NameBook << endl;
		record << AuthorBook << endl;
		record << YearOfPublication << endl;
		record << GenreBook;

		
	}
	else {
		cout << "Ошибка открытия буферного файла" << endl;
	}
	record.close();
	record_.close();

}

void SaveData(string fileName) {

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);


	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {

				reading >> NameBook;
				record << NameBook << endl;

				reading >> AuthorBook;
				record << AuthorBook << endl;

				reading >> YearOfPublication;
				record << YearOfPublication << endl;

				reading >> GenreBook;
				if (i < n - 1) {
					record << GenreBook << endl;
				}
				else {
					record << GenreBook;
				}

			}

			cout << "Данные сохранены в файле - " << fileName << endl;

		}
		else {
			cout << "Не удалось открыть файл" << endl;
		}
	}
	else {
		cout << "Ошибка открытия буферного файла" << endl;
	}
	record.close();
	reading.close();

}

bool DataCleaning() {

	//очистка буфера

	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf) {

		cout << "Ошибка открытия файла" << endl;
	}

	//очищаем
	_buf.clear();

	//проверка что буфер чист
	if (_buf.peek() ==  EOF) { //первый элемент равен последнему

		clear = true;
	}
	else {

		clear = false;
	}
	_buf.close();

	return clear;

}
	
