class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> inv(n);

        for(int i = 0; i < n; i++){
            inv[i] = i;
            for(int j = n-1; j > i; j--){
                if (arr[i] > arr[j]){
                    inv[i] = j;
                    break;
                }
            }
        }
        
        int result = 0;
        int far = inv[0];

        for(int i = 0; i < n; i++){
            far = max(far,inv[i]);
            if(far == i)result++;
        }

        return result;
    }
};
