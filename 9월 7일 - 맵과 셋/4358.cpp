//
// Created by 최예은 on 2021/09/13.
//

#include <iostream>
#include<cmath>
#include<map>
using namespace std;

int main(){
    map<string,int> m;
    int cnt=0;
    string str;

    while(getline(cin,str)){
        m[str]++;
        cnt++;
    }

    cout.precision(4);
    cout<<fixed;

    for(auto iter : m)
        cout<< iter.first<< ' '<< ((double)iter.second/cnt)*100<<endl;

}