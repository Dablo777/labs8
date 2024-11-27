#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція для пошуку "no" або "on"
bool FindRecursive(const char* str, size_t index = 0)
{
    size_t len = strlen(str);

    // Базовий випадок: досягли кінця рядка
    if (index >= len - 1)
        return false;

    // Перевіряємо, чи знайдено "no" або "on"
    if ((str[index] == 'n' && str[index + 1] == 'o') ||
        (str[index] == 'o' && str[index + 1] == 'n'))
        return true;

    // Рекурсивний виклик для наступного індексу
    return FindRecursive(str, index + 1);
}

// Рекурсивна функція для заміни "no" на "***"
void ChangeRecursive(const char* str, char* result, size_t index = 0, size_t resultIndex = 0)
{
    size_t len = strlen(str);

    // Базовий випадок: досягли кінця рядка
    if (index >= len)
    {
        result[resultIndex] = '\0'; // Завершуємо результат
        return;
    }

    // Якщо знайдено "no", додаємо "***"
    if (str[index] == 'n' && str[index + 1] == 'o')
    {
        result[resultIndex] = '*';
        result[resultIndex + 1] = '*';
        result[resultIndex + 2] = '*';

        // Рекурсивно переходимо далі, пропускаючи "no"
        ChangeRecursive(str, result, index + 2, resultIndex + 3);
    }
    else
    {
        // Копіюємо символ, якщо "no" не знайдено
        result[resultIndex] = str[index];

        // Рекурсивний виклик для наступного символу
        ChangeRecursive(str, result, index + 1, resultIndex + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Рекурсивний пошук "no" або "on"
    cout << "String contains 'no' or 'on': " << boolalpha << FindRecursive(str) << endl;

    // Зміна рядка з використанням рекурсії
    size_t newSize = strlen(str) * 4 / 3 + 1; // Розрахунок розміру нового рядка
    char* dest = new char[newSize];
    ChangeRecursive(str, dest);

    cout << "Original: " << str << endl;
    cout << "Modified: " << dest << endl;

    delete[] dest; // Очищуємо пам'ять після використання
    return 0;
}
