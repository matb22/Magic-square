#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

void OutputSquareConsole(int n, const std::vector<std::vector<int>>& magic_square);
void OutputSquareFile(int n, const std::vector<std::vector<int>>& magic_square);
int CountDigits(int number);
bool IsMagicSquareValid(const std::vector<std::vector<int>>& square);

void GenerateMagicSquare(int square_size) {
  const int n = square_size;
  
  std::vector<std::vector<int>> magic_square(n, std::vector<int>(n, 0));

  int i = 0;
  int j = n / 2;

  for (int num = 1; num <= n * n; ++num) {
    magic_square[i][j] = num;

    const int next_i = (i - 1 + n) % n;
    const int next_j = (j + 1) % n;

    if (magic_square[next_i][next_j] != 0) {
      i = (i + 1) % n;
    } else {
      i = next_i;
      j = next_j;
    }
  }

  if (IsMagicSquareValid(magic_square)) {
    std::cout << "✓ Квадрат корректный!\n";
  } else {
    std::cout << "✗ Ошибка: квадрат некорректный!\n";
  }

  OutputSquareConsole(n, magic_square);
  OutputSquareFile(n, magic_square);
}

void OutputSquareConsole(int n, const std::vector<std::vector<int>>& magic_square) {
  std::cout << "Магический квадрат порядка " << n << ":\n";
  std::cout << "Сумма в каждой строке, столбце и диагонали = "
            << n * (n * n + 1) / 2 << "\n\n";

  const int column_width = CountDigits(n * n) + 1;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << std::setw(column_width) << magic_square[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void OutputSquareFile(int n, const std::vector<std::vector<int>>& magic_square) {
  std::ofstream output_file("magic_square.txt");
  if (!output_file.is_open()) {
    std::cerr << "Ошибка: не удалось открыть файл для записи.\n";
    return;
  }

  output_file << "Магический квадрат порядка " << n << ":\n";
  output_file << "Сумма в каждой строке, столбце и диагонали = "
              << n * (n * n + 1) / 2 << "\n\n";

  const int column_width = CountDigits(n * n) + 1;
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      output_file << std::setw(column_width) << magic_square[i][j] << " ";
    }
    output_file << "\n";
  }
}

int CountDigits(int number) {
  if (number == 0) return 1;
  if (number < 0) number = -number;
  
  return static_cast<int>(std::log10(number)) + 1;
}

void DisplaySquareInfo() {
  std::cout << "\n\n  Магический квадрат — это квадратная таблица размером n×n,\n"
            << "  заполненная разными натуральными числами (обычно от 1 до n²)\n"
            << "  таким образом, что сумма чисел в каждой строке, каждом столбце\n"
            << "  и на обеих диагоналях — одинаковая.\n\n";
}

bool IsMagicSquareValid(const std::vector<std::vector<int>>& square) {
  const int n = square.size();
  if (n <= 0 || n % 2 == 0) return false;
  
  std::vector<bool> found(n * n + 1, false);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      const int num = square[i][j];
      if (num < 1 || num > n * n || found[num]) {
        return false;
      }
      found[num] = true;
    }
  }
  
  const int magic_sum = n * (n * n + 1) / 2;
  
  for (int i = 0; i < n; ++i) {
    int row_sum = 0;
    for (int j = 0; j < n; ++j) {
      row_sum += square[i][j];
    }
    if (row_sum != magic_sum) return false;
  }
  
  for (int j = 0; j < n; ++j) {
    int col_sum = 0;
    for (int i = 0; i < n; ++i) {
      col_sum += square[i][j];
    }
    if (col_sum != magic_sum) return false;
  }
  
  int diag1_sum = 0;
  for (int i = 0; i < n; ++i) {
    diag1_sum += square[i][i];
  }
  if (diag1_sum != magic_sum) return false;
  
  int diag2_sum = 0;
  for (int i = 0; i < n; ++i) {
    diag2_sum += square[i][n - 1 - i];
  }
  if (diag2_sum != magic_sum) return false;
  
  return true;
}