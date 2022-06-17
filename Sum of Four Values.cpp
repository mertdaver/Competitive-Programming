#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int n,x; cin >> n >> x;
    vector<int> v(n);
    vector<pair<int,pair<int,int>>> arr;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            arr.push_back({v[i] + v[j],{i,j}});
        }
    }
    sort(arr.begin(),arr.end());
    int l,r; l = 0; r = arr.size();
    while(l < r){
        if(arr[l] + arr[r] == x){
            if(arr[l].second.first != arr[r].second.first && arr[l].second.first != arr[r].second.second && arr[l].second.second != arr[r].second.first && arr[l].second.second != arr[r].second.second){
                cout << arr[l].second.first + 1 << " " << arr[l].second.second + 1 << " " << arr[r].second.first + 1 << " " << arr[r].second.second + 1;
                return 0;
            }
            else{
                if(arr[l].second.first == arr[r].second.first || arr[l].second.first == arr[r].second.second){
                    l++;
                }
                else{
                    r++;
                }
            }
        }
        if(arr[l] + arr[r] > x){
            r--;
        }
        if(arr[l] + arr[r] < x){
            l++;
        }
    }
    cout << "IMPOSSIBLE";
}