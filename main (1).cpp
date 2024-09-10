#include "student.h"

int main() {
    Group group;
    group.studentCount = 0; // Инициализируем количество студентов в группе

    // Создаем студентов
    Student student1 = {"Вика Ивлеева", 19};
    Student student2 = {"Иван Жур", 21};
    Student student3 = {"Вика Ивлеева", 20}; // Попытка добавить дубликат

    // Добавляем студентов в группу
    group += student1;
    group += student2;
    group += student3; // Здесь будет предупреждение о дубликате

    // Выводим информацию о группе
    group.print();

    return 0;
}
