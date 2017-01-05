#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
string numToString (T Num) {
     ostringstream ss;
     ss << Num;
     return ss.str();
}

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        int fizz = 1;
        int buzz = 1;
        for (int i = 1; i <= n; i++) {
            string str = "";
            if (3 == fizz && 5 == buzz) {
                str = "FizzBuzz";
                fizz = 1;
                buzz = 1;
            } else if (3 == fizz) {
            	str = "Fizz";
            	fizz = 1;
            	buzz++;
			} else if (5 == buzz) {
                str = "Buzz";
                buzz = 1;
                fizz++;
            } else {
                str = numToString(i);
                fizz++;
                buzz++;
            }
            v.push_back(str);
        }
        
        return v;
    }
};

ostream & operator<<(ostream &out, vector<int> v) {
    for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
        out << *ite << " ";
    return out;
}

ostream & operator<<(ostream &out, vector<string> v) {
    for (vector<string>::iterator ite = v.begin(); ite != v.end(); ite++)
        out << *ite << " ";
    return out;
}

int main() {
    int n;
    while (cin >> n) {    	
        Solution sol;
        cout << sol.fizzBuzz(n) << endl;
    }

    return 0;
}
