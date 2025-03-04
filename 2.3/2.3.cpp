#include "StudentList.h"

int main() {
    setlocale(LC_ALL, "Rus");
    StudentList list;

    list.addStudent(Student("Иванов А.Б.", "2000-05-20", 2, 4.5));
    list.addStudent(Student("Петров В.Г.", "2001-12-03", 1, 2.3));
    list.addStudent(Student("Сидоров Д.Е.", "1999-08-15", 3, 2.9));
    list.addStudent(Student("Алексеева Ж.З.", "2002-03-10", 2, 3.1));

    list.print("Исходный список");

    StudentList failing = list.extractFailingStudents();
    failing.print("Неуспевающие студенты");
    list.print("Обновленный исходный список");

    return 0;
}