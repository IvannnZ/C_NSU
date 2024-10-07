///8 Функции. Стек вызовов. Фреймы функций. Адрес возврата


/*
    Аргументы функции: Если у функции есть аргументы (параметры), они передаются и сохраняются в фрейме. В C аргументы
    могут быть переданы по значению или по ссылке.

    Локальные переменные: Локальные переменные, объявленные внутри функции, хранятся в фрейме. Они существуют только в
    пределах своей функции и не доступны из других функций.

    Адрес возврата: После завершения работы функции управление должно вернуться в место вызова. Для этого во фрейме
    функции сохраняется адрес возврата - адрес инструкции в памяти, которая должна быть выполнена после завершения работы функции.

    Указатель на предыдущий фрейм (если применимо): В некоторых системах стек вызовов хранит указатель на предыдущий
    фрейм, что позволяет системе вернуться к предыдущему состоянию стека после завершения функции.

    Другие управляющие данные: Фрейм также может содержать другие управляющие данные, такие как адреса возврата в
    случае рекурсивного вызова функции, регистры процессора и другие системные данные.
*/


//#include <stdio.h>
//
//void functionB() {
//    printf("Inside functionB\n");
//}
//
//void functionA() {
//    printf("Inside functionA\n");
//    functionB();
//}
//
//int main() {
//    printf("Inside main\n");
//    functionA();
//    return 0;
//}

//#include <stdio.h>
//
//void myFunction() {
//    printf("Hello from myFunction!\n");
//}
//
//int main() {
//    void (*funcPtr)() = &myFunction; // Получение адреса функции myFunction
//    (*funcPtr)(); // Вызов функции через указатель на функцию
//    return 0;
//}
















///17. Композиция. Реализация массивом байтов




#include <stdio.h>
#include <stdint.h>

struct Person {
    uint8_t age;
    float height;
    float weight;
};

void fillByteArray(uint8_t *byteArray, struct Person person) {
    byteArray[0] = person.age;
    uint8_t *floatBytes = (uint8_t *) &person.height;
    size_t offset = 1;
    for (int i = 0; i < sizeof(float); i++) {
        byteArray[offset + i] = floatBytes[i];
    }
    offset += sizeof(float);
    uint8_t *floatBytesWeight = (uint8_t *) &person.weight;
    for (int i = 0; i < sizeof(float); i++) {
        byteArray[offset + i] = floatBytesWeight[i];
    }
}

struct Person getPersonFromByteArray(uint8_t *byteArray) {
    struct Person person;
    person.age = byteArray[0];
    size_t offset = 1;
    uint8_t *floatBytes = (uint8_t *) &person.height;
    for (int i = 0; i < sizeof(float); i++) {
        floatBytes[i] = byteArray[offset + i];
    }
    offset += sizeof(float);
    uint8_t *floatBytesWeight = (uint8_t *) &person.weight;
    for (int i = 0; i < sizeof(float); i++) {
        floatBytesWeight[i] = byteArray[offset + i];
    }
    return person;
}

int main() {
    struct Person john = {25, 180.5, 75.0};

    uint8_t byteArray[sizeof(struct Person)];
    fillByteArray(byteArray, john);

    struct Person retrievedPerson = getPersonFromByteArray(byteArray);

    printf("Retrieved Person:\n");
    printf("Age: %d\n", retrievedPerson.age);
    printf("Height: %.2f\n", retrievedPerson.height);
    printf("Weight: %.2f\n", retrievedPerson.weight);

    return 0;
}
