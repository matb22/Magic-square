#include <iostream>
#include <iomanip>
#include <vector> 
#include <fstream>
#include <cmath>




void Output_square_console(int n , std::vector<std::vector<int>> magicSquare) ; 
void Output_square_file(int n , std::vector<std::vector<int>> magicSquare);
int countDigits(int n  )  ; 
bool isMagicSquareValid(const std::vector<std::vector<int>>& square) ; 

void generateMagicSquare(int n) {
  
  

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

  if (isMagicSquareValid(magicSquare)) {
        std::cout << "✓ Квадрат корректный!\n";
    } 
  else {
        std::cout << "✗ Ошибка: квадрат некорректный!\n";
    }






  Output_square_console(n , magicSquare) ; 
  Output_square_file( n , magicSquare) ; 
  
}


void Output_square_console(int n , std::vector<std::vector<int>> magicSquare) { 
  std::cout << "Магический квадрат порядка " << n << ":\n";
  std::cout << "Сумма в каждой строке, столбце и диагонали = " 
       << n * (n * n + 1) / 2 << "\n\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::setw(countDigits(n*n) + 1) << magicSquare[i][j] << " ";
    }
    std::cout << std::endl;
  }
}



void Output_square_file(int n , std::vector<std::vector<int>> magicSquare) { 
  std::ofstream f2 ; 
  f2.open("magic_square.txt" , std::ios::out) ;
  
  f2 << "Магический квадрат порядка " << n << ":\n";
  f2 << "Сумма в каждой строке, столбце и диагонали = " 
       << n * (n * n + 1) / 2 << "\n\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      f2 << std::setw(countDigits(n*n) +  1) << magicSquare[i][j] << " ";
    }
    f2 << std::endl;
  }

  f2.close() ; 
}





int countDigits(int n  ) {

    if (n == 0) return 1; 
    if (n < 0) n = -n; 
    
    return static_cast<int>(log10(n)) + 1;
}







void Square_info() { 
  std::cout<<"\n\n  Магический квадрат — это квадратная таблица размером n×n, заполненная разными\n" ; 
  std::cout<<"  натуральными числами (обычно от 1 до n²) таким образом, что:\n" ; 
  std::cout<<"* Cумма чисел в каждой строке, каждом столбце и на обеих диагоналях — одинаковая.\n\n" ; 
  
 
  
}





bool isMagicSquareValid(const std::vector<std::vector<int>>& square) {
    int n = square.size();
    if (n % 2 == 0) return false; 
    
    // Проверяем, что все числа от 1 до n² присутствуют ровно один раз
    std::vector<bool> found(n * n + 1, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = square[i][j];
            if (num < 1 || num > n * n || found[num]) {
                return false;
            }
            found[num] = true;
        }
    }
    
    // Вычисляем магическую константу
    int magicSum = n * (n * n + 1) / 2;
    
    // Проверяем суммы строк
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
        }
        if (rowSum != magicSum) return false;
    }
    
    // Проверяем суммы столбцов
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += square[i][j];
        }
        if (colSum != magicSum) return false;
    }
    
    // Проверяем главную диагональ
    int diag1Sum = 0;
    for (int i = 0; i < n; i++) {
        diag1Sum += square[i][i];
    }
    if (diag1Sum != magicSum) return false;
    
    // Проверяем побочную диагональ
    int diag2Sum = 0;
    for (int i = 0; i < n; i++) {
        diag2Sum += square[i][n - 1 - i];
    }
    if (diag2Sum != magicSum) return false;
    
    return true;
}