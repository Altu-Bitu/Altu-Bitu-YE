//
// Created by 최예은 on 2021/09/13.
//

#include <iostream>
#include<cmath>


using namespace std;
int W,I,T;
int day,diet_I,A;
int minus_W=0;
int BMR; //기초대사량
bool danger=false;

void printFunc(){
    cout<<W+minus_W<<' '<<BMR<<' ';
}

void bmrNoChange(){
    minus_W=(diet_I-(BMR+A))*day;

    if(abs(minus_W)>=W){
        cout<<"Danger Diet";
        danger=true;
    }

}

void bmrChange(){
    minus_W=0;
    danger=false;
    while(day--){

        minus_W+=(diet_I-(BMR+A));

        int x=diet_I-(BMR+A);
        if (abs(x) > T) {
            if (x < 0 && x % 2 != 0) //음수 계산 - 홀수인 음수
                BMR += (x / 2) - 1;
            else
                BMR += (x / 2);
        }

        //BMR+=floor((diet_I-(BMR+A))/2);

        if(abs(minus_W)>=W || BMR<=0){
            cout<<"Danger Diet";
            danger=true;
            break;
        }


    }

}

int main(){
    cin>>W>>I>>T;
    cin>>day>>diet_I>>A;
    BMR=I;

//    1) 기초 대사량 변화를 고려하지 않을 때 출력
    bmrNoChange();
    if(!danger)
        printFunc();

    cout<<endl;

//    2) 기초 대사량 변화 고려시 출력
    bmrChange();
    if(!danger){
        printFunc();

        if(I>BMR)
            cout<<"YOYO";
        else
            cout<<"NO";
    }

}
