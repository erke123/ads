#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main() {
    int n;
    int k;
    cin >> n >> k;
    string words;
    getline(cin, words);
    n = words.size();
    stringstream ss(words);
    vector<string> word;
    string s;
    while (ss >> s) {
        word.push_back(s);
    }
    
}