//
// Created by 최예은 on 2021/09/19.
//

#include<iostream>
#include <cstring>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool S[21] ={false};
    int M;
    cin>>M;
    cin.ignore();
    while(M--){

        string s;
        getline(cin,s);
        string method;
        int index;
        int n;

        if(s=="all") {
            //cout << "all" << '\n';
            memset(S, true, sizeof(S));
        }

        else if(s=="empty")
            memset(S, false, sizeof(S));

        else {
            index = s.find(' ');
            method = s.substr(0, index);
            n = stoi(s.substr(index + 1, s.length()));


            if (method == "add")
                S[n] = true;
            else if (method == "remove")
                S[n] = false;
            else if (method == "check") {
                if (S[n] == true)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
                //toggle
            else {
                if (S[n] == true)
                    S[n] = false;
                else
                    S[n] = true;
            }
        }
    }
}