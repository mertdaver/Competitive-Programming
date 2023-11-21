#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll factorial[2*(int)1e6+5];

void init() {
    factorial[0] = 1;
    for (int i = 1; i <= 2*1e6; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

ll powMod(ll x, ll p) { //return x^p mod MOD, x^p = x^p/2 * x^p/2
    if (p == 0) return 1;
    ll result = 1;
    if (p % 2 == 1) {
        result *= x;
    }
    ll tempo = powMod(x, p / 2);
    result *= (tempo * tempo) % MOD; result %= MOD;
    return (result+MOD)%MOD;
}

ll lowerb(ll x, ll target,ll N) {
    ll curr = x;
    ll jump = 1;
    while ((N / curr) == (N / x)) {
        curr += jump;
        jump *= 2;
    }
    jump /= 2;
    curr -= jump;
    while (jump) {
        if (N / x == N/(curr+jump)) {
            curr += jump;
        }
        jump /= 2;
    }
    return curr;
}

void SumOfDivisors() {

    //We'll implement the following algorithm: we'll divide our solution to two cases.
    //first one - we'll calculate the contribution of each k in [1,1e6] to the total sum.
    //The number k has contributed overall floor(N/k)*k, as it has appeared in k,2k,...,floor(n/k)*k
    //so we'll basically run over all k in [1,1e6] and add floor(N/k)*k to the overall result.
    //Second case - the interval [1e6,1e12].
    //Let's use the following observation - each number in [1e6,1e12] has appeared no more than 1e6 times.
    //because for k in [1e6,1e12] N/k <= N/1e6.
    //With the usage of the fact the numbers which appears excatly i times in total sum are consecutive, we can
    //binary search the end of each consecutive elements which appear exactly i times, and then move to the following 
    //sequence. 

    ll N; cin >> N;
    
    //First part

    ll result = 0;
    ll bound = 1e6;
    for (int k = 1; k <= bound; k++) {
        result += ((N / k) * k)%MOD;
        result %= MOD;
    }

    //Second part

    //x - starting position, target - number of apperances. return last element k' which satisfies N/k' = target.

    ll st = bound + 1;
    ll inv2 = powMod(2, MOD - 2);
    while (st <= N) {
        ll last = min(lowerb(st, N / st,N),N);
        //well dividing by 2 is problematic. 
        //we'll add (last+1)choose 2 to the answer.
        ll sum = (((((last + 1) % MOD) * (last % MOD))%MOD) * inv2)%MOD - (((st % MOD) * ((st - 1) % MOD)%MOD) * inv2)%MOD;
        sum = (sum + MOD) % MOD;
        result += (sum * (N / st)) % MOD;
        result = (result + MOD) % MOD;
        st = last + 1;
    }
    cout << (result+MOD) % MOD << '\n';
}

void CreatingStrings2() {
    string str; cin >> str;
    ll N = str.size();
    vector<int> cnt(26);
    for (int i = 0; i < N; i++) {
        cnt[str[i] - 'a']++;
    }
    ll result = factorial[N];
    for (int i = 0; i < 26; i++) {
        result *= powMod(factorial[cnt[i]], MOD - 2); result = (result + MOD) % MOD;
    }
    cout << result << '\n';
}

void DistributingApples() {
    ll N, M; cin >> N >> M;
    ll result = factorial[N + M - 1];
    ll inv = powMod(factorial[N - 1], MOD - 2) % MOD; inv = (inv + MOD) % MOD;
    inv *= powMod(factorial[M], MOD - 2) % MOD; inv = (inv + MOD) % MOD;
    result *= inv;
    result = (result+MOD)%MOD;
    cout << result << '\n';
}

void twoSets() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<int> l1;
    vector<int> l2;
    ll sum = (n + 1) * n / 2;
    if (sum % 2) {
        cout << "NO";
        return;
    }
    else {
        cout << "YES" << '\n';
    }

    int i = n;
    ll target = sum / 2;
    while (i) {
        if (i > target) {
            l2.push_back(i);
        }
        else {
            target -= i;
            l1.push_back(i);
        }
        i--;
    }

    cout << l1.size() << '\n';
    for (int x : l1) {
        cout << x << " ";
    }
    cout << '\n';
    cout << l2.size() << '\n';
    for (int x : l2) {
        cout << x << " ";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    init();
    examples();
}
