#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
int n, m;
const int MOD = 998244353;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
 
    ll result = 1;
    int i = n;
    int target = m - 1;   
    int len = 0;
    bool optional = false;
    while (--i >= 0) {
        if (A[i] == B[target]) {
            optional = true;
        }
        if (A[i] >= B[target] && optional) {
            len++;
        }
        else if(A[i]<B[target]) {
            result *= len%MOD;
            result %= MOD;
            target--;
            if (target < 0) {
                cout << 0 << '\n';
                return 0;
            }
            len = 0;
            optional = false;
            if (A[i] == B[target]) {
                optional = true;
            }
            if (A[i] >= B[target] && optional) {
                len++;
            }
            else if(A[i]<B[target]) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    if (target > 0 || !optional) {
        cout << 0 << '\n';
        return 0;
    }
 
    cout << result << '\n';
}
