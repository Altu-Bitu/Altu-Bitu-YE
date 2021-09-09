//
// Created by 최예은 on 2021/09/09.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,B,C;
    vector<int> student;
    long long ans=0;

    cin>>N;
    student.assign(N,0);

    for(int i=0;i<N;i++)
        cin >>student[i];

    cin>>B>>C;

    for (int i = 0; i < N; i++) {
        if (B >= student[i])
            ans++;
        else {
            int sub = (student[i] - B) / C;
            if ((student[i] - B) % C > 0)
                sub++;
            ans = ans + 1 + sub;
        }
    }
    cout << ans;
    return 0;




}
