//
// Created by 최예은 on 2021/09/09.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b){
    int sum_a=0;
    int sum_b=0;

    // 조건1. 길이가 짧은거 먼저
    if (a.length() != b.length())
        return a.length() <  b.length();

    // 조건2. 숫자만 더해서 합이 작은게 먼저
    for(int i=0;i<a.length();i++){
        if(a.at(i)-'0'<=9)
            sum_a+=a.at(i)-'0';
        if(b.at(i)-'0'<=9)
            sum_b+=b.at(i)-'0';
    }
    if (sum_a != sum_b)
        return sum_a < sum_b;

    // 조건 3. 사전순. (숫자먼저)
    return a < b;
}

int main(){
    int N;
    vector<string> serial;

    cin >>N;
    serial.assign(N,{});
    for(int i=0;i<N;i++)
        cin >> serial[i];

    //연산
    sort(serial.begin(), serial.end(), cmp);

    //출력
    for (int i = 0; i < N; i++)
        cout << serial[i] << '\n';

}