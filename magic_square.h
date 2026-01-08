#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include "magic_square_module.cpp" 

void DisplaySquareInfo() ; 
void OutputSquareConsole(int n, const std::vector<std::vector<int>>& magic_square);
void OutputSquareFile(int n, const std::vector<std::vector<int>>& magic_square);
int CountDigits(int number);
bool IsMagicSquareValid(const std::vector<std::vector<int>>& square);
void GenerateMagicSquare(int square_size) ; 




#endif