//
// Created by 최예은 on 2021/09/13.
//

#include<iostream>
#include<map>
#include <set>

using namespace std;

int main(){
    int N,M;
    map<string,int> m;
    cin>>N>>M;

    int time=N+M;
    set<string> s;

    while(time--){
        string str;
        cin>>str;
        m[str]++;
    }
    for(auto iter:m){
        if(iter.second==2)
            s.insert(iter.first);
    }

    cout<<s.size()<<endl;
    for(auto iter:s){
        cout<<iter<<endl;
    }


}