#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,t; cin >> n >> t;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long ans = 1;
    long long l,r; l = 0; r = (long long)pow(10,18);
    while(l < r){
        ans = (l + r)/2;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(sum <= pow(10,9)){
                sum += ans / v[i];
            }
            else{
                break;
            }
        }
        if(sum >= t){
            r = ans;
        }
        if(sum < t){
            l = ans + 1;
        }
    }
    cout << (l + r)/2 << '\n';
}
