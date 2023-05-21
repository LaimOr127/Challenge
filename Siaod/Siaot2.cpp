#include <iostream>

using namespace std;

// Определение узла списка
struct Node {
    int data;
    Node* next;
};

// Функция вставки узла в начало списка
void insertAtBeginning(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Функция вывода списка
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Функция, которая переформирует список L1, переписав в начало
// списка его часть, начиная с заданной позиции
void reformatList(Node** head, int pos) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }

    Node* prev = nullptr;
    Node* current = *head;
    int count = 1;

    // Находим узел, начиная с которого нужно переписать список
    while (current != nullptr && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }

    // Если pos выходит за границы списка, то ничего не делаем
    if (current == nullptr) {
        return;
    }

    // Переписываем часть списка, начиная с узла current
    Node* newHead = current;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = *head;
    *head = newHead;
    prev->next = nullptr;
}

// Функция вставки узла в упорядоченный по неубыванию список
void insertInOrder(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (*head == nullptr || data >= (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr && data < current->next->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Функция удаления повторяющихся элементов из упорядоченного по неубыванию списка
void removeDuplicates(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* next = head->next;

    while (next != nullptr) {
        if (current->data == next->data) {
            current->next = next->next;
            delete next;
            next = current->next;
        }
        else {
            current = next;
            next = current->next;
        }
    }
}

int main() {
    Node* head1 = nullptr; // Linked list L1
    insertAtBeginning(&head1, 1);
    insertAtBeginning(&head1, 2);
    insertAtBeginning(&head1, 3);
    insertAtBeginning(&head1, 4);
    insertAtBeginning(&head1, 5);
    insertAtBeginning(&head1, 6);
    cout << "Linked list L1: ";
    printList(head1);

    // Переформируем список L1, переписав в начало
    // списка его часть, начиная с позиции 3
    reformatList(&head1, 3);
    cout << "Linked list L1 after reformatting: ";
    printList(head1);

    // Создаем новый связный список L2 и вставляем в него элементы в упорядоченном порядке
    Node* head2 = nullptr; // Linked list L2
    insertInOrder(&head2, 1);
    insertInOrder(&head2, 5);
    insertInOrder(&head2, 2);
    insertInOrder(&head2, 3);
    insertInOrder(&head2, 2);
    insertInOrder(&head2, 4);
    insertInOrder(&head2, 4);
    insertInOrder(&head2, 6);
    cout << "Linked list L2: ";
    printList(head2);

    // Удаляем повторяющиеся элементы из списка L2
    removeDuplicates(head2);
    cout << "Linked list L2 after removing duplicates: ";
    printList(head2);

    return 0;
}