//Программа   демонстрирует   работу   оператора   цикла.   Вычисление   суммынатуральных чисел. Вводится целое n. Вычисляется сумма натуральных чисел от 1до n (включительно). Проверить значение n на допустимость.


//mmain.cpp
#include <iostream>
using namespace std;
{
    int main(){int n;
    cin >> n;
    if (n>0)
    {
        int Sum_n = 0;
        for(int i = 1; i <= n; i++)
        {
            Sum_n +=i;
        }
        cout<< "Sum_n = " << Sum_n;
    }
    else
    {
        cout << "n is wrong ("<<n<< ")";
}// prigram herereturn (0);}