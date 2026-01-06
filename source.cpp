#include <iostream>
#include "magic_square.h"





int main() {
  int n;
  std::cout << "Введите нечетный порядок магического квадрата: \n>> ";
  std::cin >> n;

  generateMagicSquare(n);

  return 0;
}