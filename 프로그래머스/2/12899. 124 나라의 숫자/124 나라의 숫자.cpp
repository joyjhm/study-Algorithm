#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;



string convert(int n) {
    string str = "";
    
    map<int, char> m = {{0, '4'}, {1, '1'}, {2, '2'}};

    while (n > 0) {
        int rest = n % 3;
        str += m[rest];

        if (rest == 0)
            n = n / 3 - 1;
        else
            n = n / 3;
    }

    reverse(str.begin(), str.end());

    return str;
}

string solution(int n) {
    string str = convert(n);    
    return str;
}