#include <iostream>

using namespace std;

int main() {
    int N;
    int count = 0;  // Змінна для підрахунку цифр, які не дорівнюють 1 і 9

    // Введення натурального числа N
    cout << "Enter a positive integer N: ";
    cin >> N;

    // Цикл, який розкладає число на цифри
    while (N > 0) {
        int digit = N % 10;  // Витягаємо останню цифру

        // Перевіряємо, чи цифра не дорівнює 1 і 9
        if (digit != 1 && digit != 9) {
            count++;
        }

        N /= 10;  // Видаляємо останню цифру з числа
    }

    // Виведення результату
    cout << "Number of digits that are not equal to 1 and 9: " << count << endl;

    return 0;
}
