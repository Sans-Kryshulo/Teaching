#include <iostream>
#include <sstream>
#include <random>
#include <chrono>
#include <thread>
#include "BracketChecker.h"
#include "Passenger.h"
#include "Bus.h"
#include "Stop.h"
#include "Printer.h"

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
                const char* str1 = "({x-y-z}*[x+2y]-(z+4x));";
                const char* str2 = "([x-y-z}*[x+2y)-{z+4x)];";

                BracketChecker checker;
                checker.check(str1);
                std::cout << "=====================\n";
                checker.check(str2);

                open = true;
            }
            else if (usernum == 2) {

                Stop stop1(10, 15, false);
                Stop stop2(8, 20, true);

                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> passengerTime(5, 15);
                std::uniform_int_distribution<> busTime(10, 30);

                bool stop1Loaded = false;
                bool stop2Loaded = false;

                while (!stop1Loaded || !stop2Loaded) {
                    if (!stop1Loaded && std::chrono::system_clock::now().time_since_epoch().count() % passengerTime(gen) == 0) {
                        Passenger passenger(std::chrono::system_clock::now().time_since_epoch().count());
                        stop1.addPassenger(std::move(passenger));
                        std::cout << "Passenger arrived at stop 1 at time: " << passenger.getTimeArrival() << std::endl;
                    }

                    if (!stop1Loaded && std::chrono::system_clock::now().time_since_epoch().count() % busTime(gen) == 0) {
                        Bus bus(15);
                        std::cout << "Bus arrived at stop 1 at time: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;

                        while (!stop1.isFull() && bus.getNumPassengers() < bus.getCapacity()) {
                            if (stop1.getNumPassengers() == 0) {
                                break;
                            }
                            Passenger passenger = std::move(stop1.popPassenger());
                            bus.addPassenger(std::move(passenger));
                        }
                        std::cout << "Bus capacity at stop 1: " << bus.getNumPassengers() << "/" << bus.getCapacity() << std::endl;

                        if (stop1.getNumPassengers() == 0) {
                            std::cout << "Bus left stop 1\n";
                            stop1Loaded = true;
                        }
                    }

                    if (!stop2Loaded && std::chrono::system_clock::now().time_since_epoch().count() % passengerTime(gen) == 0) {
                        Passenger passenger(std::chrono::system_clock::now().time_since_epoch().count());
                        stop2.addPassenger(std::move(passenger));
                        std::cout << "Passenger arrived at stop 2 at time: " << passenger.getTimeArrival() << std::endl;
                    }

                    if (!stop2Loaded && std::chrono::system_clock::now().time_since_epoch().count() % busTime(gen) == 0) {
                        Bus bus(15);
                        std::cout << "Bus arrived at stop 2 at time: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;

                        while (!stop2.isFull() && bus.getNumPassengers() < bus.getCapacity()) {
                            if (stop2.getNumPassengers() == 0) {
                                break;
                            }
                            Passenger passenger = std::move(stop2.popPassenger());
                            bus.addPassenger(std::move(passenger));
                        }
                        std::cout << "Bus capacity at stop 2: " << bus.getNumPassengers() << "/" << bus.getCapacity() << std::endl;

                        if (stop2.getNumPassengers() == 0) {
                            std::cout << "Bus left stop 2\n";
                            stop2Loaded = true;
                        }
                    }

                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                std::cout << "Both stops are loaded. Program finished.\n";

                open = true;
            }
            else if (usernum == 3) {
                Printer printer;

                // Создаем поток для обработки печати
                std::thread printThread(&Printer::print, &printer);

                // Эмулируем отправку запросов на печать
                for (int i = 0; i < 10; ++i) {
                    PrintRequest request("User " + std::to_string(i), rand() % 3); // Генерируем случайный приоритет
                    printer.addPrintRequest(request);
                }

                // Подождем некоторое время, чтобы принтер успел обработать все запросы
                std::this_thread::sleep_for(std::chrono::seconds(10));

                // Выведем статистику о печати
                printer.printStatistics();

                // Завершаем поток обработки печати
                printThread.join();

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
