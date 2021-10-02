//
// Created by 최예은 on 2021/09/30.
//

#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>


using namespace std;
int check[7];

void backtracking(int cnt,int m,set<int> &s) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++)
            cout << check[i] << ' ';
        cout << '\n';
        return;
    }

    for (auto iter : s) {
        check[cnt] = iter;
        backtracking(cnt + 1,m,s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    set<int> s;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        s.insert(a);
    }
    backtracking(0,m,s);
}