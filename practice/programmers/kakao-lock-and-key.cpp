#include <string>
#include <vector>

using namespace std;

int key_size, lock_size, board_size;

bool check(int y, int x, vector<vector<int>> board, vector<vector<int>> key)
{
    for (int i = 0; i < key_size; i++)
        for (int j = 0; j < key_size; j++)
            board[y + i][x + j] += key[i][j];

    for (int i = key_size - 1; i <= board_size - key_size; i++)
        for (int j = key_size - 1; j <= board_size - key_size; j++)
            if (board[i][j] != 1)
                return false;
    
    return true;
}

void rotate(vector<vector<int>> &key)
{
    vector<vector<int>> res(key_size, vector<int>(key_size));

    for (int j = key_size - 1; j >= 0; j--)
        for (int i = 0; i < key_size; i++)
            res[i][j] = key[key_size - j - 1][i];

    key = res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    key_size = key.size();
    lock_size = lock.size();
    board_size = lock_size + (key_size - 1) * 2;

    vector<vector<int>> board(board_size, vector<int>(board_size, 0));

    for (int i = key_size - 1; i <= board_size - key_size; i++)
        for (int j = key_size - 1; j <= board_size - key_size; j++)
            board[i][j] = lock[i - key_size + 1][j - key_size + 1];

    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 0; i <= board_size - key_size; i++)
            for (int j = 0; j <= board_size - key_size; j++)
                if (check(i, j, board, key))
                    return true;

        rotate(key);
    }

    return false;
}