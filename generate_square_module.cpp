#include <iostream>
#include <iomanip>
#include <vector> 

void generateMagicSquare(int n) {
  if (n % 2 == 0) {
    std::cout << "Порядок должен быть нечетным!" << std::endl;
    return;
  }

  std::vector<std::vector<int>> magicSquare(n, std::vector<int>(n, 0));

  int i = 0;
  int j = n / 2;

  for (int num = 1; num <= n * n; num++) {
    magicSquare[i][j] = num;

    int next_i = (i - 1 + n) % n;
    int next_j = (j + 1) % n;

    if (magicSquare[next_i][next_j] != 0) {
      i = (i + 1) % n;
    } 
   else {
      i = next_i;
      j = next_j;
    }
  }

  std::cout << "Магический квадрат порядка " << n << ":\n";
  std::cout << "Сумма в каждой строке, столбце и диагонали = " 
       << n * (n * n + 1) / 2 << "\n\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::setw(4) << magicSquare[i][j] << " ";
    }
    std::cout << std::endl;
  }
}