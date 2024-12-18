#include <iostream>
#include <sstream>
#include "Queue.h"
#include "DoublyLinkedList.h"
#include "Array.h"

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
        std::cout << "Введите целое число от 1 до 3: ";
        while (open == false)
        {
            usernum = getUserInput();
            if (usernum == 1) {
                Queue<int> q;

                q.enqueue(1);
                q.enqueue(2);
                q.enqueue(3);
                std::cout << "Front element: " << q.front() << std::endl;
                q.dequeue();
                std::cout << "Front element after dequeue: " << q.front() << std::endl;
                q.enqueue(4);
                while (!q.isEmpty()) {
                    std::cout << "Dequeuing: " << q.front() << std::endl;
                    q.dequeue();
                }

                open = true;
            }
            else if (usernum == 2) {
                DoublyLinkedList<int> list1;
                list1.pushBack(1);
                list1.pushBack(2);
                list1.pushBack(3);

                DoublyLinkedList<int> list2;
                list2.pushBack(2);
                list2.pushBack(3);
                list2.pushBack(4);

                std::cout << "List 1: ";
                list1.printList();

                std::cout << "List 2: ";
                list2.printList();

                DoublyLinkedList<int> list3 = list1 + list2;
                std::cout << "List 3 (List 1 + List 2): ";
                list3.printList();

                DoublyLinkedList<int> list4 = list1 * list2;
                std::cout << "List 4 (List 1 * List 2): ";
                list4.printList();

                open = true;
            }
            else if (usernum == 3) {
                Array<int> arr;
                arr.Add(10);
                arr.Add(20);
                arr.Add(30);

                std::cout << "Array size: " << arr.GetSize() << std::endl;
                std::cout << "Element at index 1: " << arr.GetAt(1) << std::endl;

                arr.SetAt(1, 50);
                std::cout << "Array elements: ";
                for (int i = 0; i < arr.GetSize(); ++i) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;

                arr.RemoveAt(0);

                std::cout << "Array elements after removal: ";
                for (int i = 0; i < arr.GetSize(); ++i) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
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
