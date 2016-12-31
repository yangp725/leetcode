#include <iostream>
using namespace std;

class Solution {
public:
    // https://tech.liuchao.me/2016/11/count-bits-of-integer/
    // Return the number of onr-bits in the two's complement binary
    // 从二进制数的低位开始逐位遍历，判断最低位是否为1，并消除最低位
    int bitCount(unsigned int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    /* Brian Kernighan's way
       n & (n-1), clear the least significant bit set
         10100
       & 10011
       Brian Kernighan's method go through as many iterations as there are set
       bits
       (https://graphics.stanford.edu/~seander/bithacks.html)
    */
    int bitCountS(unsigned int n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }

    int hammingDistance(int x, int y) {
        return bitCountS(x ^ y);
    }

};


int main () {
    int n = 21;
    Solution sol;
    cout << sol.bitCount(n) << endl;
    cout << sol.bitCountS(n) << endl;
    return 0;
}
