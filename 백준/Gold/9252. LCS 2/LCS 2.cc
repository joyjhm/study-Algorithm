#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001][1001];
 
int main() {

    string str1, str2;
    cin >> str1;
    cin >> str2;

    vector<char> s1(str1.length() + 1);
    vector<char> s2(str2.length() + 1);

    for (int i = 0; i < str1.length(); i++) {
        s1[i + 1] = str1[i];
    }

    for (int i = 0; i < str2.length(); i++) {
        s2[i + 1] = str2[i];
    }

    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int y = str1.length();
    int x = str2.length();

    vector<char> result;
    while(dp[y][x] != 0) {
        if(dp[y][x] == dp[y - 1][x]) {
            y--;
        } 
        else if (dp[y][x] == dp[y][x - 1]) {
            x--;
        } 
        else {
            y--;
            x--;
            result.push_back(str1[y]);
        }
    }

    cout << dp[str1.length()][str2.length()] << '\n';

    while(!result.empty()) {
        cout << result.back();
        result.pop_back();
    }

}