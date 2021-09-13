//
// Created by 최예은 on 2021/09/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findGroup(int n){
    int cnt=0;
    string s;
    bool arr[26]={false};


    while(n--){
        bool check=true;
        cin>>s;
        for(int i=0;i<s.length();i++) {
            if (i != 0 && s[i] == s[i - 1])
                continue;
            if (arr[s[i] - 'a']) {
                check = false;
                break;
            }
            arr[s[i] - 'a'] = true;
        }

        fill_n(arr,26,false);
        if(check)
            cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    cout<< findGroup(n);

}

