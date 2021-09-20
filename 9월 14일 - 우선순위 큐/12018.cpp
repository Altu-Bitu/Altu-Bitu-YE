//
// Created by 최예은 on 2021/09/20.
//

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //과목수, 총 주어진 마일리지
    int n,m;
    cin>>n>>m;
    vector<int> need_v; //성준이한테 필요한 마일리지
    int sum=0;

    for(int i=0;i<n;i++){
        //신청자 수, 수강정원
        int p,l;
        cin>>p>>l;

        vector<int> v;

        //신청자들의 마일리지 입력
        for(int j=0;j<p;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }

        if(p>=l){
            int index=p-l;
            sort(v.begin(),v.end());
            need_v.push_back(v[index]);

        }
        else
            need_v.push_back(1);

    }
    //need_v 다 채워지면 오름차순 정렬 한 후 주어진 총 마일리지 안에서 들을 수 있는 최대 과목 수 계산
    sort(need_v.begin(), need_v.end());

    int cnt=0;//들을 수 있는 최대 과목 수
    while(n--){
        if(m-sum >= need_v[cnt]) {
            sum += need_v[cnt];
            cnt++;
        }
        else
            break;
    }
    cout<<cnt;
}