#include <bits/stdc++.h>
using namespace std;
unordered_set<int> solve(int maxVal) {
    unordered_set<int> triset;
    if (maxVal < 0) return triset;
    int t1 = 0, t2 = 1, t3 = 1;
    triset.insert(t1);
    if (maxVal >= 1) {
        // hi
        triset.insert(t2);
        triset.insert(t3);
    }
    while (true) {
        int nxt = t1 + t2 + t3;
        if (nxt > maxVal) break;
        triset.insert(nxt);
        t1 = t2;
        t2 = t3;
        t3 = nxt;
    }
    cout<<"hello from thirdbranch"<<endl;
    return triset;
}
int tribo(vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxVal = *max_element(arr.begin(), arr.end());
    unordered_set<int> triset = solve(maxVal);
    int maxlen = 0;
    int cur = 0;
    for (int num : arr) {
        if (triset.find(num) != triset.end()) {
            cur++;
            maxlen = max(maxlen, cur);
        } else {
            cur = 0;
        }
    }
    return maxlen;
}
int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin>>arr[i];
    }
    int result = tribo(arr);
    cout<<result<< endl;

    return 0;
}
