#include <iostream>
#include <vector>
using namespace std;

vector<string> ascii;

int length;

char num[11][7][6] = {{"xxxxx", "x...x", "x...x", "x...x", "x...x", "x...x", "xxxxx"},
                    {"....x", "....x", "....x", "....x", "....x", "....x", "....x"},
                    {"xxxxx", "....x", "....x", "xxxxx", "x....", "x....", "xxxxx"},
                    {"xxxxx", "....x", "....x", "xxxxx", "....x", "....x", "xxxxx"},
                    {"x...x", "x...x", "x...x", "xxxxx", "....x", "....x", "....x"},
                    {"xxxxx", "x....", "x....", "xxxxx", "....x", "....x", "xxxxx"},
                    {"xxxxx", "x....", "x....", "xxxxx", "x...x", "x...x", "xxxxx"},
                    {"xxxxx", "....x", "....x", "....x", "....x", "....x", "....x"},
                    {"xxxxx", "x...x", "x...x", "xxxxx", "x...x", "x...x", "xxxxx"},
                    {"xxxxx", "x...x", "x...x", "xxxxx", "....x", "....x", "xxxxx"},
                    {".....", "..x..", "..x..", "xxxxx", "..x..", "..x..", "....."}};


bool checkNumber(int number, int pos) {

    for (int i = 0; i < 7; i++) {
        int idx = 0;
        for (int j = pos; j < pos + 5; j++) {
            if(ascii[i][j] == num[number][i][idx]) {
                idx++;
            } else {
                return false;
            }
        }
    }

    return true;
}

int findNumber(int pos) {

    bool isNum[11] = {false, };

    for (int i = 0; i < 11; i++) {
        if(checkNumber(i, pos)) {
            isNum[i] = true;
        }
    }

    for (int i = 0; i < 11; i++) {
        if(isNum[i]) {
            return i;
        }
    }

    return -1;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 7; i++) {
        string str1;
        cin >> str1;
        ascii.push_back(str1);
    }

    length = ascii[0].length();


    string str = "";
    for (int i = 0; i < length; i = i + 6) {
        int tmp = findNumber(i);
        if(tmp == 10) {
            str += "+";
        } else {
            str += to_string(tmp);
        }
    }

    int pos = str.find("+");
    int result = stoi(str.substr(0, pos)) + stoi(str.substr(pos + 1));

    str = to_string(result);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < str.length(); j++) {
            int n = str[j] - '0';
            for (int k = 0; k < 5; k++) {
                cout << num[n][i][k];
            }
            if(j != str.length() - 1) {
                cout << '.';
            }
        }
        cout << '\n';
    }

}