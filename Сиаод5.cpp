////Задание 1
//#include <iostream>
//#include <ctime>
//#include <chrono>
//
//using namespace std;
//
//struct Element
//{
//    int value;
//};
//
//void selectionSort(int n, Element* arr)
//{
//    auto begin = chrono::steady_clock::now();
//    int max, temp, index, comparisons = 0, swaps = 0;
//    for (int i = 0; i < n; i++)
//    {
//        comparisons++;
//        max = arr[i].value;
//        for (int j = i; j < n; j++)
//        {
//            comparisons++;
//            if (arr[j].value <= max)
//            {
//                swaps++;
//                max = arr[j].value;
//                index = j;
//            }
//        }
//        temp = arr[i].value;
//        arr[i].value = arr[index].value;
//        arr[index].value = temp;
//    }
//    auto end = chrono::steady_clock::now();
//    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
//    cout << "Затраченное время: " << elapsed_ms.count() << " мс" << endl;
//    cout << "Количество сравнений: " << comparisons << ", количество обменов: " << swaps << endl;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    srand(time(0));
//    int n;
//    while (true)
//    {
//        cout << endl;
//        cout << "Введите количество элементов массива: ";
//        cin >> n;
//        Element* arr = new Element[n + 1];
//        for (int i = 0; i < n; i++)
//        {
//            arr[i].value = rand();
//        }
//        /*for (int i = 0; i < n; i++)
//        {
//            cout<<arr[i].value<<endl;
//        }*/
//        selectionSort(n, arr);
//        /*for (int i = 0; i < n; i++)
//        {
//            cout << arr[i].value << endl;
//        }*/
//    }
//}


//Задание 2
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

struct Element
{
    int value;
};

void sortAscending(int n, Element* arr)
{
    auto begin = chrono::steady_clock::now();
    int maxVal, temp, index, compares = 0, swaps = 0;
    for (int i = 0; i < n; i++)
    {
        compares++;
        maxVal = arr[i].value;
        index = i;
        for (int j = i; j < n; j++)
        {
            compares++;
            if (arr[j].value <= maxVal)
            {
                maxVal = arr[j].value;
                index = j;
            }
        }
        if (index != i)
        {
            temp = arr[i].value;
            arr[i].value = arr[index].value;
            arr[index].value = temp;
            swaps++;
        }
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Затраченное время: " << elapsed_ms.count() << " мс" << endl;
    cout << "Количество сравнений: " << compares << ", Количество перестановок: " << swaps << endl;
}

void sortDescending(int n, Element* arr)
{
    auto begin = chrono::steady_clock::now();
    int maxVal, temp, index, compares = 0, swaps = 0;
    for (int i = 0; i < n; i++)
    {
        compares++;
        maxVal = arr[i].value;
        index = i;
        for (int j = i; j < n; j++)
        {
            compares++;
            if (arr[j].value >= maxVal)
            {
                maxVal = arr[j].value;
                index = j;
            }
        }
        if (index != i)
        {
            temp = arr[i].value;
            arr[i].value = arr[index].value;
            arr[index].value = temp;
            swaps++;
        }
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Затраченное время: " << elapsed_ms.count() << " мс" << endl;
    cout << "Количество сравнений: " << compares << ", Количество перестановок: " << swaps << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    while (true)
    {
        cout << "Введите количество элементов массива: ";
        cin >> n;
        Element* arr = new Element[n + 1];
        for (int i = 0; i < n; i++)
        {
            arr[i].value = rand();
        }
        sortAscending(n, arr);
        sortAscending(n, arr);
        sortDescending(n, arr);
        sortAscending(n, arr);
    }
}




//Задача 3
//#include <iostream>
//#include <ctime>
//#include <chrono>
//using namespace std;
//
//struct massive
//{
//    int value;
//};
//
//void sort(int n, massive* M)
//{
//    long long comparisons = 0;
//    long long swaps = 0;
//    auto begin = chrono::steady_clock::now();
//    for (int i = 0; i < n - 1; i++)
//    {
//        comparisons++;
//        for (int j = 0; j < n - i - 1; j++)
//        {
//            comparisons++;
//            if (M[j].value > M[j + 1].value)
//            {
//                swaps++;
//                swap(M[j].value, M[j + 1].value);
//            }
//        }
//    }
//    auto end = chrono::steady_clock::now();
//    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
//    cout << "Затраченное время: " << elapsed_ms.count() << endl;
//    cout << "Количество сравнений: " << comparisons << ", Количество обменов: " << swaps << endl;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    srand(time(0));
//    int n;
//    while (true)
//    {
//        cout << endl;
//        cout << "Введите количество элементов массива: ";
//        cin >> n;
//        massive* M = new massive[n + 1];
//        for (int i = 0; i < n; i++)
//        {
//            M[i].value = rand();
//        }
//        sort(n, M);
//    }
//}
