#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int i = 0;
    ll sum = 0;
    ll target = 1;
    while (i < n && target - v[i] <= sum && target >= v[i]) {
        target = sum + v[i] + 1;
        sum += v[i];
        i++;
    }
    cout << target << endl;
}