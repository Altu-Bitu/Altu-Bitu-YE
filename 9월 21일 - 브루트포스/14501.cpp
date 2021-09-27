//
// Created by 최예은 on 2021/09/27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;
int max_pay;

void maxProfit(int idx,int pay,int n,vector<pair<int,int>>& v) {
    //idx날 일할 수 있어야 함.(마지막날 까지 일할 수 있는 경우는 idx가 n-1이고 그날 하루만 일하면 될때)
    if (idx + v[idx].first < n || (idx == n - 1 && v[idx].first == 1)) {
        pay += v[idx].second;
        idx = idx + v[idx].first; //일할 다음날
        maxProfit(idx, pay, n, v);
    }
    if (max_pay < pay)
        max_pay = pay;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<pair<int,int>> v;

    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }


    for(int i=0;i<n;i++){
        //cout<<i<<"번째 날은 꼭 일함"<<'\n';
        //cout<<max_pay<<'\n';
        maxProfit(i,0,n,v);
    }
    cout<<max_pay;

}