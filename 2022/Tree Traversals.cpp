#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define PB push_back

vector<int> pre;
vector<int> in;
vector<int> idxs;
vector<int> par;
vector<vector<int>> sons;

void recursion(int p, int l, int r, int sub1, bool lor){ //p - parent, l & r - the part of the pre vector we r looking at, sub1 - what we need to subtract
    if (l > r)return; //p = 1, l = 1, r = 3, sub1 = 0
    if(p!=pre[l])sons[p][lor] = pre[l];
    if (l == r)return;
    int sz1; //left subtree size, pre
    sz1 = idxs[pre[l]] - sub1;
    int sz2; //right subtree size, pre
    sz2 = r-l-sz1;
    //left subtree :    
    recursion(pre[l], l + 1, l + sz1, sub1,0);
    //right subtree :
    recursion(pre[l], l + 1 + sz1, r, idxs[pre[l]]+1,1);
}

void dfs(int v) {
    if (v == -1)return;
    dfs(sons[v][0]);
    dfs(sons[v][1]);
    cout << v << " ";
}

int main()
{
    fast;
    cin >> N;
    idxs.resize(N + 1);
    par.resize(N + 1);
    sons.resize(N + 1,vector<int>(2,-1));
    loop(i, N) {
        int t; cin >> t;
        pre.PB(t);
    }
    loop(i, N) {
        int t; cin >> t;
        idxs[t] = i;
        in.PB(t);
    }
    recursion(pre[0], 0, N - 1, 0,0);
    dfs(pre[0]);
}
