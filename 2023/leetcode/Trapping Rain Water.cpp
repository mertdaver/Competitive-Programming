#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
    int N = height.size();
    vector<int> prefix(N);
    vector<int> suffix(N);
    stack<int> mono;

    prefix[0] = height[0];
    suffix[N - 1] = height[N - 1];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + height[i];
    }
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + height[i];
    }

    mono.push(0);
    for (int i = 1; i < N; i++) {
        if (height[mono.top()] > height[i]) continue;
        mono.push(i);
    }
    int result = 0;
    int last = mono.top();
    int maxIdx = last;
    mono.pop();
    while (!mono.empty()) {
        int i = mono.top(); mono.pop();
        int width = last - i - 1;
        result += width * height[i] - (prefix[last - 1] - prefix[i]);
        last = i;
    }
    mono.push(N - 1);
    for (int i = N - 2; i >= maxIdx; i--) {
        if (height[mono.top()] > height[i]) continue;
        mono.push(i);
    }
    last = mono.top();
    mono.pop();
    while (!mono.empty()) {
        int i = mono.top(); mono.pop();
        int width = i - last - 1;
        result += width * height[i] - (suffix[last+1] - suffix[i]);
        last = i;
    }
    return result;
}

int main()
{
    vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int result = trap(v);
    cout << result;
}
