//
// Created by 최예은 on 2021/09/09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int ans=0;
    vector<int> A,B;

    cin>>N;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i++){
        int b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());

    for(int i=0;i<N;i++)
        ans+=A[i]*B[i];

    cout<<ans;


}
