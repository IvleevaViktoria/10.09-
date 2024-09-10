#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30
#define NAME_LENGTH 50

// Структура для хранения информации о студенте
struct Student {
    char name[NAME_LENGTH];
    int age;
};

// Структура для группы
struct Group {
    Student students[MAX_STUDENTS];
    int studentCount;

    // Оператор сложения для добавления студента
    Group& operator+=(const Student& student) {
        if (studentCount < MAX_STUDENTS) {
            if (!isStudentExists(student.name)) { // Проверка на наличие студента
                strncpy(students[studentCount].name, student.name, NAME_LENGTH - 1);
                students[studentCount].name[NAME_LENGTH - 1] = '\0'; // Обеспечивает нуль
                students[studentCount].age = student.age;
                studentCount++;
            } else {
                printf("Студент %s уже есть в группе!\n", student.name);
            }
        } else {
            printf("Группа полна!\n");
        }
        return *this;
    }

    // Функция для проверки наличия студента
    bool isStudentExists(const char* name) const {
        for (int i = 0; i < studentCount; ++i) {
            if (strcmp(students[i].name, name) == 0) {
                return true; // Студент найден
            }
        }
        return false; // Студент не найден
    }

    // Функция для отображения списка студентов
    void print() const {
        printf("Список студентов в группе:\n");
        for (int i = 0; i < studentCount; ++i) {
            printf("Студент %d: %s, Возраст: %d\n", i + 1, students[i].name, students[i].age);
        }
    }
};

#endif
