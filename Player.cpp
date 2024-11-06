// Player.hppの実装
#include <iostream>
#include "Player.hpp"
#include "User.hpp"
#include "Computer.hpp"
#include "Board.hpp"
// 記号を返す
char Player::getMark()
{
    return mark;
}

// 手を返す
int Player::getNumber()
{
    return number;
}

// コンストラクタ
Player::Player(char mark)
{
    this->mark = mark;
}
