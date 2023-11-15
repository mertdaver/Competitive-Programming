#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

typedef long long ll;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({ a, 1 });
        v.push_back({ b,-1 });
    }
    sort(v.begin(), v.end());
    int maxi, cur; maxi = 0; cur = 0;
    for (pair<int,int> x : v) {
        cur += x.second;
        maxi = max(cur, maxi);
    }
    cout << maxi << endl;
}

/*
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    unordered_multiset<ll> come; //how many will come in the i-th hour.
    unordered_multiset<ll> leave; //how many will leave in the i-th hour.
    int m, s; m = 0; s = 0;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        //v[i] = { a,b };
        m = max(m, b);
        come.insert(a);
        leave.insert(b);
    }
    int maxi = 0;
    int cur = 0;
    int i = s;
    while (i < m) {
        cur += come.count(i) - leave.count(i);
        maxi = max(cur, maxi);
        i++;
    }
    cout << maxi << '\n';
*/
