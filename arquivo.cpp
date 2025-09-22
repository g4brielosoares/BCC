#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> seuDe(10, 0);

    seuDe.insert(seuDe.end(), 312);
    seuDe.insert(seuDe.begin(), 34);
    seuDe.insert(seuDe.begin(), 65);

    seuDe[4] = 1;
    vector<int> seuDe2(seuDe);

    seuDe2.push_back(21);

    for (auto valor : seuDe2) 
        cout << valor << "\n";

    sort(seuDe.begin(), seuDe.end(), greater<int>());
    reverse (seuDe.begin(), seuDe.end());

    cout << "\n";
    for (auto valor : seuDe) 
        cout << valor << "\n";

    cout << "\n" << seuDe.back() << "\n";
    cout << seuDe.front() << "\n";

    cout << seuDe[0] << "\n";
    
    double dado;

    cin >> dado;
    cout << fixed << setprecision(2) << dado << "\n";
    
    return 0;
}