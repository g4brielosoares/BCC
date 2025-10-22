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

    for (long unsigned int i = 0; i < vet.size(); i++) {
        cout << vet[i];
        if(i != vet.size() - 1) cout << "+";
    }
    cout << "\n";

    return 0;
}