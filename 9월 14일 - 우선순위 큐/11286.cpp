//
// Created by 최예은 on 2021/09/20.
//

#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    //first를 기준으로 오름차순 정렬되고 만약 first가 같으면 second가 작은게 먼저 출력됨 (greater라서 오름차순)
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

    while(N--){
        int num;
        cin>>num;

        if(num!=0)
            pq.push({abs(num),num});

        else
            //배열이 비었으면 0 출력
            if(pq.empty())
                cout<<0<<'\n';
                //아니면 젤 앞에 값 출력
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
    }
}