#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "User.hpp"
#include "Computer.hpp"
#include "Board.hpp"
using namespace std;

int main()
{
    Player *player[2];      // プレイヤーを２名用意する
    User user('o');         // userはOを書き込む
    Computer computer('x'); // computerはxを書き込む
    player[0] = &computer;  // computerが先手のプレイヤー
    player[1] = &user;      // userは後手のプレイヤー
    Board board;            // 盤面
    int turn = 0;           // 順番(0と1で交互に切り替える)

    // 乱数を初期化する
    srand(time(NULL));

    // 勝敗が決まるまで繰り返す
    while (true)
    {
        // 盤面を表示する
        board.show();

        // プレイヤーが手を選ぶ
        do
        {
            player[turn]->select();
        } while (board.setCell(player[turn]) == false);

        if (board.judge(player[turn]))
        {
            // 勝敗が決した場合はゲームを終了する
            break;
        }

        // プレイヤーを交互に切り替える
        if (turn == 0)
        {
            turn = 1;
        }
        else
        {
            turn = 0;
        }
    }

    // 盤面を表示する
    board.show();

    return 0;
}
