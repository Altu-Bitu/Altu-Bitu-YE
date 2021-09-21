//
// Created by 최예은 on 2021/09/20.
//

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<long long> v;
    long long sum=0;


    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    while(m--){
        sort(v.begin(),v.end());
        long long tmp=v[0]+v[1];
        v[0]=tmp;
        v[1]=tmp;
    }

    for(int i=0;i<n;i++)
        sum+=v[i];

    cout<<sum;


}