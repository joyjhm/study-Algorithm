#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

vector<int> sum;

vector<string> split(string str, char deli) {
    istringstream iss(str);
    string buffer;

    vector<string> result;
    while (getline(iss, buffer, deli)) {
        result.push_back(buffer);               
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    vector<string> minus = split(s, '-');
    for (int i=0; i < minus.size();i++){
        vector<string> plus = split(minus[i], '+');
        int add = 0;
        for (int j = 0; j < plus.size(); j++) {
            add += stoi(plus[j]);
        }
        sum.push_back(add);

    }
    int result = sum[0];
    for(int i =1; i < sum.size(); i++) {
        result -= sum[i];
    }

    cout << result;
}