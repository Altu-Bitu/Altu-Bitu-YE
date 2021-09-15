//
// Created by 최예은 on 2021/09/16.
//

#include <iostream>
#include <stack>

using namespace std;

int main(){

    int N;
    string str;
    int alphabet[26];
    stack<double> s;

    cin >> N;
    cin >> str;

    for (int i = 0; i < N; i++)
        cin >> alphabet[i];

    for (int i = 0; i < str.length(); i++){
        // 스택에 연산자가 들어오면 값 두개 꺼내서 계산하고 계산한 값 다시 넣음

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            switch (str[i]){
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;

                case '*':
                    s.push(b * a);
                    break;

                case '/':
                    s.push(b / a);
                    break;
            }

        }
        else
            s.push(alphabet[str[i] - 'A']);
    }

    double ans = s.top();

    cout << fixed;
    cout.precision(2);
    cout << ans << endl;

}