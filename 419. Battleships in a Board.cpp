#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBattleships0(vector< vector<char> > &board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                if ('X' == board[i][j]) {
                    count++;
                    board[i][j] = '.';
                    int tmpj = j;
                    while (++tmpj < n && 'X' == board[i][tmpj])
                        board[i][tmpj] = '.';
                    int tmpi = i;
                    while (++tmpi < m && 'X' == board[tmpi][j])
                        board[tmpi][j] = '.';
                    j = tmpj;
                }
            }
        }
        return count;
    }

    // just think which 'X' can represent the ship
    // or when should we increase count?
    // when we are traveling the matrix from top to bottom, from left to right
    // so if we set the top-left 'X' as the represent of the ship, then the 'X'
    // can not stand for the ship, if there were another 'X' on it's top or left
    int countBattleships(vector< vector<char> > &board) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                if ('X' == board[i][j] && (0 == i || 'X' != board[i-1][j])
                                       && (0 == j || 'X' != board[i][j-1]))
                count++;
            }
        }
        return count;
    }
};

int main () {
    int m;
    cin >> m;

    vector< vector<char> > board;
    for (int i = 0; i <= m; i++) {
        string vec;
        // getline while catch the newline behind the input of m
        // so, I use "i <= m" and ignore the case when i equal to 0
        getline(cin, vec);
        if (0 == i) continue;
        vector<char> vec1(vec.begin(), vec.end());
        board.push_back(vec1);
    }

    Solution sol;
    cout << sol.countBattleships(board);
    /*
    vector< vector<char> >::iterator row;
    vector<char>::iterator col;
    for (row = board.begin(); row != board.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            cout << *col;
        }
        cout << endl;
    }
    */

    return 0;
}
