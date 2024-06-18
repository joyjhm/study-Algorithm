#include <iostream>
#include <string>

using namespace std;

char encoding[10000];

int main() {
    int n;
    while(true) {
        cin >> n;
        cin.ignore();

        if (n == 0) {
            break;
        }
        string str;
        getline(cin, str);
        int length = 0;
        for (int i = 0; i < str.length(); i++) {
            str[i] = toupper(str[i]);
            if(str[i] >= 'A' && str[i] <= 'Z') {
                length++;
            }
        }

        encoding[0] = str[0];
        int start = 1;
        int idx = 0;
        for (int i = 1; i < str.length(); i++) {
            if(str[i] == ' ') {
                continue;
            }
            idx = idx + n;
            if (idx >= length) {
                idx = start;
                start++;
            }
            encoding[idx] = str[i];
        }

        for (int i = 0; i < length; i++) {
            cout << encoding[i];
        }
        cout << '\n';

    }
}