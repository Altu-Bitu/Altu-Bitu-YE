//
// Created by 최예은 on 2021/09/27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n);
    int arr[8001]={0}; //최빈값을 위한 빈도수 배열
    int sum=0;
    int idx;
    int mode_max=0;
    bool flag=false;

    //값 저장
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        idx = v[i] <= 0 ? abs(v[i]) : v[i] + 4000;
        arr[idx]++;
        if(mode_max<arr[idx])
            mode_max=arr[idx];
    }

    sort(v.begin(),v.end());

    int avg, mid, mode, range;
    int mid_idx=round(n/2);

    //평균
    cout << fixed;
    cout.precision(0);
    avg=round((double)sum/n);
    //중앙값
    mid=v[mid_idx];
    //범위
    range=v[n-1]-v[0];

    //최빈값
    for(int i = -4000; i < 4001; i++){
        int tmp = i <= 0 ? abs(i) : i+4000;
        if(arr[tmp] == mode_max){
            mode = i;
            if(flag) //최빈값이 두개이상일때 반복문 탈출
                break;
            flag = true;
        }
    }
    cout<<avg<<'\n'<<mid<<'\n'<<mode<<'\n'<<range<<'\n';
    return 0;

}