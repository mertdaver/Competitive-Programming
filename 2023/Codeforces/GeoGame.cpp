#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
#define PI pair<int,int>

void solve() {
    int N; cin >> N;
    set<int> points[2];

    int X,Y; cin >> X >> Y;
    int start = (X%2)^(Y%2);
    
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        points[(X % 2) ^ (Y % 2)].insert(i);
    }

    if (points[start].size() >= points[1 ^ start].size()) {
        cout << "First" << endl;
        cout.flush();

        int turn = 0;
        int lastType = start;
        while (turn < N) {
            if (turn % 2 == 0) {
                int idx;
                if (points[1 ^ lastType].size())idx = *points[1 ^ lastType].begin();
                else idx = *points[lastType].begin();
                cout << idx + 1 << endl;
                cout.flush();
                if (points[1 ^ lastType].size()) points[1 ^ lastType].erase(points[1 ^ lastType].begin());
                else points[lastType].erase(points[lastType].begin());
            }
            else {
                int idx; cin >> idx; --idx;
                if (idx == -2)return;
                if (points[0].count(idx)) {
                    points[0].erase(idx);
                    lastType = 0;
                }
                else {
                    points[1].erase(idx);
                    lastType = 1;
                }
            }
            turn++;
        }

    }

    else {
        cout << "Second" << endl;
        cout.flush();

        int turn = 0;
        int lastType = start;
        while (turn < N) {
            if (turn % 2 == 1) {
                int idx;
                if (points[1 ^ lastType].size())idx = *points[1 ^ lastType].begin();
                else idx = *points[lastType].begin();
                cout << idx + 1 << endl;
                cout.flush();
                if (points[1 ^ lastType].size()) points[1 ^ lastType].erase(points[1 ^ lastType].begin());
                else points[lastType].erase(points[lastType].begin());
            }
            else {
                int idx; cin >> idx; --idx;
                if (idx == -2)return;
                if (points[0].count(idx)) {
                    points[0].erase(idx);
                    lastType = 0;
                }
                else {
                    points[1].erase(idx);
                    lastType = 1;
                }
            }
            turn++;
        }
    }
    cout.flush();

}




int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
