//
// Created by 최예은 on 2021/09/13.
//

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    int ans;
    int cnt;
    cin >>n;

    map<string,int>m;
    string clothes, kind;

    //for(auto iter : m)

    while(n--){
        ans=1;
        cin >> cnt;
        while(cnt--) {
            cin >> clothes >> kind;
            m[kind]++;
        }
        for(auto iter: m)
            ans*= (iter.second+1);
        cout<< ans-1<<endl;

        m.clear();
    }

}
