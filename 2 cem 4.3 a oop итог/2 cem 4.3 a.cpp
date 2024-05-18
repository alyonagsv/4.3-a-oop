
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
    cout << "���������� ������������ ��� ����������" << endl;
    stud_bd1.print();

    Student stud1("Sveta", 18, 1, "female", 8), stud2("Peter", 17, 1, "male", 7.5), stud3("Jane", 19, 2, "female", 9);
    vector<Student> Students = { stud1,stud2,stud3 };
    Student_bd stud_bd2(Students);    // ����������� � �����������
    cout << "���������� ������������ � �����������" << endl;
    stud_bd2.print();

    Student_bd stud_bd3 = stud_bd2;    // ����������� �����������
    cout << "���������� ������������ �����������" << endl;
    stud_bd3.print();

    Student_bd stud_bd4 = move(stud_bd3);    // ����������� �����������
    cout << "���������� ������������ �����������" << endl;
    stud_bd4.print();

    Student_bd stud_bd;
    int n;
    cout << "Enter quantity of student" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "���������� " << i + 1 << " �������� � ���� ������ � ������ ������ � ����������" << endl;
        stud_bd.addStudent();    // ���������� �������� � ���� ������ � ������ ������ � ����������
    }

    const char* filename = "studentsDataBase.bin";
    stud_bd.saveDatabaseBinary(filename);    
    stud_bd.loadDatabaseBinary(filename);    
    stud_bd.print();// ����� ����������� ������ � ���������
    cout << "enter name of student for search this�:" << endl;
    char* search_name = new char;
    cin >> search_name;
    stud_bd.searchStudents(search_name);  
    int course;
    cout << "������� ����� ����� ��� ������� �������� �������� ��������� �� ��" << endl; // ������ �������� �������� ��������� �� ������������ �����
    cin >> course;
    stud_bd.calculateAverageAge(course);
    return 0;
}
