#include <iostream>
#include <random>
#include <cstdio>
using namespace std;
int diceroll(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1,6);

    int random_no = dis(gen);
    return random_no;
}

int ladder(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(5,15);

    int random_no = dis(gen);
    return random_no;
}

int snake(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(15,20);

    int random_no = dis(gen);
    return random_no;
}

int main() {
    int positionplayer1=0,positionplayer2=0;
    int turn;

    cout<<"*****WELCOME TO SNAKE AND LADDER GAME*****"<<endl<<endl;
    while(positionplayer1 <= 100  && positionplayer2 <= 100 ){

        cout<<endl<<"Player 1: Enter to roll the dice";

        int ladders[] = {2,11,12,22,36,41,46,70,77,85};
        int snakes[] = {21,23,29,35,47,52,71,82,95,99};
        while (getchar() != '\n') {

        }

        turn = diceroll();
        positionplayer1=positionplayer1+turn;
        cout<<"Dice has been rolled:"<<turn<<endl;
        cout<<"Player 1 has advanced to Position:"<<positionplayer1<<endl;
        for(int i = 0 ; i <= 9;i++){
            if(positionplayer1==ladders[i]){
                positionplayer1=positionplayer1+ladder();
                cout<<"Player 1 has taken a ladder and is on Position:"<<positionplayer1<<endl;
            }
            if(positionplayer1==snakes[i]){
                positionplayer1=positionplayer1-snake();
                cout<<"Player 1 has been bitten by a snake and is on Position:"<<positionplayer1<<endl;
            }
        }

        if(positionplayer1 >= 100){
            cout<<"Player 1 won the game"<<endl;
            break;
        }
        //player 2
        cout<<endl<<endl;
        cout<<"Player 2: Enter to roll the dice";
        while (getchar() != '\n') {
        }
        turn = diceroll();
        positionplayer2=positionplayer2+turn;
        cout<<"Dice has been rolled:"<<turn<<endl;
        cout<<"Player 2 has advanced to Position:"<<positionplayer2<<endl;
        for(int i = 0 ; i <= 9;i++){
            if(positionplayer2==ladders[i]){
                positionplayer2=positionplayer2+ladder();
                cout<<"Player 2 has taken a ladder of and is on Position:"<<positionplayer2<<endl;
            }
            if(positionplayer2==snakes[i]){
                positionplayer2=positionplayer2-snake();
                cout<<"Player 2 has been bitten by a snake and is on Position:"<<positionplayer2<<endl;
            }
        }
        if(positionplayer2 >= 100){
            cout<<"Player 2 won the game"<<endl;
            break;
        }
    }

    return 0;
}
