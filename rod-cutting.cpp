#include<bits/stdc++.h>
using namespace std;
int const N = 1e5;
int dp[N];

int MaxValue(int len, int prices[], int sz) {
    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans = 0;
    for(int i = 1; i <= sz; ++i) {
        if(len - i >= 0) {
            ans = max(ans, MaxValue(len - i, prices, sz) + prices[i-1]);
        }
    }
    dp[len] = ans;
    return dp[len];
} 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int length, PricesSize; cin >> length >> PricesSize;
    int prices[PricesSize];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < PricesSize; ++i) cin >> prices[i];
    cout << MaxValue(length, prices, PricesSize) << '\n';
    return 0;
}