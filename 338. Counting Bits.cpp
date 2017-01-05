#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits0(int num) {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= num; i++) {
            v.push_back(v[i & (i-1)]+ 1);
        }
        return v;
    }

    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        for (int i = 1; i <= num; i++) {
            v.push_back(v[i >> 1] + (i&1)); // addition priority higher than &
        }
        return v;
    }
};

ostream & operator<<(ostream &out, vector<int> v) {
    for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
        out << *ite << " ";
    return out;
}

int main() {
    int n;
    while (cin >> n) {
        Solution sol;
        cout << sol.countBits(n) << endl;
    }

    return 0;
}
