//
// Created by 최예은 on 2021/09/13.
//

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2, ans;
    int carry = 0;

    cin >> s1 >> s2;

    //길이 더 긴거에 맞춰서 0 채워넣기
    if (s1.size() > s2.size()){
        string s;
        for (int i = 0; i < s1.size() - s2.size(); i++)
            s += '0';
        s2 = s + s2;
    }

    else{
        string s;
        for (int i = 0; i < s2.size() - s1.size(); i++)
            s += '0';
        s1 = s + s1;
    }

    while (s1.size() != 0 && s2.size() != 0){
        int tmp_a = s1.back() - '0';
        int tmp_b = s2.back() - '0';
        int remain = (carry + tmp_a + tmp_b) % 10;
        carry = (carry + tmp_a + tmp_b) / 10;
        ans = (char)(remain + '0') + ans;
        s1.pop_back();
        s2.pop_back();
    }

    if(carry > 0)
        ans = (char)(carry + '0') + ans;

    cout << ans << endl;
    return 0;
}
