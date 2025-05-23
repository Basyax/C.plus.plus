#include <iostream>     
// Підключення стандартної бібліотеки вводу/виводу.
// Вона містить визначення для об'єктів cout, cin, cerr тощо,
// які дозволяють виводити інформацію на екран і зчитувати з клавіатури.

#include <cmath>        
// Підключення стандартної математичної бібліотеки.
// Тут містяться різні математичні функції, наприклад, sqrt() для обчислення квадратного кореня.

using namespace std;     
// Оголошення використання простору імен std, щоб не писати
// std::cout, std::endl, а можна просто cout, endl.
// Це спрощує запис коду, але в великих проєктах може призвести до конфліктів імен.


// Оголошення функції isPrime, яка приймає ціле число num і повертає булеве значення:
// true - якщо число є простим, false - якщо ні.
bool isPrime(int num) {
    if (num <= 1) {                
        // Якщо число num менше або рівне 1 (0, 1, і від'ємні числа),
        // то за визначенням вони не є простими.
        return false;              
        // Повертаємо false, що означає — число не просте.
    }

    int limit = static_cast<int>(sqrt(num));  
    // Обчислюємо верхню межу для перевірки дільників.
    // Якщо число не має дільників до свого квадратного кореня,
    // то воно є простим.
    // Використовуємо static_cast<int> щоб явно привести результат
    // sqrt(num) (який є типом double) до цілого числа.
    // Це дозволяє у циклі ітеруватися по цілих числах.

    // Цикл від 2 до limit включно перевіряє, чи є дільник числа num.
    for (int i = 2; i <= limit; i++) {       
        if (num % i == 0) {                   
            // Якщо num ділиться на i без остачі (залишок від ділення 0),
            // це означає, що у num є дільник, крім 1 і самого себе.
            return false;                     
            // Повертаємо false — число не просте.
        }
    }

    return true;                             
    // Якщо цикл завершився і не було знайдено жодного дільника,
    // то число є простим, повертаємо true.
}


int main() {
    cout << "Прості числа від 0 до 21: ";  
    // Виводимо на екран повідомлення, яке пояснює,
    // які числа будуть виведені далі — прості числа від 0 до 21.

    // Цикл перебирає всі цілі числа від 0 до 21 включно.
    for (int i = 0; i <= 21; i++) {
        // Для кожного числа i викликаємо функцію isPrime,
        // щоб перевірити, чи є це число простим.
        if (isPrime(i)) {                    
            // Якщо функція повернула true (число просте),
            // то виконуємо наступний рядок.
            cout << i << " ";                
            // Виводимо це число i на екран, після нього — пробіл.
            // Таким чином усі прості числа будуть виведені в одному рядку через пробіл.
        }
    }

    cout << endl;                           
    // Після завершення циклу виводимо символ кінця рядка,
    // щоб перейти на новий рядок в консолі.
    // Це робить вивід акуратнішим.

    return 0;                              
    // Завершуємо функцію main, повертаючи 0.
    // Повернення 0 з main означає, що програма виконалась успішно
}
