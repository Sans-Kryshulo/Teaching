#include <iostream>
#include <sstream>
#include "Stack.h"
#include "LinkedList.h"


int getUserInput() {
    while (true) {
        std::string input;
        std::cin >> input;
        std::cin.ignore();
        std::stringstream stream(input);
        int result;
        if (stream >> result && stream.eof()) {
            return result;
        }
        else {
            std::cout << "Ошибка! Введено некоректное значения. Спробуйте ёще раз: ";
        }
    }
}
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
void printLinkedList(const LinkedList& list) {
    LinkedList temp = list;
    while (!temp.isEmpty()) {
        std::cout << temp.pop() << " ";
    }
    std::cout << std::endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int usernum;
    bool ExitBool = false;
    while (ExitBool == false)
    {
        bool open = false;
        bool exit = false;
        usernum = 0;
        std::cout << "Введите целое число от 1 до 2: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                Stack stack;
                stack.push(10);
                stack.push(20);
                stack.push(30);

                std::cout << "Top element is: " << stack.peek() << std::endl;
                std::cout << "Popped element is: " << stack.pop() << std::endl;
                std::cout << "Popped element is: " << stack.pop() << std::endl;
                std::cout << "Top element is: " << stack.peek() << std::endl;
                std::cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
                std::cout << "Popped element is: " << stack.pop() << std::endl;
                std::cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

                open = true;
            }
            else if (usernum == 2) {
                LinkedList list1;
                list1.push(1);
                list1.push(2);
                list1.push(3);

                LinkedList list2;
                list2.push(3);
                list2.push(4);
                list2.push(5);

                std::cout << "List 1: ";
                printLinkedList(list1);
                std::cout << "List 2: ";
                printLinkedList(list2);
                Node* clonedHead = list1.clone();
                std::cout << "Cloned List 1: ";
                printList(clonedHead);
                LinkedList list3 = list1 + list2;
                std::cout << "List 1 + List 2: ";
                printLinkedList(list3);
                LinkedList list4 = list1 * list2;
                std::cout << "List 1 * List 2: ";
                printLinkedList(list4);

                open = true;
            }
            else {
                std::cout << "Введенное значение не в диапазоне. Спробуйте ёще раз: ";
                open = false;
            }
        }
        std::cout << "Продолжить роботу програми? (Y/N)\n";
        while (exit == false)
        {
            std::string userexit;
            std::cin >> userexit;
            if (userexit == "n" || userexit == "N") {
                ExitBool = true;
                exit = true;
            }
            else if (userexit == "y" || userexit == "Y") {
                ExitBool = false;
                exit = true;
            }
            else {
                ExitBool = false;
                exit = false;
                std::cout << "Введено некоректное значения. Спробуйте ёще раз. \n";
            }
        }
    }
}
