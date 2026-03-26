#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool check(map<string,int>& list, const string phoneNumber) {
    string str = "";
    for (int i = 0; i < phoneNumber.length(); i++) {
        str += phoneNumber[i];
        if(list[str] > 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        map<string,int> list;
        list[arr[0]]++;
        int i;
        for (i = 1; i < n; i++) {
            bool isConsist = check(list, arr[i]);
            if(!isConsist) {
                break;
            }
            list[arr[i]]++;
        }
        if(i == n) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}