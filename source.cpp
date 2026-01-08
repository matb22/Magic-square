#include <iostream>
#include <limits>
#include "magic_square.h"
#include <Windows.h>

constexpr int kMinMenuChoice = 1;
constexpr int kMaxMenuChoice = 3;
constexpr int kMinSquareSize = 1;

void DisplayMenu() {
  std::cout << "    ========== Меню ==========\n";
  std::cout << "    1) Создать магический квадрат\n";
  std::cout << "    2) Что такое магический квадрат?\n";
  std::cout << "    3) Выход\n";
  std::cout << "Введите номер пункта:\n>> ";
}

int GetMagicSquareSize() {
  int size = 0;
  
  std::cout << "Введите нечетный порядок квадрата:\n>> ";
  
  while (true) {
    if (!(std::cin >> size)) {
      std::cin.clear();
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
      std::cout << "Ошибка! Введите число от 3 до 2,147,483,646 :\n>> ";
      continue;
    }
    
    if (size <= kMinSquareSize) {
      std::cout << "Порядок должен быть положительным! Попробуйте снова:\n>> ";
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
      continue;
    }
    
    if (size % 2 == 0) {
      std::cout << "Порядок должен быть нечетным! Попробуйте снова:\n>> ";
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
      continue;
    }
    
    break;
  }
  
  return size;
}

bool PromptToContinue() {
  char choice = '\0';
  std::cout << "\nВыполнить еще одну операцию? (y/n): ";
  std::cin >> choice;
  std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
  
  return !(choice == 'n' || choice == 'N');
}

void WaitForEnter() {
  std::cout << "\nНажмите Enter для возврата в меню...";
  std::cin.get();
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

  int menu_choice = 0;
  bool exit_program = false;
  
  while (!exit_program) {
    DisplayMenu();
    
    while (!(std::cin >> menu_choice) ||
           menu_choice < kMinMenuChoice ||
           menu_choice > kMaxMenuChoice) {
      std::cin.clear();
      std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
      std::cout << "Неверный ввод! Выберите пункт 1-3:\n>> ";
    }
    
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    
    switch (menu_choice) {
      case 1: {
        const int square_size = GetMagicSquareSize();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        
        GenerateMagicSquare(square_size);
        
        if (!PromptToContinue()) {
          exit_program = true;
        }
        break;
      }
        
      case 2:
        DisplaySquareInfo();
        WaitForEnter();
        break;
        
      case 3:
        exit_program = true;
        break;
        
      default:
        std::cerr << "Неожиданный выбор меню: " << menu_choice << "\n";
        break;
    }
  }
  
  std::cout << "Программа завершена. До свидания!\n";
  return 0;
}