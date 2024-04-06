#include<iostream>
#include<string>
using namespace std;

int lcs[1001][1001];
 
int main() {

    string str1, str2;
    cin >> str1 >> str2;
    for(int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if(str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }
    int result = 0;
    for(int i = 1; i <= str1.length(); i++) {
        for(int j = 1; j <= str2.length(); j++) {
            result = lcs[i][j] > result ? lcs[i][j] : result;
        }
    }

    cout << result;
}