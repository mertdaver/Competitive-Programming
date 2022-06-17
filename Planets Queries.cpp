#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//vector<vector<int>> g;
int g[200005][31];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	//g.resize(n + 1,vector<int>(31));
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i][0];
	}
	for (int k = 1; k <= 30; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			g[i][k] = g[g[i][k - 1]][k - 1];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int x, k; cin >> x >> k;
		int pos = x;
		for (int p2 = 536870912, i = 29; p2; p2 >>= 1, i--) {
			if (k >= p2) {
				k -= p2;
				pos = g[pos][i];
			}
		}
		cout << pos << '\n';
	}
}