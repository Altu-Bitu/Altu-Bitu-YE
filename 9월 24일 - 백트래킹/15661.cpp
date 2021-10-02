//
// Created by 최예은 on 2021/09/30.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;
int n;
int S[21][21];
bool check[21];
int ans=INT_MAX;

void func(int start){
    if(start>=n){
        int start=0,link=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(check[i]&&check[j])
                    start+=S[i][j];
                else if(!check[i]&&!check[j])
                    link+=S[i][j];
            }
        }
        if(ans>abs(start-link))
            ans=abs(start-link);
    }

    for(int i=start;i<=n;i++){
        if(!check[i]){
            check[i]=true;
            func(i);
            check[i]=false;
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> S[i][j];
        }
    }
    func(1);
    cout<< ans <<'\n';
}