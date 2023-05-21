#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "table_data_line.cpp"
#include "test_data.cpp"

/// @brief Таблица банков
struct Table
{
private:
    static const unsigned int N = 100;
    unsigned int n = 0;

    int getBankIndexById(unsigned int id)
    {
        for (unsigned int i = 0; i < n; i++)
        {
            if (data[i].id == id)
                return i;
        }
        return -1;
    }

    int transformID(std::string str_id)
    {
        std::string valid = "0123456789";
        std::string str_value = "";
        for (int i = 0; i < str_id.length(); i++)
        {
            if (valid.find(str_id[i]) != str_id.npos)
            {
                str_value += str_id[i];

                if (str_value.length() >= 4)
                {
                    break;
                }
            }
        }

        int value = std::stoi(str_value != "" ? str_value : "0");

        for (int i = 0; value < 1000 && i < 4; i++)
        {
            value *= 10;
        }

        if (value < 1000)
        {
            value += 1000;
        }
        return value;
    }

    int getServiceIndexByName(std::string name)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            if (possible_services[i] == name)
                return i;
        }
        return -1;
    }

public:
    Table_Data_Line *data = new Table_Data_Line[N];
    std::string table_name;

    /// @brief Конструктор Table по умолчанию
    Table();

    /// @brief Конструктор Table с заданием имени
    /// @param name : std::string - Имя таблицы
    Table(std::string name);

    /// @brief Деструктор Table
    ~Table();

    /// @brief  Получение максимального количества строк в таблице
    /// @return : unsigned int - Максимальное количество  строк
    unsigned int get_max_size();

    /// @brief  Получение количества строк в таблице
    /// @return : unsigned int - Количество строк
    unsigned int get_size();

    /// @brief Вывод таблицы в консоль
    void print();

    /// @brief Заполнение массива случайными значениями
    /// @param lines_quantity : unsigned int - Количество заполняемых строк
    void fillRandom(const unsigned int lines_quantity);

    /// @brief Добавление в таблицу новой (или изменение существующей) строки
    /// @param id       : unsigned int  - Код банка
    /// @param name     : std::string   - Название банка
    /// @param adress   : std::string   - Адрес банка
    /// @param type     : std::string   - Форма собственности банка
    void addLine(unsigned int id, std::string name, std::string adress, std::string type);

    /// @brief Удаление строки из таблицы
    /// @param id : unsigned int - Код банка
    void removeLine(unsigned int id);

    /// @brief Добавление в таблицу новой (или изменение существующей) строки с клавиатуры
    void addLineByKeyboard();

    /// @brief Добавление услуги в начало списка предоставляемых банком услуг
    /// @param id               : unsigned int  - Код банка
    /// @param service_index    : unsigned int  - Код услуги
    void addService(unsigned int id, unsigned int service_id);

    /// @brief Добавление услуги в начало списка предоставляемых банком услуг
    /// @param id               : unsigned int  - Код банка
    /// @param service_name     : std::string   - Название услуги
    void addService(unsigned int id, std::string service_name);

    /// @brief Генерация списка государственных банков, предоставляющих ипотечный кредит
    /// @return : unsigned int * - указатель на массив кодов банков удовлетворяющих условию
    unsigned int *getBanks_SpecialFilter();
};

Table::Table()
{
    table_name = "Table";
}

Table::Table(std::string name)
{
    table_name = name;
}

Table::~Table()
{
    delete[] this->data;
}

void Table::print()
{
    std::cout << "\n###  " << this->table_name << " (" << this->n << ")"
              << "  ###\n\n";

    if (this->n == 0)
    {
        std::cout << "* Empty Table *\n\n";
        return;
    }

    unsigned short int maxLen_name = 0;
    unsigned short int maxLen_adress = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        const unsigned short int l_name = (data[i].name.length());
        if (maxLen_name < l_name)
        {
            maxLen_name = l_name;
        }

        const unsigned short int l_adress = (data[i].adress.length());
        if (maxLen_adress < l_adress)
        {
            maxLen_adress = l_adress;
        }
    }

    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << (std::to_string(data[i].id) + " | " + data[i].name + std::string((maxLen_name - (data[i].name.length())), ' ') + " | " + data[i].adress + std::string((maxLen_adress - (data[i].adress.length())), ' ') + " | " + data[i].type + " | ");

        unsigned short int j = 0;

        std::string services_str = "";
        while (data[i].services[j].length() > 0)
        {
            services_str = services_str + data[i].services[j] + ", ";
            j++;
        }
        services_str.pop_back();
        services_str.pop_back();

        std::cout << services_str << "\n";
    }
    std::cout << "\n\n";
}

void Table::fillRandom(const unsigned int lines_quantity)
{
    n = 0;
    for (unsigned int cl = 0; cl < n; cl++)
    {
        data[cl] = Table_Data_Line();
    }

    while (n < lines_quantity && n < this->N)
    {
        this->addLine(rand() % 9000 + 1000, possible_bank_names[(int)(rand() % 100)], possible_adress_street[(int)(rand() % 100)] + ", " + std::to_string((int)(rand() % 90 + 1)), rand() % 2 == 0 ? "commercial" : "state     ");
    }
}

void Table::addLine(unsigned int id, std::string name, std::string adress, std::string type)
{
    id = this->transformID(std::to_string(id));
    type = type.find("c") != type.npos || type.find("C") != type.npos ? "commercial" : "state     ";

    int index = this->getBankIndexById(id);

    if (index != -1)
    {
        data[index].id = id;
        data[index].name = name;
        data[index].adress = adress;
        data[index].type = type;

        for (unsigned short int cl = 0; cl < 8; cl++)
        {
            data[index].services[cl] = "";
        };
        const unsigned short int k = (rand() % 3) + 1;
        for (unsigned short int j = 0; j < k; j++)
        {
            data[index].services[j] = possible_services[(int)(rand() % 8)];
        };
    }
    else if (n < N)
    {
        data[n].id = id;
        data[n].name = name;
        data[n].adress = adress;
        data[n].type = type;

        const unsigned short int k = (rand() % 3) + 1;
        for (unsigned short int j = 0; j < k; j++)
        {
            data[n].services[j] = possible_services[(int)(rand() % 8)];
        };

        n++;
    }
    else
    {
        std::cout << "Unable to add bank: Maximum table size reached"
                  << "\n";
    }
}

void Table::removeLine(unsigned int id)
{
    int index = this->getBankIndexById(id);

    if (index == -1)
    {
        std::cout << "Failed to remove: bank is not founded";
        return;
    }

    this->data[index] = Table_Data_Line();

    for (int i = index; i < this->n - 1; i++)
    {
        this->data[i] = this->data[i + 1];
    }

    this->n = this->n - 1;
}

void Table::addLineByKeyboard()
{
    std::string str_id;
    std::string str_name;
    std::string str_adress;
    std::string str_type;

    std::cout << "Bank id (4 digit integer): ";
    getline(std::cin, str_id);
    std::cout << "Bank name: ";
    getline(std::cin, str_name);
    std::cout << "Adress: ";
    getline(std::cin, str_adress);
    std::cout << "State or commercial: ";
    getline(std::cin, str_type);

    unsigned int id = this->transformID(str_id);

    this->addLine(id, str_name, str_adress, str_type.find("c") != str_type.npos || str_type.find("C") != str_type.npos ? "commercial" : "state     ");
}

void Table::addService(unsigned int id, unsigned int service_index)
{
    int index = this->getBankIndexById(id);

    if (index != -1)
    {
        if (service_index < 8)
        {
            bool hasService = false;

            for (int i = 0; i < 8; i++)
            {
                hasService = possible_services[service_index] == data[index].services[i];
                if (hasService)
                    break;
            }

            if (!hasService)
            {
                for (int i = 6; i >= 0; i--)
                {
                    data[index].services[i + 1] = data[index].services[i];
                }
                data[index].services[0] = possible_services[service_index];
            }
            else
            {
                std::cout << "Failed to add service: This bank already provides the service\n";
            }
        }
        else
        {
            std::cout << "Failed to add service: Unknown service\n";
        }
    }
    else
    {
        std::cout << "Failed to add service: Unknown bank\n";
    }
}

void Table::addService(unsigned int id, std::string service_name)
{
    int service_index = this->getServiceIndexByName(service_name);
    if (service_index != 1)
    {
        this->addService(id, service_index);
    }
    else
    {
        std::cout << "Failed to add service: Unknown service\n";
    }
}

unsigned int Table::get_max_size()
{
    return this->N;
}

unsigned int Table::get_size()
{
    return this->n;
}

unsigned int *Table::getBanks_SpecialFilter()
{
    unsigned int *temp = new unsigned int[this->n];
    int counter = 0;

    for (int i = 0; i < this->n; i++)
    {

        if (this->data[i].type == "state     ")
        {

            bool hasService = false;

            for (int j = 0; j < 8; j++)
            {
                hasService = data[i].services[j] == "provision of mortgage loans";
                if (hasService)
                    break;
            }

            if (hasService)
            {
                temp[counter] = data[i].id;
                counter++;
            }
        }
    }

    unsigned int *banks_ids = new unsigned int[counter + 1];
    banks_ids[0] = counter;

    for (int i = 0; i < counter; i++)
    {
        banks_ids[i + 1] = temp[i];
    }

    return banks_ids;
}
