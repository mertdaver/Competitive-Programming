class Solution {
public:
    int N;
    vector<int> group;
    vector<int> sz;

    int findSet(int v){
        if(v==group[v]) return v;
        return v = findSet(group[v]);
    }

    void unite(int v, int u){
        v = findSet(v); u = findSet(u);
        if(v == u) return;
        if(sz[v] < sz[u]){
            swap(v,u);
        }
        sz[v] += sz[u];
        group[u] = v;
    }

    void similarityCheck(int i, int j,vector<string>& strs){
        string s1 = strs[i];
        string s2 = strs[j];
        if(s1.size() != s2.size()) return;
        int M = s1.size();
        vector<int> mistakes; //how many differences & locations.
        for(int i = 0; i < M; i++){
            if(s1[i] != s2[i]){
                mistakes.push_back(i);
            }
        }
        if(mistakes.size() == 0){
            unite(i,j);
        }
        if(mistakes.size()==2){
            if(s1[mistakes[0]]==s2[mistakes[1]]&&s1[mistakes[1]]==s2[mistakes[0]]){
                unite(i,j);
            }
        }
        mistakes.clear();
    }

    int numSimilarGroups(vector<string>& strs) {
        N = strs.size();
        group.resize(N);
        sz.resize(N,1);
        for(int i = 0; i < N; i++){
            group[i] = i;
        }
        for(int i = 0; i < N; i++){
            for(int j = i+1; j< N; j++){
                similarityCheck(i,j,strs);
            }
        }
        set<int> seen;
        for(int i = 0; i < N; i++){
            group[i] = findSet(i);
            seen.insert(group[i]);
        }
        int result = seen.size();
        return result;
    }
};

//Algorithm:
//We'll use dsu in this algorithm.
//Each string represnts a group of his own.
//Then, we'll iterate over all pairs (O(n^2))
//Let's say we are currently at pair (i,j)
//If s[i] ~ s[j], then we connect group[i] & group[j]
//At the end of all iterations, number of groups is decided.
