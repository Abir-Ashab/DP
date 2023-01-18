#include <bits/stdc++.h>
using namespace std;
int const MAX = 1005;
int l, n;
int a[MAX];
int track[MAX][MAX];

int CuttingCost(int start, int finish) {
    if (track[start][finish] != -1)
        return track[start][finish];

    bool flag = false;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= start or a[i] >= finish)
            continue;

        flag = true;
        int ans1 = finish - start;
        int ans2 = CuttingCost(start, a[i]) + CuttingCost(a[i], finish);
        ans = min(ans, ans1 + ans2);
    }

    if (!flag)
        track[start][finish] = 0;
    else
        track[start][finish] = ans;
    return track[start][finish];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    memset(track, -1, sizeof(track));

    cout << "Minimum cutting cost is: " << CuttingCost(0, l) << endl;

    return 0;
}