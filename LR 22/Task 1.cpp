#include <iostream>     // для вводу/виводу
#include <string>       // для роботи з рядками
#include <sstream>      // для розділення введеного рядка на числа
#include <cmath>        // для std::abs
using namespace std;    // дозволяє не писати std:: перед кожним об'єктом

class Fraction {
public:
    // Конструктор приймає чисельник і знаменник
    Fraction(int numerator, int denominator);

    // Метод повертає рядкове представлення дробу
    string toString();

    // Метод повертає десяткове (double) представлення дробу
    double toDouble();

private:
    int numerator;   // чисельник
    int denominator; // знаменник
};

// Реалізація конструктора
Fraction::Fraction(int num, int den) {
    // Робимо знак дробу тільки в чисельнику
    if (den < 0) {
        num = -num;        // переносимо знак до чисельника
        den = -den;
    }
    numerator = num;
    denominator = den;
}

// Метод для текстового відображення дробу
string Fraction::toString() {
    // Обчислюємо цілу частину та залишок
    int whole = numerator / denominator;                // ціла частина
    int remainder = abs(numerator % denominator);       // остача (завжди додатна)

    if (remainder == 0) {
        // Якщо остача 0, то це ціле число
        return to_string(whole);
    } else if (whole != 0) {
        // Якщо є ціла частина і дробова
        return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
    } else {
        // Якщо цілої частини немає (наприклад -3/4)
        return to_string(numerator) + "/" + to_string(denominator);
    }
}

// Метод для десяткового представлення
double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num, den;                // для чисельника та знаменника
    string input;                // введення у вигляді рядка

    getline(cin, input);        // зчитування всього рядка, напр. "3 / 4"

    // Створюємо stringstream для розбору введення
    stringstream ss(input);
    char slash;                 // символ '/', який ми просто пропустимо

    ss >> num >> slash >> den;  // розділяємо: num, /, den

    // Створюємо об'єкт Fraction
    Fraction fraction(num, den);

    // Виводимо текстове та десяткове представлення дробу
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
