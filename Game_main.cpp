#include"Common.hpp"
#include"Screen.cpp"
#include"Enemy.cpp"

using namespace std;


void escort_enemy(){
    
    Enemy ene(3,5);
    //draw Enemy
    sc.draw_enemy(make_pair(2,9),ene);
    sc.disp();
}

int main(){
    Screen sc(38);
    sc.draw_test();


return 0;}
