#include <iostream>

struct Date {
    int hours;
    int minutes;

    Date(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void normalize() {
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        if (hours < 0) {
            hours += 24;
        }
    }
};

int main() {
    Date startTime, endTime;

    // Введення початкового часу
    std::cout << "Введіть початковий час (формат: ГГ ХХ): ";
    std::cin >> startTime.hours >> startTime.minutes;

    // Перевірка коректності введення
    if (startTime.hours < 0 || startTime.hours >= 24 || startTime.minutes < 0 || startTime.minutes >= 60) {
        std::cerr << "Помилка: некоректний початковий час!" << std::endl;
        return 1;
    }

    // Введення кінцевого часу
    std::cout << "Введіть кінцевий час (формат: ГГ ХХ): ";
    std::cin >> endTime.hours >> endTime.minutes;

    // Перевірка коректності введення
    if (endTime.hours < 0 || endTime.hours >= 24 || endTime.minutes < 0 || endTime.minutes >= 60) {
        std::cerr << "Помилка: некоректний кінцевий час!" << std::endl;
        return 1;
    }

    // Обчислення різниці в хвилинах
    int startTotalMinutes = startTime.hours * 60 + startTime.minutes;
    int endTotalMinutes = endTime.hours * 60 + endTime.minutes;
    //Обчислюємо загальну кількість хвилин для початкового та кінцевого часу.
    int difference = endTotalMinutes - startTotalMinutes;
  //Визначаємо різницю між кінцевим і початковим часом у хвилинах.
    // Якщо різниця від'ємна, це означає, що кінцевий час на наступний день
    if (difference < 0) {
        difference += 24 * 60; // Додаємо 24 години в хвилинах
    }

    // Перетворення назад у години і хвилини
    Date result;
    result.hours = difference / 60;
    result.minutes = difference % 60;
/*
Цей код створює новий об'єкт result типу Date для зберігання різниці часу.

result.hours = difference / 60; — обчислює години, ділячи загальну різницю в хвилинах на 60.
result.minutes = difference % 60; — визначає залишок хвилин, використовуючи оператор залишку, щоб отримати хвилини після виділення повних годин.
Таким чином, ми перетворюємо загальну різницю в хвилинах назад у формат години і хвилини.
*/
    // Вивід результату
    std::cout << "Різниця: " << result.hours << ":" << (result.minutes < 10 ? "0" : "") << result.minutes << std::endl;
//Виводимо результат у форматі ГГ:ХХ, додаючи нуль, якщо хвилини менше 10.
    return 0;
}
