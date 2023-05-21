#include "table_vector.cpp"

int App()
{
    srand(time(0));

    Table table("Banks");

    std::cout << "\nThe Table '" << table.table_name << "' has been created\n\n";
    std::cout << "Available commands: \n help     - display this message\n print    - print the table to the console\n fill     - fill the table with random values\n edit     - add a new bank to the table or edit the data about the added bank\n delete   - delete bank data\n service  - add a service provided by the bank\n list     - Create a list of state-owned banks providing mortgage loans\n exit     - end session\n";

    std::string commands[] = {"help", "print", "fill", "edit", "delete", "service", "list", "exit"};

    while (true)
    {
        std::cout << "\nEnter the command: ";
        std::string command;
        getline(std::cin, command);
        std::cout << "\n";

        short int commandIndex = -1;
        for (short int i = 0; i < 8; i++)
        {
            if (commands[i] == command)
            {
                commandIndex = i;
                break;
            }
        }

        bool Exit = false;

        switch (commandIndex)
        {
        case 0: // "help"
        {
            std::cout << "Available commands: \n help     - display this message\n print    - print the table to the console\n fill     - fill the table with random values\n edit     - add a new bank to the table or edit the data about the added bank\n delete   - delete bank data\n service  - add a service provided by the bank\n list     - Create a list of state-owned banks providing mortgage loans\n exit     - end session\n";
            break;
        }
        case 1: // "print"
        {
            table.print();
            break;
        }
        case 2: // "fill"
        {
            std::cout << "Enter the number of rows: ";
            std::string n;
            getline(std::cin, n);
            table.fillRandom(std::stoi(n));
            break;
        }
        case 3: // "edit"
        {
            table.addLineByKeyboard();
            break;
        }
        case 4: // "delete"
        {
            std::cout << "Enter the bank id: ";
            std::string bank_id;
            getline(std::cin, bank_id);
            table.removeLine(std::stoi(bank_id));
            break;
        }
        case 5: // "service"
        {
            std::cout << "Enter the bank id: ";
            std::string bank_id;
            getline(std::cin, bank_id);
            std::cout << "Enter the service name: ";
            std::string service_name;
            getline(std::cin, service_name);
            table.addService(std::stoi(bank_id), service_name);
            break;
        }
        case 6: // "list"
        {
            unsigned int *banks_ids = table.getBanks_SpecialFilter();
            std::cout << "State-owned banks providing mortgage loans: ";
            for (int i = 1; i < banks_ids[0] + 1; i++)
            {
                std::cout << banks_ids[i] << ((i == banks_ids[0]) ? "" : ", ");
            }
            std::cout << "\n";
            delete[] banks_ids;
            break;
        }
        case 7: // "exit"
        {
            Exit = true;
            break;
        }

        default:
        {
            std::cout << "Unknown command\n";
            break;
        }
        }

        if (Exit)
            break;
    }

    std::cout << "Session termination has occurred\n\n";

    return 0;
}
