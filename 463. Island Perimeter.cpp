#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector< vector<int> > &grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i< m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    count += 4;
                    if (i > 0 && grid[i-1][j] == 1)
                        count -= 1;
                    if (i < m-1 && grid[i+1][j] == 1)
                        count -= 1;
                    if (j > 0 && grid[i][j-1] == 1)
                        count -= 1;
                    if (j < n-1 && grid[i][j+1] == 1)
                        count -= 1;
                }
            }
        }
        return count;
    }
};

int main () {
    int m, n;
    cin >> m >> n;

    vector< vector<int> > grid;
    for (int i = 0; i < m; i++) {
        vector<int> vec;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            vec.push_back(num);
        }
        grid.push_back(vec);
    }

    Solution sol;
    cout << sol.islandPerimeter(grid);
    return 0;
}
