#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> v;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int maxi; maxi = 0;
    int cur; cur = 0;
    int r; r = 0;
    int l; l = 0;
    while (r < n) {
        if (m.count(v[r])) {
            auto it = m.find(v[r]);
            if ((*it).second >= l) {
                cur -= (*it).second - l + 1;
                l = (*it).second + 1;
            }
            m[v[r]] = r;
        }
        m.insert({ v[r],r });
        cur++;
        maxi = max(cur, maxi);
        r++;
    }
    cout << maxi << endl;
}