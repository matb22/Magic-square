#include <iostream>
#include <iomanip>
#include <vector> 
#include <fstream>
#include <cmath>




void Output_square_console(int n , std::vector<std::vector<int>> magicSquare) ; 
void Output_square_file(int n , std::vector<std::vector<int>> magicSquare);
int countDigits(int n  )  ; 

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



