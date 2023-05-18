//Дз 1

//1.1
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double a, b, c;
    cout << "Введите a b c:\n";
    cin >> a >> b >> c;
    if (a != 0) {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Нет решений";
            return 0;
        }

        cout << (-b + sqrt(D)) / (2 * a) << endl;

        if (D > 0)
            cout << (-b - sqrt(D)) / (2 * a) << endl;
    }
    else {
        if (b == 0)

            if (c == 0) {
                cout << "Любое число\n";
            }
            else {
                cout << "Решений нет\n";
            }

        else {
            cout << (-c / b);
        }
    }
}


//1.2
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Введите два числа:\n";
    double a, b;
    cin >> a >> b;
    cout << a << "+" << b << "=" << a + b << '\n'
        << a << "-" << b << "=" << a - b << '\n'
        << a << "*" << b << "=" << a * b << '\n';
    if (b != 0)
        cout << a / b << '\n';
    else
        cout << "На ноль делить нельзя\n";
}

//1.3
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double b, c;
    std::cout << "Введите два числа:";
    std::cin >> b >> c;
    if (b == 0 && c == 0)
        std::cout << "Любое число\n";

    if (b != 0)
        std::cout << (-c / b);
    else
        std::cout << "Решений нет";
}

//1.4
#include <iostream>
#include <string_view>
#include <string>
//#include <cmath>

using namespace std;

bool input_bool(string_view message) {
    string value;

    while (value != "да" && value != "нет") {
        std::cout << message << " [да/нет] ";
        cin >> value;
        for_each(value.begin(), value.end(), [](char& x) {
            x = static_cast<char>(tolower(x));
            });
    }
    return (value == "да");
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    bool lamp_on = input_bool("Лампа включена?");
    bool is_day = input_bool("На улице день?");
    bool window_open = input_bool("Шторы открыты?");

    if (is_day && window_open || lamp_on) {
        cout << "На улице светло\n";
    }
    else {
        cout << "На улице темно\n";
    }
}


//Дз2

//номер 1
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
T input(string_view message) {
	cout << message << ": ";
	T value;
	cin >> value;
	return value;
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");

	auto a = input<double>("Введите а");
	auto x = input<double>("Введите x");

	double w;

	if (abs(x) < 1) {
		w = a * log(abs(x));
	}
	else {
		w = sqrt(a - (x * x));
	}
	if (to_string(w) != "nan") {
		printf("w(%f, %f)=%f", a, x, w);
	}
	else {
		printf("Значение функции не определено");
	}
}

//номер 2
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
T input(string_view message) {
	cout << message << ": ";
	T value;
	cin >> value;
	return value;
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	auto x = input<double>("Введите x");
	auto y = input<double>("Введите y");
	auto b = input<double>("Введите b");

	double z = log(b - y) * sqrt(b - x);

	if (to_string(z) == "nan") {
		printf("Значение функции не определено");
	}
	else {
		printf("%f", z);
	}
}

//номер 3
#include <iostream>
#include <cmath>
#include <functional>
#include "../utils.cpp"

using namespace std;


int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	using placeholders::_1;

	auto input = bind(
		base_input<double>, _1,
		[](double v) { return v > 0; },
		"Число должно быть больше нуля"
	);


	auto r = input("Введите малый радиус: ");
	auto R = input("Введите большой радиус: ");
	auto h = input("Введите высоту: ");

	double l = sqrt(pow(h, 2) + pow(R - r, 2));

	double S = M_PI * (R * R + (R + r) * l + r * r);
	double V = M_PI * (1.0 / 3) * h * (R * R + R * r + r * r);

	printf("S=%f V=%f", S, V);
}

//номер 4
#include <iostream>
#include "../utils.cpp"

using namespace std;

int main() {
	auto input = bind(
		base_input<double>, placeholders::_1,
		[](double v) { return v > 0 && (int)v == v; },
		"Число должно быть больше нуля"
	);
	auto n = input("Введите n:");

	for (int i = n; i < n + 10; ++i)
		cout << i << " ";
}

//номер 5
#include <iostream>
#include <cmath>

using namespace std;


int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");


	for (double x = -4; x <= 4; x += 0.5) {
		double y = (x * x - 2 * x + 2) / (x - 1);
		if (abs(y) != 1.0 / 0)
			printf("y(%f)=%f\n", x, y);
		else
			printf("y(%f) не определен\n", x);
	}
}


//Дз3

//3.1
#include <iostream> 
using namespace std;
#include <cmath> 
int main()
{
	setlocale(0, "");
	double s, p, r, n, m, a;
	cout << "s:";
	cin >> s;
	cout << "p:";
	cin >> p;
	cout << "n:";
	cin >> n;
	r = p / 100.;

	if (12 * (pow(1 + r, n) - 1) == 0)
	{
		cout << "нет решения";
	}
	else
	{

		m = ((s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1)));
		cout << m << endl;
	}
	return 0;
}

//3.2
#include <iostream> 
using namespace std;
#include <fstream>
int main()
{
	setlocale(0, "");
	double s, r, n, m, u, p;
	cout << "s:";
	cin >> s;
	cout << "m:";
	cin >> m;
	cout << "n:";
	cin >> n;
	r = 0;
	do
	{
		r = r + 0.01;
		u = ((s * r * pow(1 + r, 2)) / (12 * (pow(1 + r, 2) - 1)));
		u = round(u * 100) / 100;
	} while (u != m);
	p = r * 100;
	cout << p << endl;
	return 0;
}

//3.3
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	ifstream f("primer.txt");
	string a;
	if (f)
	{
		while (getline(f, a))
		{
			cout << a << endl;
		}
	}
	else
	{
		cout << "файл не найден";
		return 0;
	}
	return 0;
}

//3.4
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	ifstream f("primer.txt");
	int a;
	if (f)
	{
		do
		{
			if (f >> a)
			{
				cout << a << endl;
			}
			else
			{
				f.clear();
				f.ignore(1, ' ');
			}
		} while (!f.eof());
	}
	else
	{
		cout << "файл не найден";
		return 0;
	}
	return 0;
}

//3.5
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string s;
	int i, j;
	char a[30], t;

	cin >> s;
	s.copy(a, 29);
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
		{
			if (a[i] <= a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 1; i < 30; i++)
	{
		cout << a[i] << endl;
	}
	return 0;


//Дз4

//4.1
#include <iostream>
#include <fstream>
    using namespace std;

    int main()
    {
        setlocale(0, "");
        double a, s, q;
        int i;
        s = 0;
        ofstream g("234.txt");
        for (i = 0; i < 10; i++)
        {
            cin >> q;
            g << q << endl;
        }
        g.close();

        ifstream f("234.txt");

        if (f.is_open())
        {
            while (f >> a)
            {
                s = s + a;
            }
            cout << s << endl;
        }
        else
        {
            cout << "Файл не найден";
            cout << "Файл не найден";
            return 0;
        }

        f.close();
        return 0;
    }

    //4.2
#include <iostream> 
    using namespace std;

    void f(int x)
    {
        if (x > 0)
        {
            cout << "sign x = 1";

        }
        if (x == 0)
        {
            cout << "sign x = 0";
        }
        if (x < 0)
        {
            cout << "sign x = -1";
        }
    }
    int main()
    {
        setlocale(0, "");
        int a;
        cin >> a;
        f(a);
        return 0;
    }

    //4.3
#include <iostream>
#include <cmath>
#include <functional>
#include "../utils.cpp"

    using namespace std;


    auto read_side = bind(
        base_input<double>,
        placeholders::_1,
        [](double v) { return v > 0; },
        "Сторона должна быть больше 0");

    void rectangle(double a, double b) {
        cout << "Площадь прямоугольника: " << a * b << endl;
    }

    void triangle(double a, double h) {
        cout << "Площадь треугольника: " << 0.5 * a * h << endl;
    }

    void circle(double R) {
        cout << "Площадь круга: " << M_PI * R * R << endl;
    }

    int main() {
        double a, b, h, R;
        int ask;
        cout << "1.прямоугольник\n2.треугольник\n3.круг\n(1-3): ";
        cin >> ask;

        switch (ask) {
        case 1:
            a = read_side("Введите длину прямоугольника: ");
            b = read_side("Введите высоту: ");
            rectangle(a, b);
            break;
        case 2:
            a = read_side("Введите сторону треугольника: ");
            h = read_side("Введите высоту: ");
            triangle(a, h);
            break;
        case 3:
            R = read_side("Введите радиус окружности: ");
            circle(R);
            break;
        default:
            cout << "Такого варианта нет";
        }


    }

    //4.3
#include <iostream> 
#include <cmath> 
    using namespace std;

    void p(double x1, double x2)
    {
        double m;
        m = x1 * x2;
        cout << m << endl;
    }
    void t(double x1, double x2, double x3)
    {
        double m;
        m = x1 * x2 * sin(x3);
        cout << m << endl;
    }
    void o(double x1)
    {
        double m, pi = 3.14;
        m = x1 * pi;
        cout << m << endl;
    }
    int main()
    {
        setlocale(0, "");
        double a, b, c;
        cout << "сторона прямоуголника:";
        cin >> a;
        cout << "сторона прямоуголника:";
        cin >> b;
        p(a, b);
        cout << "сторона треугольника:";
        cin >> a;
        cout << "сторона треугольника:";
        cin >> b;
        cout << "угол между сторонами треугольника:";
        cin >> c;
        t(a, b, c);
        cout << "радиус:";
        cin >> a;
        o(a);
        return 0;
    }

    //4.4
#include <iostream> 
    using namespace std;

    void a()
    {

        cout << "* ";
    }
    void b()
    {
        cout << "__";
    }
    int main()
    {
        setlocale(0, "");
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                a();
            }
            for (int j = 0; j < 18; j++)
            {
                b();
            }
            cout << "\n";
        }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 27; j++)
            {
                b();
            }
            cout << "\n";
        }
        return 0;
    }

    //4.5
#include <iostream> 
    using namespace std;
#include <cmath> 

    void a()
    {

        cout << "*";
    }
    void b()
    {
        cout << "_";
    }

    int main()
    {
        double t, x = 1, u;
        int i = 0;
        setlocale(0, "");
        for (double y = 1; y > -1.01; y = y - 0.1)
        {

            for (double x = -5; x < 5.01; x = x + 0.1)
            {
                i++;
                if (i == 51)
                {
                    cout << "|";
                }
                t = sin(x);
                t = (round(t * 10)) / 10;
                u = y;
                u = (round(u * 10)) / 10;
                if (t == u)
                {
                    a();
                }
                else
                {
                    b();
                }
            }
            cout << "\n";
            i = 0;
        }
        return 0;
    }

    //4.6
#include <iostream>
#include <string>
    using namespace std;

    int main()
    {
        setlocale(0, "");
        string a;
        int i, o;
        o = 0;
        cin >> a;
        char* q = new char[a.length()];
        a.copy(q, a.length());
        for (i = 0; i < a.length(); i++)
        {
            if ((int)q[i] == 77)
            {
                o = o + 1000;
            }
            if ((int)q[i] == 68)
            {
                o = o + 500;
            }
            if ((int)q[i] == 67)
            {
                if ((int)q[i + 1] == 77 or (int)q[i + 1] == 68)
                {
                    o = o - 100;
                }
                else
                {
                    o = o + 100;
                }
            }
            if ((int)q[i] == 76)
            {
                o = o + 50;
            }
            if ((int)q[i] == 88)
            {
                if ((int)q[i + 1] == 76 or (int)q[i + 1] == 67)
                {
                    o = o - 10;
                }
                else
                {
                    o = o + 10;
                }
            }
            if ((int)q[i] == 86)
            {
                o = o + 5;
            }
            if ((int)q[i] == 73)
            {
                if ((int)q[i + 1] == 88 or (int)q[i + 1] == 86)
                {
                    o = o - 1;
                }
                else
                {
                    o = o + 1;
                }
            }
        }
        cout << o << endl;
        return 0;
    }

    //4.7
#include <iostream>
    using namespace std;
    int f(int s2, int m, int b, int c)
    {
        return((m * s2 + b) % c);
    }
    int main()
    {
        setlocale(0, "");
        int i, n, d, u, s1, o;
        cin >> i;
        n = 37;
        d = 3;
        u = 64;
        s1 = 0;
        for (int j = 0; j < i; j++)
        {
            o = f(s1, n, d, u);
            s1 = o;
        }
        cout << o << endl;
        n = 25173;
        d = 13849;
        u = 65537;
        s1 = 0;
        for (int j = 0; j < i; j++)
        {
            o = f(s1, n, d, u);
            s1 = o;
        }
        cout << o << endl;
        return 0;
    }
    //4.7
#include <iostream>
#include <functional>
#include <tuple>

    using namespace std;


    tuple<function<int()>, function<void()>> get_random() {
        int m = 37;
        int b = 3;
        int c = 64;
        int s0 = 0;
        int* s = new int;
        auto next = [=]() -> int {
            *s = (m * (*s) + b) % c;
            return (*s);
        };

        auto finalize = [=]() {
            delete s;
        };
        return make_tuple(next, finalize);
    }

    int main() {
        auto [rand, finalize] = get_random();
        for (int i = 0; i < 10; ++i) {
            cout << rand() << " ";
        }
        finalize();
    }

    //4.8
#include <iostream>
    using namespace std;
    int main() {
        int i, j, k;
        double s, m, n;
        double A[3][4];
        double B[4][2];
        double C[3][2];
        A[0][0] = 5;
        A[0][1] = 2;
        A[0][2] = 0;
        A[0][3] = 10;
        A[1][0] = 3;
        A[1][1] = 5;
        A[1][2] = 2;
        A[1][3] = 5;
        A[2][0] = 20;
        A[2][1] = 0;
        A[2][2] = 0;
        A[2][3] = 0;
        B[0][0] = 1.2;
        B[0][1] = 0.5;
        B[1][0] = 2.8;
        B[1][1] = 0.4;
        B[2][0] = 5;
        B[2][1] = 1;
        B[3][0] = 2;
        B[3][1] = 1.5;
        cout << "C:\n";
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2; j++) {
                C[i][j] = 0;
                for (k = 0; k < 4; k++)
                    C[i][j] += A[i][k] * B[k][j];
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
        cout << "1)\n";
        s = 0;
        for (i = 0; i < 3; i++)
        {
            if (s < C[i][0])
            {
                s = C[i][0];
            }
        }
        cout << s << endl;
        cout << "2)\n";
        s = 0;
        for (i = 0; i < 3; i++)
        {
            if (s < C[i][1])
            {
                s = C[i][1];
            }
        }
        cout << s << endl;;
        cout << "3)\n";
        m = 0;
        for (i = 0; i < 3; i++)
        {
            m += C[i][0];
        }
        cout << m << endl;
        cout << "4)\n";
        n = 0;
        for (i = 0; i < 3; i++)
        {
            n += C[i][1];
        }
        cout << n << endl;
        cout << "5)\n";
        s = m + n;
        cout << s << endl;;
        return 0;
    }

    //4.9
#include <iostream>
#include <string>
#include <algorithm>
    using namespace std;

    int main()
    {
        setlocale(0, "");
        int b, s, i, l, o, r;
        char t;
        string a;
        cout << "число:";
        cin >> a;
        cout << "система счисления:";
        cin >> b;
        cout << "система счисления:";
        cin >> s;
        char q[1000];
        int w[1000];
        l = a.size() - 1;
        r = 0;
        a.copy(q, a.length() + 1);
        for (i = 0; i < a.length(); i++)
        {
            if ((int)q[i] < 60)
            {
                if (q[i] - 48 >= b)
                {
                    cout << "ошибка";
                    return 0;
                }
                r = r + (q[i] - 48) * pow(b, l);
                l = l - 1;
            }
            else
            {
                if (q[i] - 55 >= b)
                {
                    cout << "ошибка";
                    return 0;
                }
                r = r + (q[i] - 55) * pow(b, l);
                l = l - 1;
            }
        }
        i = 0;
        while (r > 1)
        {
            o = r % s;
            w[i] = o;
            i = i + 1;
            r = r / s;
        }
        if (r > 9)
        {
            r = r + 55;
            t = (char)r;
            cout << t;
        }
        if (r > 0 and r < 10)
        {
            cout << r;
        }
        i = i - 1;
        while (i >= 0)
        {
            if (w[i] > 9)
            {
                w[i] = w[i] + 55;
                t = (char)w[i];
                cout << t;
            }
            else
            {
                cout << w[i];
            }
            i = i - 1;
        }
        return 0;
    }


//Дз5

//5.1
#include <iostream>

    using namespace std;

    int digit_sum(int n) {
        if (n == 0) return 0;
        return digit_sum(n / 10) + n % 10;
    }


    int main() {
        setlocale(LC_ALL, "ru_RU.utf8");
        int m;
        cout << "Введите m: ";
        cin >> m;
        if (0 > m || m >= 27) {
            cout << "0 < m < 27";
            return 0;
        }
        cout << "Числа, сумма цифр которых равна " << m << ":\n";
        for (int i = 100; i <= 999; ++i) {
            if (digit_sum(i) == m) cout << i << endl;
        }

    }

//5.2

#include <iostream>


    using namespace std;

    int euclid(int a, int b) {
        if (a == b)
            return a;

        return (a > b) ? euclid(a - b, b) : euclid(a, b - a);
    }

    int euclid2(int a, int b) {
        if (a == 0 || b == 0)
            return a + b;

        return (a > b) ? euclid2(a % b, b) : euclid2(a, b % a);
    }

    int main() {
        int a, b;
        cout << "Введите два числа: ";
        cin >> a >> b;
        if (a == 0 || b == 0) {
            cout << "Нельзя искать НОД с 0\n";
            return 0;
        }

        cout << "НОД вычитанием: " << euclid(a, b) << '\n';
        cout << "НОД делением: " << euclid2(a, b) << '\n';

    }

//5.3

#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <fstream>
#include "../utils.cpp"

    using namespace std;

    auto read_pos = bind(
        base_input<int>,
        placeholders::_1,
        [](int v) { return v > 0; },
        "Число должно быть положительным");

    auto read_not_empty = bind(
        base_input<string>,
        placeholders::_1,
        [](string_view str) { return !str.empty(); },
        ""
    );

    struct Toy {
        string name;
        int price;
        int age_from;
        int age_to;

        Toy() : price(0), age_from(0), age_to(0) {
        }
    };

    ofstream& operator<<(ofstream& out, const Toy& toy) {
        out << toy.name << " " << toy.price << " "
            << toy.age_from << " " << toy.age_to << endl;
        return out;
    }

    ostream& operator<<(ostream& out, const Toy& toy) {
        out << toy.name << " " << toy.price << " руб.";
        return out;
    }

    int main() {
        ofstream file;
        file.open("./outputs/toys.txt");

        if (!file.is_open()) {
            cout << "Не возможно создать файл\n";
            return 0;
        }

        auto toys_count = read_pos("Введите количество игрушек: ");
        vector<Toy> toys(toys_count);

        for (auto& toy : toys) {
            toy.name = read_not_empty("Введите название игрушки: ");
            toy.price = read_pos("Введите цену игрушки: ");
            toy.age_from = read_pos("Игрушка подходит детям от: ");
            toy.age_to = read_pos("Игрушка подходит детям до: ");

            file << toy.name << " " << toy.price << " "
                << toy.age_from << " " << toy.age_to << endl;
        }


        vector<Toy> filter1;

        copy_if(toys.begin(), toys.end(), back_inserter(filter1),
            [](Toy& t) {
                return t.price <= 400 && t.age_from <= 8 && 8 <= t.age_to;
            });


        if (!filter1.empty()) {
            cout << "Детям 8 лет подходят игрушки: \n";
            copy(toys.begin(), toys.end(),
                ostream_iterator<Toy>(cout, "\n"));
        }
        else {
            cout << "Игрушек не дороже 400 рублей для детей 8 лет нет.\n";
        }

        vector<Toy> filter2;


        copy_if(toys.begin(), toys.end(), back_inserter(filter2),
            [](Toy& t) {
                return (t.age_from <= 4 && 4 <= t.age_to) &&
                    (t.age_from <= 10 && 10 <= t.age_to);
            });

        if (!filter2.empty()) {
            cout << "Детям 4 и 10 лет подходят игрушки: \n";
            copy(filter2.begin(), filter2.end(),
                ostream_iterator<Toy>(cout, "\n"));
        }
        else {
            cout << "Игрушек для детей 4 и 10 лет нет.\n";
        }


        auto max_price_toy = *max_element(
            toys.begin(), toys.end(),
            [](auto t1, auto t2) {
                return t1.price < t2.price;
            });

        cout << "Самая дорогая игрушка " << max_price_toy.name
            << " стоит " << max_price_toy.price << " руб.";
    }

//5.4

#include <iostream>
#include <algorithm>
#include <fstream>

    using namespace std;

    int main() {
        setlocale(LC_ALL, "ru_RU.utf8");
        ifstream file("./inputs/map_ascii.txt");

        if (!file.is_open()) {
            cout << "Невозможно открыть файл";
            return 0;
        }

        string data;
        getline(file, data, '\0');

        copy(data.begin(), data.end(),
            ostream_iterator<int>(cout, " "));
    }

//5.5

#include <iostream>
#include <fstream>

    using namespace std;


    int main() {
        setlocale(LC_ALL, "ru_RU.utf8");
        ifstream file("./inputs/replace.txt");

        if (!file.is_open()) {
            cout << "Невозможно открыть файл";
            return 0;
        }

        string data;
        char x;
        cout << "Введите символ, на который нужно заменить пробелы: ";
        cin >> x;

        getline(file, data, '\0');
        for (char& c : data) {
            if (isspace(c)) {
                c = x;
            }
        }

        file.close();
        ofstream fw("inputs/replace.txt");
        fw << data;
        fw.flush();
        fw.close();
    }

//5.6

#include <iostream>
#include <iomanip>
#include <cmath>

    using namespace std;


    int main() {

        int n;
        cout << "Введите n: ";
        cin >> n;

        if (n <= 1) {
            cout << "N должно быть больше 1\n";
        }

        double y = 0;
        for (int i = 1; i <= n; ++i) {
            double denom = 0;
            for (int j = 1; j <= i; ++j) {
                denom = denom + sin(j);
            }
            y = y + i / denom;
        }

        cout << "y(" << n << ") = " << setprecision(9) << y;
    }

//5.7

#include <iostream>
#include <iomanip>
#include <cmath>

    using namespace std;


    int main() {

        int n;
        cout << "Введите n: ";
        cin >> n;

        if (n <= 1) {
            cout << "N должно быть больше 1\n";
        }

        double y = 0;
        for (int i = 1; i <= n; ++i) {
            double denom = 0;
            for (int j = 1; j <= i; ++j) {
                denom = denom + sin(j);
            }
            y = y + i / denom;
        }

        cout << "y(" << n << ") = " << setprecision(9) << y;
    }

//5.8

#include <iostream>
#include <vector>

    using namespace std;

    vector<int> sieve(int n) {
        vector<bool> ok(n + 1, true);
        for (int i = 2; i <= n; ++i) {
            int j = 2;
            while ((j != n) && (j * i <= n)) {
                ok[j * i] = false;
                ++j;
            }
        }
        vector<int> result;
        for (int i = 2; i < ok.size(); ++i) {
            if (ok[i]) result.push_back(i);
        }
        return result;
    }

    int main() {
        int n;
        cout << "Введите число: ";
        cin >> n;
        if (n < 0) {
            cout << "Число должно быть положительным\n";
            return 0;
        }
        cout << "Простые числа от 2 до " << n << ":\n";

        for (auto e : sieve(n)) {
            cout << e << " ";
        }
    }

//5.9

#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

    using namespace std;

    void plot_function(vector<vector<char>>& plot, function<double(double)> f,
        double res_x, double res_y) {

        int v_len = plot.size();
        int h_len = plot[0].size();
        int v_center = v_len / 2;
        int h_center = h_len / 2;

        double x_left_edge = -(h_center - 1) * res_x;
        double x_right_edge = -x_left_edge;

        double y_top_edge = -(v_center - 1) * res_y;
        double y_bottom_edge = -y_top_edge;

        //    cout << x_left_edge << " " << x_right_edge << '\n';
        //    cout << y_top_edge << " " << y_bottom_edge;

        double x = x_left_edge;
        for (int i = 0; i < h_len; ++i, x += res_x) {
            double y = f(x);
            if (y_top_edge <= y && y <= y_bottom_edge) {
                //            cout << y;
                //            cout.flush();
                int approx_y = static_cast<int>(round(y / res_y));
                int point = v_center - approx_y;
                plot[point][i] = '*';
            }
        }
    }

    void plot_axis(vector<vector<char>>& plot) {
        int v_len = plot.size();
        int h_len = plot[0].size();
        int v_center = v_len / 2;
        int h_center = h_len / 2;

        for (int i = 0; i < v_len; ++i) {
            if (plot[i][h_center] != '*')
                plot[i][h_center] = '|';
            else
                plot[i][h_center] = 'o';
        }

        for (int i = 0; i < h_len; ++i) {
            if (plot[v_center][i] != '*')
                plot[v_center][i] = '-';
            else
                plot[v_center][i] = 'o';
        }
    }

    void plot_axis_labels(vector<vector<char>>& plot) {
        int v_len = plot.size();
        int h_len = plot[0].size();
        int v_center = v_len / 2;
        int h_center = h_len / 2;

        plot[0][h_center] = '^';
        plot[0][h_center + 1] = 'y';

        plot[v_center][h_len - 2] = '>';
        plot[v_center][h_len - 1] = 'x';

        plot[v_center + 1][h_center - 1] = '0';
    }

    void print_plot(vector<vector<char>>& plot) {
        cout << endl;
        for (auto row : plot) {
            for (char item : row) {
                cout << item;
            }
            cout << endl;
        }
    }
    int main() {
        vector<vector<char>> plt(20, vector<char>(120, ' '));
        double res_x = 15.0 / plt[0].size();
        double res_y = 3.0 / plt.size();
        plot_function(
            plt, [](double x) {return sin(x); }, res_x, res_y);
        plot_axis(plt);
        plot_axis_labels(plt);
        print_plot(plt);
    }