//
// Created by 최예은 on 2021/09/20.
//

#include<iostream>
#include<stack>
#include<algorithm>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    int cnt = 0;
    stack<int> s[7];


    //줄마다 스택 만들고,
    // push 할떄마다 cnt++,


    while(n--) {
        int str_num, fret_num;
        cin >> str_num >> fret_num;

        if (s[str_num].empty()) {
            s[str_num].push(fret_num);
            cnt++;
        }
        else {
            // 더 작은 플랫이 들어오면 스택 안에 플랫이 같거나 더 작아지기 전까지 pop(cnt++)한 다음 push(cnt++)
            if (s[str_num].top() > fret_num) {
                while (!s[str_num].empty() && s[str_num].top() > fret_num) {
                    s[str_num].pop();
                    cnt++;
                }

                //같은 경우엔 푸시하지 않음
                if (!s[str_num].empty() && s[str_num].top() == fret_num)
                    continue;

                s[str_num].push(fret_num);
                cnt++;
            }
            //더 큰 플랫이 들어오면 푸시해줌
            else if (s[str_num].top() < fret_num) {
                s[str_num].push(fret_num);
                cnt++;
            }

        }
    }

    cout << cnt;
    return 0;

}
