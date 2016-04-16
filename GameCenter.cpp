#include"Common.hpp"
#include"Screen.cpp"

using namespace std;

class GameCenter{
    private:
        Screen sc;
        vector<pair<pair<int,int>,Enemy> > enemyArmy;
        int enemy_cnt;
        Spaceship myship;
        //only one bullet
        Bullet mybullet;
    public:
        GameCenter():sc(38),myship('*'),enemy_cnt(0){
            myship.position = make_pair(30,0);
        }
        int get_enemy_number(){return enemy_cnt;}
        int add_enemy(Enemy&enemy,pair<int,int> pos){
            int ret(enemy_cnt);
            enemyArmy.push_back(make_pair(pos,enemy));
            enemy_cnt = enemyArmy.size();
            // return this enemy's ID
            return ret;
        }
        int set_enemy_pos(int eID,pair<int,int> epos){
            if(eID<0||eID>enemy_cnt)return -1;
            enemyArmy[eID].first = epos;
        }
        pair<int,int> get_mypos(){return myship.position;}
        int set_mypos(pair<int,int>newpos){myship.position = newpos;return 0;}
        int ship_fire(){
            myship.fire(mybullet);
            return 0;
        }
        int refresh(){
            // move objects
            if(mybullet.isvalid()==true){
                mybullet.move();
                if(mybullet.position.first<0)mybullet.valid_mark = false;
            }
			return 0;
        }
        int disp(){
            sc.fill();
            sc.draw_obj(myship.position,&myship);
            if(mybullet.isvalid()==true){
				sc.draw_obj(mybullet.getpos(),&mybullet);
            }

            // draw enemy
            for(int i = 0;i<enemy_cnt;i++){
                sc.draw_obj(enemyArmy[i].first,&enemyArmy[i].second);
            }
            sc.disp();
            return 0;
        }
};
