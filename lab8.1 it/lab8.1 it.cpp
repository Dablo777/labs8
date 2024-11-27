#include <iostream>
#include <cstring>

using namespace std;

bool Find(const char* str)
{
    size_t i = 0;
    size_t len = strlen(str);
    while (i < len - 1)
    {
        if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
        {
            return true;
        }
        i++;
    }
    return false;
}

char* Change(const char* str)
{
    size_t len = strlen(str);
    size_t newSize = len * 4 / 3 + 1; // Розрахунок розміру нового рядка
    char* tmp = new char[newSize];
    tmp[0] = '\0'; // Ініціалізуємо порожній рядок
    size_t i = 0;
    char* t = tmp;

    while (i < len - 1)
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            strcat_s(tmp, newSize, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0'; // Завжди завершувати рядок нуль-символом
        }
    }

    // Копіюємо останні символи, якщо вони залишилися
    while (i < len)
    {
        *t++ = str[i++];
        *t = '\0';
    }

    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains 'no' or 'on': " << boolalpha << Find(str) << endl;

    char* dest = Change(str); // Отримуємо новий змінений рядок
    cout << "Original: " << str << endl;
    cout << "Modified: " << dest << endl;

    delete[] dest; // Очищуємо пам'ять після використання
    return 0;
}
