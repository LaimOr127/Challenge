#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100; // максимальный размер стека

class Stack {
private:
    char data[MAX_SIZE]; // массив для хранения элементов стека
    int top_index; // индекс верхнего элемента стека

public:
    Stack() { // конструктор по умолчанию
        top_index = -1;
    }

    void push(char value) { // добавление элемента в стек
        if (top_index == MAX_SIZE - 1) { // проверка на переполнение
            cout << "Error: stack overflow" << endl;
            return;
        }
        top_index++;
        data[top_index] = value;
    }

    char pop() { // удаление элемента из стека
        if (top_index == -1) { // проверка на пустоту
            cout << "Error: stack is empty" << endl;
            return '\0';
        }
        char value = data[top_index];
        top_index--;
        return value;
    }

    char top() { // получение верхнего элемента стека
        if (top_index == -1) { // проверка на пустоту
            cout << "Error: stack is empty" << endl;
            return '\0';
        }
        return data[top_index];
    }

    bool empty() { // проверка, пуст ли стек
        return top_index == -1;
    }
};

int priority(char op) { // определение приоритета оператора
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

bool is_digit(char c) { // проверка, является ли символ цифрой
    return c >= '0' && c <= '9';
}

bool is_operator(char c) { // проверка, является ли символ оператором
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infix_to_prefix(string infix) { // преобразование инфиксной записи в префиксную
    Stack operators, result; // стек для операторов и результирующий стек
    int n = infix.length();
    for (int i = n - 1; i >= 0; i--) { // сканируем выражение справа налево
        char c = infix[i];
        if (is_digit(c)) { // если символ - число, добавляем его в результирующий стек
            result.push(c);
        }
        else if (is_operator(c)) { // если символ - оператор
            while (!operators.empty() && priority(operators.top()) >= priority(c)) {
                // выталкиваем все операторы с большим или равным приоритетом в результирующий стек
                result.push(operators.pop());
            }
            operators.push(c); // добавляем текущий оператор в стек операторов
        }
        else if (c == ')') { // если символ - закрывающая скобка
            operators.push(c); // добавляем ее в стек операторов
        }
        else if (c == '(') { // если символ - открывающая скобка
            while (operators.top() != ')') {
                // выталкиваем операторы до ближайшей закрывающей скобки в результирующий стек
                result.push(operators.pop());
            }
            operators.pop(); // удаляем закрывающую скобку из стека операторов
        }
    }
    while (!operators.empty()) {
        // выталкиваем все оставшиеся операторы в результирующий стек
        result.push(operators.pop());
    }
    string prefix;
    while (!result.empty()) {
        // переворачиваем результирующий стек и собираем его элементы в строку
        prefix += result.pop();
    }
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string prefix = infix_to_prefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
