//
// Created by 최예은 on 2021/10/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> c(n+1);
    vector<int> dp(k+1,99999);

    for(int i = 1; i <= n; i++)
        cin >>  c[i];
    sort(c.begin(), c.end());

    for(int i = 1; i < c.size(); i++)
        dp[c[i]] = 1;

    for(int i = 1; i < c.size(); i++) {
        for(int j = c[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    if(dp[k] == 99999)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';



    return 0;
}