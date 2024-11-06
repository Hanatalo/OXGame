// プレイヤーを表すクラスの定義
class Player
{
protected:
    char mark;  // 枠に書き込む記号
    int number; // 選択箇所
public:
    virtual void select() = 0; // 手を選ぶ
    char getMark();            // 記号を返す
    int getNumber();           // 手をかえす
    Player(char mark);
};