#include"Common.hpp"
#include"Screen.cpp"
#include"Enemy.cpp"
#include"GameCenter.cpp"

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
GameCenter *game;
// with Game
void escort_game(){
    
    Enemy ene(3,5);
    pair<int,int>epos(0,0);
    int eID = game->add_enemy(ene,epos);
    int xpos(0),xgain(1);
    while(1){
        game->set_enemy_pos(eID,epos);
        game->refresh();
        game->disp();
        xpos+=xgain;
        if(xpos>=80)xgain = -1;
        else if(xpos<=0)xgain = 1;
        Sleep(10);
        epos.second = xpos;
    }
}

void maneuver_game(){
    int xpos(0);
    while(1){
        game->set_mypos(make_pair(30,xpos));

        char ch = _getch();
        if(ch=='h'||ch=='H'){xpos-=4;}
        else if(ch=='l'||ch=='L')xpos+=4;
        else if(ch==' ')game->ship_fire();
        if(xpos<=0)xpos = 0;
        else if(xpos>=80)xpos = 80;
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

        char ch = _getch();
        if(ch=='h'||ch=='H'){xpos--;}
        else if(ch=='l'||ch=='L')xpos++;
        if(xpos<=0)xpos = 0;
        else if(xpos>=80)xpos = 80;
    }

}

int main(){
    game = new GameCenter();
    std::thread th1(escort_game);
    maneuver_game();
    th1.join();
    //maneuver_ship(sc);
    //escort_enemy(sc);

return 0;}
