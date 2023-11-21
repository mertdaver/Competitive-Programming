#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
int N,x;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> x;
    
    vector<int> weight(N);
    for (int i = 0; i < N; i++)cin >> weight[i];
    vector<PI> best(1<<N);
    best[0] = { 1,0 };

    for (int s = 1; s < (1 << N); s++) {
        best[s] = { N + 1,0 };
        for (int p = 0; p < N; p++) {
            if (s & (1 << p)) {

                auto option = best[s ^ (1 << p)];
                if (option.second + weight[p] <= x) {
                    option.second += weight[p];
                }
                else {
                    option.first++;
                    option.second = weight[p];
                }

                best[s] = min(best[s], option);
            }
        }
    }

    cout << best[best.size()-1].first;
}
