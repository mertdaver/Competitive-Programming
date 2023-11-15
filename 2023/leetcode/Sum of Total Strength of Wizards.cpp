#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int totalStrength(vector<int>& strength) {
    int n = strength.size();
    int MOD = 1e9 + 7;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    set<int> smallLeft;
    set<int> smallRight;

    vector<int> LR(n,0); //Left to Right
    vector<int> RL(n, 0); //Right To left

    //prefixes of LR,RL
    vector<int> prefLR(n, 0); 
    vector<int> prefRL(n, 0);

    LR[0] = strength[0]; prefLR[0] = LR[0];
    RL[n - 1] = strength[n - 1]; prefRL[n - 1] = RL[n - 1];


    pq.push({ strength[0],0 });

    for (int i = 1; i < n; i++) {
        pq.push({ strength[i],i });

        LR[i] = (LR[i - 1] + strength[i])%MOD;
        RL[n - 1 - i] = (RL[n - i] + strength[n - 1 - i])%MOD;

        prefLR[i] = (prefLR[i - 1] + LR[i])%MOD;
        prefRL[n - i - 1] = (prefRL[n - i] + RL[n - i - 1])%MOD;
    }

    long long result = 0;

    //MODULOOOOO

    while (!pq.empty()) {
        long long i = pq.top().second; pq.pop();

        long long j1, j2;
        auto it1 = smallLeft.lower_bound(-i);
        auto it2 = smallRight.lower_bound(i);
        if (it1 == smallLeft.end()) {
            j1 = 0;
        }
        else {
            j1 = -(*it1) + 1;
        }
        if (it2 == smallRight.end()) {
            j2 = n - 1;
        }
        else {
            j2 = (*it2) - 1;
        }

        long long Lallseq = (prefRL[j1] - prefRL[i] - (i - j1) * RL[i])%MOD;
        long long Rallseq = (prefLR[j2] - prefLR[i] - (j2 - i) * LR[i])%MOD;

        result += ((((i - j1 + 1) * Rallseq)%MOD) * strength[i])%MOD;
        result %= MOD;
        result += ((((j2 - i + 1) * Lallseq)%MOD) * strength[i])%MOD;
        result %= MOD;

        long long iSum = (i - j1 + 1) * (j2 - i + 1) * strength[i];
        iSum %= MOD;
        iSum *= strength[i];
        iSum %= MOD;

        result += iSum;
        result %= MOD;
        
        smallLeft.insert(-i);
        smallRight.insert(i);
    }
    
    return result % MOD;
}
