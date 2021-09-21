//
// Created by 최예은 on 2021/09/21.
//

//골드바흐의 추측

#include<iostream>
#include<algorithm>
#include <vector>
#include <cmath>


using namespace std;
vector<bool> is_prime(1000001,true);

void isPrime(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=sqrt(1000000);i++){
        if(is_prime[i]){
            for(int j=i*i;j<=1000000;j+=i)
                is_prime[j]=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    isPrime();

    while(1){
        bool check=false;
        cin>>n;

        if(n==0)
            return 0;
        for(int i=0;i<1000001;i++){
            if(is_prime[i] && is_prime[n - i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
                check=true;
                break;
            }
        }
        if(!check)
            cout<< "Goldbach's conjecture is wrong."<<'\n';

    }

}