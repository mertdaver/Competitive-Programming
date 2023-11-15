#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
int ans[200005][2]; 
int dict[200005][2]; //dict[i][0] -> Ai, dict[i][1] = Bi
int done[200005];
//pair<int,int> backup[200005]; 
typedef tree<tuple<int,int,int>,null_type,less<tuple<int,int,int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ordered_set start;
    ordered_set over;
    ordered_set s;
    ordered_set o;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        start.insert({a,a - b,i});
        over.insert({b,b - a,i});
        o.insert({b,b - a,i});
        dict[i][0] = a;
        dict[i][1] = b;
    }
    auto it = start.begin();
    while(it != start.end()){
        int val,len,idx;
        tie(val,len,idx) = *it;
        ans[idx][0] = over.order_of_key({dict[idx][1],-len,idx});
        over.erase({dict[idx][1],-len,idx});
        it++;
    }
    it = o.begin();
    while(it != o.end()){
        int val,len,idx;
        tie(val,len,idx) = *it;
        ans[idx][1] = start.order_of_key({dict[idx][0],-len,idx});
        start.erase({dict[idx][0],-len,idx});
        it++;
    }
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            cout << ans[i][j] << " ";
        }
        cout <<'\n';
    }
}
