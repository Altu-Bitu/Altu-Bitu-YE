//
// Created by 최예은 on 2021/10/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, a, b;
    int result = 0;
    cin >> N;

    vector<pair<int, int>> v;
    v.emplace_back(0, 0);
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    //오름차순 정렬
    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) {
                if (dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        result = max(result, dp[i]);
    }

    cout << N - result;
    return 0;
}