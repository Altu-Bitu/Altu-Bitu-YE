//
// Created by 최예은 on 2021/09/20.
//

#include<iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    bool cpp = false, java = false, err = false;
    string result;

    for (int i = 0; i < str.length(); i++){
        if (isupper(str[i])){ // 대문자 일떄
            if (!i || cpp){ //근데 첫글자가 대문자이거나 cpp일때
                err = true;
                break;
            }
            result += '_';
            result += tolower(str[i]);
            java = true; //java 단어로 판별
        }

        else if (str[i] == '_'){
            //첫글자가 _ , 끝이 _ , 자바로 판별 됐는데(대문자 나왔는데) _도 나왔거나, 연ㄴ속되서 _ 나오거나, _다음에 대문자 나올때
            if (!i || java || i == str.length() - 1 || str[i + 1] == '_' || isupper(str[i + 1])){
                err = true;
                break;
            }
            result += toupper(str[i + 1] );
            i++;
            cpp = true;
        }

        //소문자면 그냥 넣기
        else
            result += str[i];
    }

    if (err)
        cout << "Error!\n";
    else
        cout << result << '\n';

}