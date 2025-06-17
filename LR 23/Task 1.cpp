#include <iostream> // Підключаємо бібліотеку для вводу/виводу
#include <string>   // Підключаємо бібліотеку для роботи з рядками
using namespace std; // Використовуємо простір імен std для зручності

// Клас для представлення дробів
class Fraction {
public:
    Fraction(int numerator, int denominator); // Конструктор з параметрами
    string toString(); // Метод для текстового представлення дробу
    double toDouble(); // Метод для отримання десяткового значення дробу
    Fraction plus(Fraction that);  // Метод додавання дробів
    Fraction minus(Fraction that); // Метод віднімання дробів
    Fraction times(Fraction that); // Метод множення дробів
    Fraction by(Fraction that);    // Метод ділення дробів

private:
    int numerator;   // Чисельник дробу
    int denominator; // Знаменник дробу
    void reduce();   // Метод для скорочення дробу
};

// Реалізація конструктора
Fraction::Fraction(int num, int den) {
    // Якщо знаменник від'ємний, змінюємо знак дробу
    if (den < 0) {
        num = -num;
        den = -den;
    }
    numerator = num;     // Зберігаємо чисельник
    denominator = den;   // Зберігаємо знаменник
    reduce();            // Скорочуємо дріб
}

// Метод для виводу дробу у вигляді рядка
string Fraction::toString() {
    int whole = numerator / denominator;          // Ціла частина
    int remainder = abs(numerator % denominator); // Остача
    if (remainder == 0) {
        return to_string(whole); // Якщо остача нуль — це ціле число
    }
    string frac = to_string(remainder) + "/" + to_string(denominator); // Дробова частина
    if (whole != 0) {
        return to_string(whole) + " " + frac; // Ціла + дробова частина
    }
    if (numerator < 0) {
        return "-" + frac; // Тільки знак мінус, якщо дріб < 0
    }
    return frac; // Просто дріб
}

// Метод для повернення десяткового значення дробу
double Fraction::toDouble() {
    return (double)numerator / denominator;
}

// Метод для додавання двох дробів
Fraction Fraction::plus(Fraction that) {
    int num = numerator * that.denominator + that.numerator * denominator; // Знаходимо спільний чисельник
    int den = denominator * that.denominator; // Спільний знаменник
    return Fraction(num, den); // Повертаємо новий об'єкт
}

// Метод для віднімання дробів
Fraction Fraction::minus(Fraction that) {
    int num = numerator * that.denominator - that.numerator * denominator;
    int den = denominator * that.denominator;
    return Fraction(num, den);
}

// Метод для множення дробів
Fraction Fraction::times(Fraction that) {
    int num = numerator * that.numerator;       // Множимо чисельники
    int den = denominator * that.denominator;   // Множимо знаменники
    return Fraction(num, den);                  // Повертаємо новий об'єкт
}

// Метод для ділення дробів
Fraction Fraction::by(Fraction that) {
    int num = numerator * that.denominator;     // Множимо на обернений дріб
    int den = denominator * that.numerator;
    return Fraction(num, den);
}

// Допоміжна функція для обчислення найбільшого спільного дільника (НСД)
int gcd(int a, int b) {
    if (b == 0)
        return abs(a); // Базовий випадок: НСД знайдено
    return gcd(b, a % b); // Рекурсія
}

// Метод для скорочення дробу
void Fraction::reduce() {
    int g = gcd(numerator, denominator); // Знаходимо НСД
    numerator /= g; // Скорочуємо чисельник
    denominator /= g; // Скорочуємо знаменник
}

int main() {
    int num1, den1, num2, den2; // Змінні для збереження чисельників і знаменників

    cin >> num1; char slash1; cin >> slash1 >> den1; // Зчитуємо перший дріб
    cin >> num2; char slash2; cin >> slash2 >> den2; // Зчитуємо другий дріб

    Fraction f1(num1, den1); // Створюємо об'єкт першого дробу
    Fraction f2(num2, den2); // Створюємо об'єкт другого дробу

    // Друкуємо всі чотири арифметичні операції з дробами
    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0; // Завершення програми
}
