#include"Common.hpp"
#include"Screen.cpp"
#include"Enemy.cpp"

using namespace std;


void escort_enemy(Screen&sc){
    
    Enemy ene(3,5);
    Spaceship ship('*');
    //draw Enemy
    int xpos(0);
    int xgain(1);
    while(1){
        sc.fill();
        sc.draw_obj(make_pair(2,xpos),&ene);
        sc.draw_obj(make_pair(20,xpos),&ship);
        sc.disp();
        xpos+=xgain;
        if(xpos>=80)xgain = -1;
        else if(xpos<=0)xgain = 1;
        Sleep(10);
    }
}

void maneuver_ship(Screen&sc){
    Spaceship ship('*');
    int xpos(0);
    int xgain(1);
    while(1){
        sc.fill();
        sc.draw_obj(make_pair(20,xpos),&ship);
        sc.disp();

        char ch = getch();
        if(ch=='h'||ch=='H'){xpos--;}
        else if(ch=='l'||ch=='L')xpos++;
        if(xpos<=0)xpos = 0;
        else if(xpos>=80)xpos = 80;
    }

}

int main(){
    Screen sc(38);
    sc.draw_test();

    maneuver_ship(sc);
    //escort_enemy(sc);

return 0;}
