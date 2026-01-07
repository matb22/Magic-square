#include <iostream>
#include <limits>
#include "magic_square.h"
#include <windows.h>
#include <cmath>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int task_number;
    int n;
    bool exit_program = false;

    while (!exit_program) {
        std::cout << "    ==========Menu==========\n";
        std::cout << "    1) Создать магический квадрат\n";
        std::cout << "    2) Что такое магический квадрат?\n";
        std::cout << "    3) Выход\n";
        std::cout << "Введите номер желаемого пункта: \n>> ";

        // Проверка ввода пункта меню
        while (!(std::cin >> task_number) || task_number < 1 || task_number > 3) {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "Неверный ввод! Выберите пункт 1-3: \n>> ";
        }

        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // Очистка буфера

        switch (task_number) {
        case 1: {
            
            std::cout << "Введите нечетный порядок магического квадрата: \n>> ";
            
            
            while (true) {
                // Пытаемся прочитать число
                if (!(std::cin >> n)) {
                    // Ошибка ввода (не число)
                    std::cin.clear();
                    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                    std::cout << "Ошибка! Введите число: \n>> ";
                    continue;
                }
                
                // Проверяем на четность
                if (n % 2 == 0) {
                    std::cout << "Порядок должен быть нечетным! Попробуйте снова: \n>> ";
                    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                    continue;
                }
                
                // Проверяем, что число положительное
                if (n <= 0) {
                    std::cout << "Порядок должен быть положительным! Попробуйте снова: \n>> ";
                    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                    continue;
                }
                
                // Все проверки пройдены
                break;
            }
            
           std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // Очистка буфера
            
            // Генерация квадрата
            generateMagicSquare(n);
            
            // Спросить, хочет ли пользователь продолжить
            char choice;
            std::cout << "\nХотите выполнить еще одну операцию? (y/n): ";
            std::cin >> choice;
           std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            
            if (choice == 'n' || choice == 'N') {
                exit_program = true;
            }
            break;
        }
        
        case 2:
            Square_info();
            
            // Спросить, хочет ли пользователь продолжить
            char choice;
            std::cout << "\nНажмите Enter для возврата в меню...";
            std::cin.get();
            break;
            
        case 3:
            exit_program = true;
            break;
        }
    }

    std::cout << "Программа завершена. До свидания!\n";
    return 0;
}