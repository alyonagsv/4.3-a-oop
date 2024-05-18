#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include"Student.h"
using namespace std;

void Student::SetAge(double a)
{
	age = a;
}
void Student::SetCourse(int g)
{
	course = g;
}
int Student::GetAge() const
{
	return age;
}
int Student::GetCourse() const
{
	return course;
}
void Student::SetName(char* n)
{
	name = n;
}
void Student::SetGender(char* n)
{
	gender = n;
}
char* Student::GetGender() const
{
	return gender;
}
void Student::SetProgress(int g)
{
	progress = g;
}
int Student::GetProgress() const
{
	return progress;
}

Student::Student()   // конструктор без параметров
{
	name = (nullptr);
	age = 0;
	course = 0;
	gender = (nullptr);
	progress = 0.0;
}

Student::Student(const char* new_name, int new_age, int new_course, const char* new_gender, double new_progress)  // заданными словами 
{
	name = new char[strlen(new_name) + 1];
	int n = strlen(new_name) + 1;
	strcpy_s(name, n, new_name);
	this->age = new_age;
	this->course = new_course;

	gender = new char[strlen(new_gender) + 1];
	int  size = strlen(new_gender) + 1;
	strcpy_s(gender, size, new_gender);
	this->progress = new_progress;
}

Student::Student(const Student& change)  // копирования
{
	this->age = change.age;
	this->course = change.course;
	this->progress = change.progress;
	this->name = change.name;
	this->gender = change.gender;
}

Student::Student(Student&& change)  // перемещения 
{
	this->age = change.age;
	this->course = change.course;
	this->progress = change.progress;
	this->name = change.name;
	this->gender = change.gender;

	change.name = nullptr;
	change.gender = nullptr;
	change.course = NULL;
	change.progress = NULL;
	change.age = NULL;
}

void Student::fill()// noexcept // заполнение с клавиатуры 
{
	cin.ignore();
	cout << "ФИО: ";
	char str[50];
	cin.getline(str, 50);
	int size = strlen(str) + 1;
	name = new char[size];
	strcpy_s(name, size, str);

	cout << "Возраст: ";
	cin >> this->age;
	cin.ignore();

	cout << "Курс: ";
	cin >> this->course;
	cin.ignore();

	cout << "Пол: ";
	char str1[50];
	cin.getline(str1, 20);
	int size1 = strlen(str1) + 1;
	gender = new char[size1];
	strcpy_s(gender, size1, str1);


	cout << "Успеваемость: ";
	cin >> this->progress;
	cout << endl;
}

void  Student::print() //const // вывод на экран слова
{
	cout << this->name << setw(5);
	cout << this->age << setw(9);
	cout << this->course << setw(9);
	cout << this->gender << setw(6);
	cout << this->progress << endl << endl;
}

void Student::save_binary(ofstream& file) // Сохранение в бинарный файл
{
	//ofstream file(name_file,/* ios::app,*/ ios::binary);
	if (!file.is_open())
	{
		cout << "error save" << endl;
	}
	file.write(reinterpret_cast<char*>(this), sizeof(Student));

	//file.close();
}
void Student::output_binary(const char* name_file) // загрузка из бинарного файла
{
	ifstream infile(name_file, /*ios::app,*/ ios::binary);
	if (!infile.is_open())
	{
		cout << "error load/ output" << endl;
	}
	infile.read(reinterpret_cast<char*>(this), sizeof(Student));
	infile.close();
}
