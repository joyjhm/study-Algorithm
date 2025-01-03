#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool primeChecked[10000000];
bool visited[7];
int result = 0;
vector<char> v;

void checkPrime() {
    primeChecked[0] = true;
    primeChecked[1] = true;
    for (int i = 2; i < sqrt(9999999); i++) {
        if(!primeChecked[i]) {
            for (int j = 2 * i; j < 10000000; j += i) {
                primeChecked[j] = true;
            }            
        }
    }
}

void bruth_force(string numbers) {
    
    if(!v.empty()) {
        int num = stoi(string(v.begin(), v.end()));
        if(!primeChecked[num]) {
            result++;
            primeChecked[num] = true;
        }
    }
    
    for (int i = 0; i < numbers.length(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            v.push_back(numbers[i]);
            bruth_force(numbers);
            v.pop_back();  
            visited[i] = false;
        }
    }
}

int solution(string numbers) {    
    checkPrime();
    bruth_force(numbers);
    
    return result;
}