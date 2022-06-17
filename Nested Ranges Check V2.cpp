#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;
int dict[200005];
int backdict[200005];
int v[200005];
pair<int, int> backup[200005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    multiset<tuple<int, int,int>> start;
    multiset<tuple<int, int,int>> over;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        backup[i] = { a,b };
        start.insert({ a , a - b , i });
        over.insert({ b , b - a , i });
        dict[i] = b; //like dictionary -> where I've to go to find b.
        backdict[i] = a;
    }
    auto it = start.begin();
    while (it != start.end()) {
        int val, len, idx;
        tie(val, len, idx) = *it;
        auto tmp = over.find({ dict[idx],-len,idx });
        v[idx] = tmp != over.begin();
        it = start.erase(it);
        over.erase(tmp);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    start.clear();
    over.clear();
    for (int i = 0; i < n; i++) {
        int a, b; a = backup[i].first; b = backup[i].second;
        start.insert({ a , a - b , i });
        over.insert({ b , b - a , i });
        dict[i] = b; //like dictionary -> where I've to go to find b.
    }
    it = start.begin();
    while (it != start.end()) {
        int val, len, idx;
        tie(val, len, idx) = *it;
        auto tmp = over.find({ dict[idx],-len,idx });
        v[idx] = 0;
        while (over.begin() != tmp) {
            int tval, tlen, tidx;
            tie(tval, tlen, tidx) = *over.begin();
            v[tidx] = 1;
            start.erase(start.find({ backdict[tidx], -tlen, tidx }));
            over.erase(over.begin());
        }
        it = start.erase(it);
        over.erase(tmp);
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}
