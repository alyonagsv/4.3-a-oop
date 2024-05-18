#pragma once
#include <fstream>
using namespace std;
class Student
{
	char* name;
	char* gender;
	double progress;
	double age;
	int course;
public:
	Student& operator=(const Student& change)
	{
		if (this != &change)
		{
			this->age = change.age;
			this->course = change.course;
			this->progress = change.progress;
			this->name = change.name;
			this->gender = change.gender;
		}
		return *this;
	}
	void SetName(char* n);
	char* GetName() //const
	{
		return name;
	}
	void SetGender(char* n);
	char* GetGender()const;
	void SetAge(double a);
	void SetCourse(int c);
	int GetCourse()const;
	int GetAge()const;
	void SetProgress(int c);
	int GetProgress()const;
	Student(); // конструктор без параметров
	Student(const char* new_name, int new_age, int new_course, const  char* new_gender, double new_progress);  // заданным словом const char*, not char*
	Student(const Student& change);  // копирования
	Student(Student&& change);   // перемещения 

	~Student() {};
	void fill();  // ?????????? ? ??????????
	void print(); //const;  // ????? ?? ????? 
	void output_binary(const char* name_file);
	void save_binary(ofstream& file);
};