#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<int > s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    auto it = s.begin();
    bool flag = false;
    while (s.size()) {
        if (!flag) { flag = true; it++;}
        else {
            cout << *it << " ";
            it = s.erase(it);
            flag = false;
        }
        if (it == s.end()) {
            it = s.begin();
        }
    }
}
