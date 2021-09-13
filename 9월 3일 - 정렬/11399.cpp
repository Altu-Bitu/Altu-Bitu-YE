//
// Created by 최예은 on 2021/09/09.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int tmp=0;
    int time=0;
    vector<int> arr;

    cin>>N;

    arr.assign(N,0);

    for(int i=0;i<N;i++)
        cin >>arr[i];

    sort(arr.begin(),arr.end());

    for(int i=0;i<N;i++){
        tmp+=arr[i];
        time+=tmp;
    }
    cout<<time;


}
