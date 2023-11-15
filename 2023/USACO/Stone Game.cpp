#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define PI pair<int,int>
#define PII pair<pair<int,int>,ll>
typedef long long ll;
ll lb[2*(ll)1e6+5]; //lb[k] := number of elements whom k is bigger (not strictly) than.
vector<int> stones;
int N;

void init() {
    int last = 0;
    for (int k = 1; k <= 2*1e6+4; k++) {
        while (last < N && k >= stones[last]) {
            last++;
        }
        lb[k] = last;
    }
}

int maximalProduct(int k) {
    int t = 1;
    vector<PII> intervals;
    while (t*k <= stones.back()) {
        ll l = t*k;
        ll r = t * k + k - 1;//min(t * k + k - 1,(int)1e6+4);
        ll a1, a2;
        a1 = lb[t*k-1];
        a2 = lb[r];

        if ((a2 - a1) % 2 == 1) { //i.e [kt,kt+k) is an interval of odd size.
            intervals.push_back({ { l,r }, a2 - a1 });
            if (intervals.size() > 2) break;
        } 
        t++;
    }
    if (intervals.size() == 0 || intervals.size() > 2) {
        return 0;
    }
    else {
        if (intervals.size() == 1) {
            if (intervals[0].first.first == k) {
                return intervals[0].second;
            }
        }
        else {
            if (intervals[1].first.first == intervals[0].first.second + 1) {
                return intervals[1].second;
            }
        }
    }
    return 0;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    stones.resize(N,0);

    for (int i = 0; i < N; i++)
        cin >> stones[i];

    sort(stones.begin(), stones.end());
    ll result = 0;
    init();
                                        
    for (int k = 1; k <= stones.back(); k++) { //Assuming we're taking k stones at first move. 
        ll wins = maximalProduct(k);
        result += wins;
    }

    cout << result << '\n';
}
