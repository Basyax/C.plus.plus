// Підключення бібліотек (наборів готових функцій)
#include <iostream>   // Для роботи з вводом/виводом (cin - ввод, cout - вивод)
#include <string>     // Для роботи з текстом (клас string)
#include <map>        // Для створення словника (map - структура "ключ-значення")
#include <sstream>    // Для розбиття рядка на частини (istringstream)

// Вказуємо, що хочемо використовувати стандартні назви без std::
using namespace std;

// Головна функція - початок програми
int main() {
    // Створюємо змінну для зберігання першого введеного рядка
    // string - тип даних для рядків тексту
    // values_line - ім'я змінної (лінія значень)
    string values_line;

    // Читаємо рядок з клавіатури (до натискання Enter)
    // getline - функція читання рядка
    // cin - стандартний ввід (консоль)
    // values_line - куди зберігаємо результат
    getline(cin, values_line);
    
    // Створюємо змінну для шаблону
    string template_line;

    // Читаємо другий рядок - шаблон для заміни
    getline(cin, template_line);
    
    // Створюємо словник для заміни плейсхолдерів
    // map - тип словника
    // <string, string> - ключ і значення обидва рядки
    // replacements - ім'я словника (заміни)
    map<string, string> replacements;

    // Створюємо потік для розбиття рядка на частини
    // istringstream - тип потоку для рядка
    // iss - ім'я потоку
    // (values_line) - передаємо йому наш рядок для обробки
    istringstream iss(values_line);

    // Тимчасова змінна для зберігання кожної пари "ключ=значення"
    string pair;
    
    // Цикл для обробки кожного фрагмента, розділеного комою
    // while - цикл "поки"
    // getline(iss, pair, ',') - читає з потоку до коми
    while (getline(iss, pair, ',')) {
        // Шукаємо позицію знаку рівності в парі
        // size_t - спеціальний тип для позицій у рядку
        // equal_pos - ім'я змінної (позиція знаку "=")
        // pair.find('=') - шукає символ '=' у рядку pair
        size_t equal_pos = pair.find('=');

        // Перевіряємо, чи знайшли знак "="
        // string::npos - спеціальне значення "не знайдено"
        if (equal_pos != string::npos) {
            // Виділяємо ім'я (частина до "=")
            // substr - функція виділення підрядка
            // 0 - початок
            // equal_pos - кількість символів
            string name = pair.substr(0, equal_pos);

            // Виділяємо значення (частина після "=")
            // equal_pos + 1 - починаємо з символу після "="
            // Якщо не вказуємо довжину - беремо до кінця рядка
            string value = pair.substr(equal_pos + 1);

            // Додаємо пару до словника
            // replacements[name] - доступ до елементу за ключем
            // = value - присвоюємо значення
            replacements[name] = value;
        }
    }
    
    // Змінна для відстеження поточної позиції пошуку
    size_t start_pos = 0;

    // Безкінечний цикл для пошуку всіх плейсхолдерів
    while (true) {
        // Шукаємо відкриваючу дужку '['
        size_t open_pos = template_line.find('[', start_pos);

        // Якщо не знайшли - виходимо з циклу
        if (open_pos == string::npos) break;
        
        // Шукаємо закриваючу дужку ']' після знайденої '['
        size_t close_pos = template_line.find(']', open_pos);

        // Якщо не знайшли - виходимо з циклу
        if (close_pos == string::npos) break;
        
        // Виділяємо ім'я плейсхолдера (без дужок)
        string name = template_line.substr(open_pos + 1, close_pos - open_pos - 1);
        
        // Шукаємо це ім'я в словнику
        // auto - автоматичне визначення типу
        // find - метод пошуку в map
        auto it = replacements.find(name);

        // Перевіряємо, чи знайшли
        if (it != replacements.end()) {
            // Замінюємо весь плейсхолдер на значення
            template_line.replace(open_pos, close_pos - open_pos + 1, it->second);

            // Оновлюємо позицію початку пошуку
            start_pos = open_pos + it->second.length();
        } else {
            // Якщо не знайшли - пересуваємось далі
            start_pos = close_pos + 1;
        }
    }
    
    // Виводимо результат
    cout << template_line << endl;

    // Завершуємо програму
    return 0;
}
