//
// Created by 최예은 on 2021/10/04.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int dp[3][1000] = { 0, };
int rgb[3][1000] = { 0, };

int main() {
    int n; //집 갯수
    cin>>n;

    for (int i = 0; i < n; i++)
        cin>>rgb[0][i]>>rgb[1][i]>>rgb[2][i];

    dp[0][0] = rgb[0][0];
    dp[1][0] = rgb[1][0];
    dp[2][0] = rgb[2][0];

    for (int i = 1; i < n; i++) {
        dp[0][i] = min({dp[1][i-1],dp[2][i-1]})+rgb[0][i]; //현재를 r로
        dp[1][i] = min({ dp[0][i - 1],dp[2][i - 1] }) + rgb[1][i]; //현재를 g로
        dp[2][i] = min({ dp[1][i - 1],dp[0][i - 1] }) + rgb[2][i]; //현재를 b로
    }
    cout<<min({ dp[0][n - 1],dp[1][n - 1] ,dp[2][n - 1] })<<'\n';

    return 0;
}