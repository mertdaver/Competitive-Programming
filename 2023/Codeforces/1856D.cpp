#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
 
using namespace std;
 
#define PI pair<int,int>
 
int query(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
 
    int res;
    cin >> res;
    return res;
}
 
int daq(int l, int r) { //return index of maximal value in the interval [i,j]
    if (l == r) return l;
 
    int m = (l + r) / 2;
    int a = daq(l, m);
    int b = daq(m + 1, r);
 
    int r1, r2;
    r1 = query(a,b-1);
    r2 = query(a,b);
 
    if (r1 == r2) {
        return b;
    } else {
        return a;
    }
}
 
void solve() {
    int n;
    cin >> n;
 
    int result = daq(1, n);
    cout << "! " << result << endl;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
 
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}
