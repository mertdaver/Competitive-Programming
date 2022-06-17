#include <bits/stdc++.h>

using namespace std;

const int inf = 2147483648;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    unordered_map<int,unordered_set<int>> m;
    for(int i = 0; i < n; i++){
        m[v[i]].insert(i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){continue;}
            auto it = m[x - v[i] - v[j]];
            if(it.size()){
                while(it.size() && (*it.begin() == i || (*it.begin()) == j)){
                    it.erase(it.begin());
                }
                if(it.size()){
                    cout << i + 1 << " " << j + 1 << " " << (*it.begin()) + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}











    /*set<int> s;
    map<int,int> m;
    for(int i = 0; i < n; i++){
        s.insert(v[i]);
        m[v[i]] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i){continue;}
            auto it = s.find(x - v[i] - v[j]);
            if(it != s.end()){
                int idx = m[*it];
                if(idx != i && idx != j){
                    cout << i + 1 << " " << j + 1 << " " << idx + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';*/