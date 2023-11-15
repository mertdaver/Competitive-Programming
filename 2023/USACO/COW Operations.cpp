#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; int n = s.size(); int q; cin >> q;
    vector<vector<int>> pref(n+1,vector<int>(3));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)pref[i][j] = pref[i-1][j];
        char ch = s[i-1];
        if (ch == 'C')pref[i][0]++;
        if (ch == 'O')pref[i][1]++;
        if (ch == 'W')pref[i][2]++;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        
        if ((pref[r][0] - pref[l - 1][0]) % 2 == 1) {
            if ((pref[r][1] - pref[l - 1][1]) % 2 == 0 && (pref[r][2] - pref[l - 1][2]) % 2 == 0) {
                cout << "Y";
            }
            else {
                cout << "N";
            }
        }
        else {
            if ((pref[r][1] - pref[l - 1][1]) % 2 == 1 && (pref[r][2] - pref[l - 1][2]) % 2 == 1) {
                cout << "Y";
            }
            else {
                cout << "N";
            }
        }
    }
}
