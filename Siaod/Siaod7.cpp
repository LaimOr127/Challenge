// Siaod6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


//линейный поиск(метод грубой силы) :
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

    using namespace std;

struct table {
    string name;
    int code;
};
long long int c1 = 0, c2 = 0;

int linearSearch(int n, table* M, int key) {

    c1++;
    for (int i = 0; i < n; i++) {
        c1++;
        if (M[i].code == key) {
            return key;
        }
        c1++;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, key;
    while (true) {
        cout << "Размер таблицы = ";
        cin >> n;
        cout << "Ключ = ";
        cin >> key;
        table* M = new table[n + 1];
        for (int i = 0; i < n; i++) {
            M[i].name = "товар" + to_string(i + 1);
            M[i].code = 100000 + i;
        }
        auto begin = chrono::steady_clock::now();
        key = linearSearch(n, M, key);
        auto end = chrono::steady_clock::now();
        auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cout << "Затраченное время: " << elapsed_ms.count() << endl;
        cout << "Сф: " << c1 << ", Мф: " << c2 << endl;
        if (key == 0)
        {
            cout << "не найден" << endl;
        }
        else
        {
            cout << "найден" << endl;
        }
    }
    return 0;
}

//поиск с барьером :
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

struct table {
    string name;
    int code;
};
long long int c1 = 0, c2 = 0;

int barrierSearch(int n, table* M, int key) {
    M[n].code = key;
    int i = 0;
    while (true) {
        c1++;
        if (M[i].code == key) {
            return key;
        }
        i++;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, key;
    while (true) {
        cout << "Размер таблицы = ";
        cin >> n;
        cout << "Ключ = ";
        cin >> key;
        table* M = new table[n + 1];
        for (int i = 0; i < n; i++) {
            M[i].name = "товар" + to_string(i + 1);
            M[i].code = 100000 + i;
        }
        auto begin = chrono::steady_clock::now();
        key = barrierSearch(n, M, key);
        auto end = chrono::steady_clock::now();
        auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cout << "Затраченное время: " << elapsed_ms.count() << endl;
        cout << "Сф: " << c1 << ", Мф: " << c2 << endl;
        if (key == 0)
        {
            cout << "не найден" << endl;
        }
        else
        {
            cout << "найден" << endl;
        }
    }
    return 0;
}


//Бинарный однородный без использования дополнительной таблицы :
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

struct table {
    string name;
    int code;
};
long long int c1 = 0, c2 = 0;

int binary_search(int n, table* M, int key) {
    int left = 0, right = n - 1;
    c1++;
    while (left <= right) {
        int mid = (left + right) / 2;
        c1++;
        if (M[mid].code == key) {
            return mid;
        }
        else if (M[mid].code < key) {
            left = mid + 1;
            c1++;
        }
        else {
            right = mid - 1;
            c1++;
        }
        c1++;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, key;
    while (true) {
        cout << "Размер таблицы = ";
        cin >> n;
        cout << "Ключ = ";
        cin >> key;
        table* M = new table[n + 1];
        for (int i = 0; i < n; i++) {
            M[i].name = "товар" + to_string(i + 1);
            M[i].code = 100000 + i;
        }
        auto begin = chrono::steady_clock::now();
        key = binary_search(n, M, key);
        auto end = chrono::steady_clock::now();
        auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cout << "Затраченное время: " << elapsed_ms.count() << endl;
        cout << "Сф: " << c1 << ", Мф: " << c2 << endl;
        if (key == 0)
        {
            cout << "не найден" << endl;
        }
        else
        {
            cout << "найден" << endl;
        }
    }
    return 0;
}