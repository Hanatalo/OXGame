// 盤面を表すクラスの定義

class Board
{
private:
    char cell[3][3]; // 3 * 3 の枠
public:
    void show();                  // 盤面を表示する
    bool setCell(Player *player); // 枠に記号を書き込む
    bool judge(Player *player);   // 勝敗を判定する
    Board();                      // コンストラクタ
};
