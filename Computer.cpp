// Computer.hppの実装

#include <iostream>
#include <cstdlib>
#include "Player.hpp"
#include "User.hpp"
#include "Computer.hpp"
#include "Board.hpp"

// 手を選ぶ
void Computer::select()
{
    number = rand() % 9 + 1;
    std::cout << mark << "の手を選んでください = " << number << "\n";
}

// コンストラクタ
Computer::Computer(char mark) : Player(mark)
{
}