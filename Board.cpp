// Board.hppの実装

#include <iostream>
#include "Player.hpp"
#include "User.hpp"
#include "Computer.hpp"
#include "Board.hpp"

// 盤面を表示する
void Board::show()
{
    std::cout << "\n";
    for (int v = 0; v < 3; v++)
    {
        std::cout << "+-+-+-+\n";
        for (int h = 0; h < 3; h++)
        {
            std::cout << "|" << cell[v][h];
        }
        std::cout << "|\n";
    }
    std::cout << "+-+-+-+\n";
}

// 枠にOXを書き込む
bool Board::setCell(Player *player)
{
    int number = player->getNumber();
    int v = (number - 1) / 3;
    int h = (number - 1) % 3;

    if (cell[v][h] >= '1' && cell[v][h] <= '9')
    {
        // 選択可能ならtrueを返す
        cell[v][h] = player->getMark();
        return true;
    }
    else
    {
        // 選択不可能
        std::cout << "そこは選択できません！\n";
        return false;
    }
}

// 勝敗を判定する
bool Board::judge(Player *player)
{
    // プレイヤーが勝ちならTrueを返す
    char mark = player->getMark();
    if (cell[0][0] == mark && cell[0][1] == mark && cell[0][2] == mark ||
        cell[1][0] == mark && cell[1][1] == mark && cell[1][2] == mark ||
        cell[2][0] == mark && cell[2][1] == mark && cell[2][2] == mark ||
        cell[0][0] == mark && cell[1][0] == mark && cell[2][0] == mark ||
        cell[0][1] == mark && cell[1][1] == mark && cell[2][1] == mark ||
        cell[0][2] == mark && cell[1][2] == mark && cell[2][2] == mark ||
        cell[0][0] == mark && cell[1][1] == mark && cell[2][2] == mark ||
        cell[2][0] == mark && cell[1][1] == mark && cell[0][2] == mark)
    {
        std::cout << " \n勝負あり:" << mark << "の勝ちです!\n";
        return true;
    }

    // 引き分けの場合Trueを返す
    bool draw = true;
    for (int v = 0; v < 3 && draw; v++)
    {
        for (int h = 0; h < 3 && draw; h++)
        {
            if (cell[v][h] >= '1' && cell[v][h] <= '9')
            {
                draw = false;
            }
        }
    }
    if (draw)
    {
        std::cout << "\n勝負あり : " << "引き分けです。\n";
        return true;
    }

    // 決着が決まっていない場合はfalseを返す
    return false;
}

// コンストラクタ
Board::Board()
{
    for (int v = 0; v < 3; v++)
    {
        for (int h = 0; h < 3; h++)
        {
            cell[v][h] = (v * 3 + h + 1) + '0';
        }
    }
}
