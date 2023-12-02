#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
const int MOD = 1e9+7;

#define ordered_set tree<PI, null_type,less<PI>, rb_tree_tag,tree_order_statistics_node_update>

inline void modme(ll& num){
    num %= MOD;
    num += MOD;
    num %= MOD;
}

ll powmod(ll a, ll p){
    if(p==0)return 1;
    ll result = 1;
    if(p%2)result *= a;
    ll tempo = powmod(a,p/2);
    modme(tempo);
    tempo *= tempo;
    modme(tempo);
    result *= tempo;
    modme(result);
    return result;
}

int main() {
    freopen("help.in","r",stdin);
    freopen("help.out","w",stdout);
    int N; cin >> N;
    vector<PI> segs(N);
    ordered_set rs;
    for(int i = 0; i < N ;i++){
        cin >> segs[i].first >> segs[i].second;
    }
    sort(segs.begin(),segs.end());

    vector<ll> dp(N);

    for(int i = 0; i < N; i++){
        ll disjoints = rs.order_of_key({segs[i].first,-1});
        dp[i] = powmod(2,disjoints);
        if(i) dp[i] += 2*dp[i-1];
        modme(dp[i]);
        rs.insert({segs[i].second,i});
    }
    cout << dp[N-1];
}
