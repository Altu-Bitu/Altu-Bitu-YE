//
// Created by 최예은 on 2021/09/30.
//
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int K;
char arr[11];
int Min[11], Max[11],visit[11],temp[11];

void func(int num,int cnt,int n) {
    if (cnt == K) {
        for (int i = 0; i < K + 1; i++) {
            if (Max[i] > temp[i]) break;
            if (Max[i] == temp[i]) continue;
            for (int i = 0; i < K + 1; i++)
                Max[i] = temp[i];
        }

        for (int i = 0; i < K + 1; i++) {
            if (Min[i] < temp[i]) break;
            if (Min[i] == temp[i]) continue;
            for (int i = 0; i < K + 1; i++)
                Min[i] = temp[i];
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!visit[i]) {
            visit[i] = 1;

            if (arr[n] == '<' && num < i)
                temp[cnt+1]=i, func(i, cnt + 1, n + 1);
            if (arr[n] == '>' && num > i)
                temp[cnt+1] = i, func(i, cnt + 1, n + 1);

            visit[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> arr[i];

    for (int i = 0; i < K + 1; i++)
        Min[i] = 9, Max[i] = 0;

    for (int i = 0; i < 10; i++)
        temp[0] = i, visit[i] = 1, func(i, 0, 0), visit[i] = 0;

    for (int i = 0; i < K + 1; i++)
        cout << Max[i];
    cout<<'\n';
    for (int i = 0; i < K + 1; i++)
        cout << Min[i];
}