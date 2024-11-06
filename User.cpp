#include <iostream>
#include "Player.hpp"
#include "User.hpp"
#include "Computer.hpp"
#include "Board.hpp"

// User.hppの実装

// 手を選ぶ
void User::select()
{
    int n;

    do
    {
        std::cout << mark << "の手を選んでください = ";
        std::cin >> n;
    } while (n < 1 || n > 9);
    number = n;
}

// コンストラクタ
User::User(char mark) : Player(mark)
{
}
