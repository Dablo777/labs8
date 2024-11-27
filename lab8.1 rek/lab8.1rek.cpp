#include <iostream>
#include <cstring>

using namespace std;

// ���������� ������� ��� ������ "no" ��� "on"
bool FindRecursive(const char* str, size_t index = 0)
{
    size_t len = strlen(str);

    // ������� �������: ������� ���� �����
    if (index >= len - 1)
        return false;

    // ����������, �� �������� "no" ��� "on"
    if ((str[index] == 'n' && str[index + 1] == 'o') ||
        (str[index] == 'o' && str[index + 1] == 'n'))
        return true;

    // ����������� ������ ��� ���������� �������
    return FindRecursive(str, index + 1);
}

// ���������� ������� ��� ����� "no" �� "***"
void ChangeRecursive(const char* str, char* result, size_t index = 0, size_t resultIndex = 0)
{
    size_t len = strlen(str);

    // ������� �������: ������� ���� �����
    if (index >= len)
    {
        result[resultIndex] = '\0'; // ��������� ���������
        return;
    }

    // ���� �������� "no", ������ "***"
    if (str[index] == 'n' && str[index + 1] == 'o')
    {
        result[resultIndex] = '*';
        result[resultIndex + 1] = '*';
        result[resultIndex + 2] = '*';

        // ���������� ���������� ���, ����������� "no"
        ChangeRecursive(str, result, index + 2, resultIndex + 3);
    }
    else
    {
        // ������� ������, ���� "no" �� ��������
        result[resultIndex] = str[index];

        // ����������� ������ ��� ���������� �������
        ChangeRecursive(str, result, index + 1, resultIndex + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // ����������� ����� "no" ��� "on"
    cout << "String contains 'no' or 'on': " << boolalpha << FindRecursive(str) << endl;

    // ���� ����� � ������������� ������
    size_t newSize = strlen(str) * 4 / 3 + 1; // ���������� ������ ������ �����
    char* dest = new char[newSize];
    ChangeRecursive(str, dest);

    cout << "Original: " << str << endl;
    cout << "Modified: " << dest << endl;

    delete[] dest; // ������� ���'��� ���� ������������
    return 0;
}
