#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> ans(n);
    stack<pair<int, int>> s; s.push({ v[n - 1] ,n - 1 });
    for (int i = n - 2; i >= 0; i--) {
        while (s.size() && s.top().first > v[i]) {
            ans[s.top().second] = i+1;
            s.pop();
        }
        s.push({ v[i],i });
    }
    while (s.size()) {
        int idx = s.top().second;
        ans[idx] = 0;
        s.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
