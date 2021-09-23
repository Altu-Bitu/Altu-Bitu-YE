//
// Created by 최예은 on 2021/09/21.
//

//이항계수 1

#include<iostream>
#include<algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>>N>>K;

    int ans=0;
    int tmp1=1,tmp2=1;
    for(int i=N;i>N-K;i--)
        tmp1*=i;
    for(int j=K;j>0;j--)
        tmp2*=j;

    ans=tmp1/tmp2;
    cout<<ans;



}