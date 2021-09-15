//
// Created by 최예은 on 2021/09/16.
//
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b){
    // 조건1. 자주 나온거 먼저
    if (a.second != b.second)
        return a.second >  b.second;
    // 조건2. 길이가 긴거 먼저
    if(a.first.length()!=b.first.length())
        return a.first.length() >  b.first.length();
    //사전순 앞단어
    return a.first <  b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,int> m;
    int N,M;
    cin>>N>>M;

    //길이가 M보다 큰 단어 저장
    while(N--){
        string str;
        cin>>str;
        if(str.length()>=M)
            m[str]++;
    }

    vector<pair<string,int>> v(m.begin(), m.end());

    sort(v.begin(),v.end(),cmp);

    for(auto it:v)
        cout<<it.first<<"\n";

}
