#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int N, M;
vector<int> son;
vector<bool> done;
vector<int> cyc;
vector<int> dist;

int dfs(int v){
    if (done[v]) {
        if (!dist[v]) {
            for (int u = son[v];; u = son[u]) {
                cyc.push_back(u);
                if (u == v)break;
            }
            for (int i = 0; i < cyc.size(); i++) {
                dist[cyc[i]] = cyc.size();
            }
        }
        cyc.clear();
        return dist[v];
    }
    done[v] = 1;
    int val = dfs(son[v]) + 1;
    if (!dist[v])dist[v] = val;
    return dist[v];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    son.resize(N + 1);
    done.resize(N + 1);
    dist.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int b; cin >> b;
        son[i] = b;
    }
    for (int i = 1; i <= N; i++)
        cout << dfs(i) << " ";
}
