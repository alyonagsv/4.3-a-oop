#include<iostream>
#include<fstream>
#include<iomanip>
#include "Student_bd.h"
#include "Student.h"
using namespace std;
Student_bd::Student_bd() { students = {}; };        // Конструктор без параметров
Student_bd::Student_bd(const vector<Student>& students) :
    students(students) {};        // Конструктор с параметрами (вектор студентов)
Student_bd::Student_bd(const Student_bd& other) :
    students(other.students) {};        // Конструктор копирования
Student_bd::Student_bd(Student_bd&& change) noexcept :
    students(move(change.students)) {};        // Конструктор перемещения

void Student_bd::addStudent()
{
    Student student;
    student.fill();
    students.push_back(student);
}
void Student_bd::loadDatabaseBinary(const char* filename)
{
    ifstream in(filename, ios::binary);
    if (!in.is_open())
    {
        cout << "error load" << endl;
    }
    else
    {
        for (auto& student : students)
        {
            //student.output_binary(filename);
            if (!in.read(reinterpret_cast<char*>(&student), sizeof(Student)))
                break;
        }
        in.close();
    }
}

void Student_bd::saveDatabaseBinary(const char* filename)
{
    ofstream out(filename, ios::binary);
    if (!out.is_open())
    {
        cout << "error save" << endl;
    }
    else
    {
        for (auto& student : students)
        {
            student.save_binary(out);
        }
        out.close();
    }
}

void Student_bd::print()
{
    for (auto& student : students)
    {
        student.print();
    }
}

void Student_bd::searchStudents(const string& name_search)
{
    bool studFind = 0;
    for (auto& student : students)
    {
        if (string(student.GetName()).find(name_search) != string::npos) // если строка не найдена, то значение find совпадает npos ( это статическая константа string, представляющая максимально возможное значение для типа size_t)
        {
            studFind = 1;
            student.print();
        }
    }
    if (studFind == 0)
        cout << "This student wasn't founded" << endl;
}
/*  void Student_bd::searchCharStudents(char* name_search)
  {
      for (auto& student : students)
      {
          if (student.GetName()== name_search)
          {
              student.print();
          }
      }
  }*/

void Student_bd::calculateAverageAge(int course)
{
    int count = 0;
    double totalAge = 0;
    double averege_age = 0;
    for (auto& student : students)
    {
        if (student.GetCourse() == course)
        {
            totalAge += student.GetAge();
            count++;
        }
    }
    if (count == 0)
    {
        cout << "there are no students for " << course << "course";
    }
    else
    {
        cout << "average age of students in " << course << " course:" << totalAge / count;

    }
    //return count > 0 ? static_cast<double>(totalAge) / count : 0.0;
}
