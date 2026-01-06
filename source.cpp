#include <iostream>
#include "magic_square.h"



  

int main() {
  int task_number;
  int n ;

  std::cout<<"    ==========Menu========== \n " << "   1)Создать магический квадрат \n" << "    2)Что такое магический квадрат? \n" << "    3)Выход \n" ; 
  std::cout<<"Введите номер желаемого пункта : \n>> ";
  std::cin>>task_number ; 



  while (task_number != 3) { 
    switch (task_number)
    {
    case 1:
      
     
      std::cout << "Введите нечетный порядок магического квадрата: \n>> ";
      std::cin >> n;

      generateMagicSquare(n);
      break;
    case 2: 
      std::cout<<"МИНИ ИНСТРУКЦИЯ " ; 

      break ; 
    case 3 : 
      break ;

    default:
      std::cout<<"Выберите пункт 1-3 :\n>> " ;
      std::cin>>task_number ;  
      break ;
    }
  }

  

  return 0;
}