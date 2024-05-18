
#include <iomanip>     // setw
#include <iostream>   //  cin cout
#include<fstream>
#include"Student.h"
#include"Student_bd.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    Student_bd stud_bd1;
    cout << "реализация конструктора без параметров" << endl;
    stud_bd1.print();

    Student stud1("Sveta", 18, 1, "female", 8), stud2("Peter", 17, 1, "male", 7.5), stud3("Jane", 19, 2, "female", 9);
    vector<Student> Students = { stud1,stud2,stud3 };
    Student_bd stud_bd2(Students);    // конструктор с параметрами
    cout << "реализация конструктора с параметрами" << endl;
    stud_bd2.print();

    Student_bd stud_bd3 = stud_bd2;    // конструктор копирования
    cout << "реализация конструктора копирования" << endl;
    stud_bd3.print();

    Student_bd stud_bd4 = move(stud_bd3);    // конструктор перемещения
    cout << "реализация конструктора перемещения" << endl;
    stud_bd4.print();

    Student_bd stud_bd;
    int n;
    cout << "Enter quantity of student" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Добавление " << i + 1 << " студента в базу данных с вводом данных с клавиатуры" << endl;
        stud_bd.addStudent();    // Добавление студента в базу данных с вводом данных с клавиатуры
    }

    const char* filename = "studentsDataBase.bin";
    stud_bd.saveDatabaseBinary(filename);    
    stud_bd.loadDatabaseBinary(filename);    
    stud_bd.print();// выыод сохраненных данных о студентах
    cout << "enter name of student for search this :" << endl;
    char* search_name = new char;
    cin >> search_name;
    stud_bd.searchStudents(search_name);  
    int course;
    cout << "Введите номер курса для расчёта среднего возраста студентов на нём" << endl; // Расчет среднего возраста студентов на определенном курсе
    cin >> course;
    stud_bd.calculateAverageAge(course);
    return 0;
}
