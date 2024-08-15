#include "Function.h"

void DataInitialization() {

	//������� ��������� ����
	ofstream _buf("Buffer.txt");

	if (!_buf) {
		cout << "������ �������� �����!" << endl;
	}
	_buf.close();
}

void DataEntry() {

	string NameBook;
	string AuthorBook;
	int YearOfPublication;
	string GenreBook;
	int n;

	cout << "������� ���������� ������: ";
	cin >> n;

	//��������� �������� ���� � ���������� � ���� ������
	ofstream record("Buffer.txt", ios::app); //������ � �����

	if (record){ //���� ���� ��������
		record << n << endl;

		for (int i = 0; i < n; i++) {

			cout << "������� �������� �����: ";
			cin >> NameBook;

			cout << "������� ������ �����: ";
			cin >> AuthorBook;

			cout << "������� ��� �������: ";
			cin >> YearOfPublication;

			cout << "������� ���� �����: ";
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
		cout << "�� ������� ������� ����" << endl;
	}
	record.close();
}

void DataReading(string fileName) {
	 //������ ������ �� �����

	ifstream reading(fileName); //������
	ofstream record("Buffer.txt", ios::out); //����������

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n;

			//��������� ������ �� �����
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
			cout << "������ �������" << endl;
		}
		else {
			cout << " �� ������� ������� �����";
		}
	}
	else {
		cout << "�� �������� ������� ����";
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
		cout << "���������� ������: " << n << endl<< endl;

		for (int i = 0; i < n; i++) {
			cout << "������ �� #" << i + 1 << endl;

			reading >> NameBook;
			cout << "�������� ����� - " << NameBook << endl;

			reading >> AuthorBook;
			cout << "����� ����� - " << AuthorBook << endl;

			reading >> YearOfPublication;
			cout << "��� ������� - " << YearOfPublication << endl;

			reading >> GenreBook;
			cout << "���� ����� - " << GenreBook << endl;

			cout << "______________________________"<< endl;
		 }
	}
	else {
		cout << "�� ������� ������� ����" << endl;
	}
	reading.close();
}

void DataChange() {
	//��������� ������
   //������� ������

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

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
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

						cout << "������� �������� �����: ";
						cin >> NameBook;

						cout << "������� ������ �����: ";
						cin >> AuthorBook;

						cout << "������� ��� �������: ";
						cin >> YearOfPublication;

						cout << "������� ���� �����: ";
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
				cout << "������ ��������" << endl;
			}
			else {
				cout << "����� ������ �������" << endl;
			}

		}
		else {
			cout << "�� ������� ������� ����" << endl;
		}
	}
	else {
		cout << "������ �������� ��������� �����" << endl;
	}
	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy() {
	//����������� � ����� ����

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {

			string NameBook;
			string AuthorBook;
			int YearOfPublication;
			string GenreBook;
			int n;

			//��������� ������ �� �����
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
			cout << " �� ������� ������� ����";
		}
	}
	else {
		cout << "�� �������� ������� ,�������� ����";
	}
	reading.close();
	record.close();

}

int AmounthOfData() {

	//������� ���������� ������ �� �����

	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {

		_buf >> n;

	}
	else {

		cout << "�� ������� ������� �������� ����" << endl;
	}

	_buf.close();
	return n;
}

void DeleteData(){
	//�������� ������
	// // ���������� ������
   //�������������� � �������� �����
	//����� ����������


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

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
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
				cout << "������ �������" << endl;
			}
			else {
				cout << "����� ������ �������" << endl;
			}

		}
		else {
			cout << "�� ������� ������� ����" << endl;
		}
	}
	else {
		cout << "������ �������� ��������� �����" << endl;
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

	ofstream record("Buffer.txt", ios::app); // � �����
	ofstream record_("Buffer.txt", ios::out | ios::in); //� ������

	if (record_) {
		record_ << n << endl;
	}
	else {

		cout << "�� ������� ������� �������� ����" << endl;
	}

	if (record) {

		record << endl;

		cout << "������� �������� �����: ";
		cin >> NameBook;

		cout << "������� ������ �����: ";
		cin >> AuthorBook;

		cout << "������� ��� �������: ";
		cin >> YearOfPublication;

		cout << "������� ���� �����: ";
		cin >> GenreBook;

		record << NameBook << endl;
		record << AuthorBook << endl;
		record << YearOfPublication << endl;
		record << GenreBook;

		
	}
	else {
		cout << "������ �������� ��������� �����" << endl;
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

			cout << "������ ��������� � ����� - " << fileName << endl;

		}
		else {
			cout << "�� ������� ������� ����" << endl;
		}
	}
	else {
		cout << "������ �������� ��������� �����" << endl;
	}
	record.close();
	reading.close();

}

bool DataCleaning() {

	//������� ������

	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf) {

		cout << "������ �������� �����" << endl;
	}

	//�������
	_buf.clear();

	//�������� ��� ����� ����
	if (_buf.peek() ==  EOF) { //������ ������� ����� ����������

		clear = true;
	}
	else {

		clear = false;
	}
	_buf.close();

	return clear;

}
	
