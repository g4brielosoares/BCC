#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;
    vector<char> vet;
    for (auto c : s) {
        if (c != '+')
            vet.push_back(c);
    }

    sort(vet.begin(), vet.end());

    for (auto c : vet) {
        cout << c;
        if(c != vet.back()) cout << "+";
    }
    cout << "\n";

    return 0;
}