#pragma once
#include"Common.hpp"
using namespace std;
//declearation
class Screen_object_base;
class Enemy;
class Spaceship;

#ifndef EnemyClassDEF
#define EnemyClassDEF
class Screen_object_base{
    public:
        pair<int,int> BoxSize;
        vector<string>shape;
    public:
        pair<int,int> position;
        pair<int,int> velocity;
        Screen_object_base():BoxSize(make_pair(0,0)),position(make_pair(0,0)),velocity(make_pair(0,0)){}
        Screen_object_base(const vector<string>&shape_in):shape(shape_in){
            // get BoxSize
            BoxSize.first = shape.size();
            int mlen(0);
            for(auto str:shape)mlen = max(mlen,(int)str.size());
            BoxSize.second = mlen;
        }
};
class Bullet:public Screen_object_base{
    private:
        bool valid_mark;
    public:
        //friend class Screen;
        // default shape
        friend class GameCenter;
        friend class Spaceship;

        Bullet():Screen_object_base(),valid_mark(false){
            BoxSize = make_pair(2,4);
            shape.push_back("@@@@");
            shape.push_back("@@@@");
        }
        pair<int,int> getBoxSize(){return this->BoxSize;}
        pair<int,int> getpos(){return position;}
        pair<int,int> getvel(){return velocity;}
        bool isvalid(){return valid_mark;}
        int move(){
            //move according to velocity

            position.first += velocity.first;
            position.second += velocity.second;
            return 0;
        }
        //=======================================
        //public interface
        //=======================================
        int debug_output(){
            for(int i = 0;i<BoxSize.first;i++){
                cout<<shape[i]<<endl;
            }

        }
};
class Enemy:public Screen_object_base{
    public:
        //friend class Screen;
        // default shape
        Enemy(int h = 3,int w = 3,char mark = '#'){
            this->BoxSize = make_pair(h,w);
            for(int i = 0;i<BoxSize.first;i++){
                string line(BoxSize.second,' ');
                for(int j = 0;j<BoxSize.second;j++){
                    if(j==BoxSize.second/2)line[j] = mark;
                    else if(i==BoxSize.first/2)line[j] = mark;
                }
                this->shape.push_back(line);
            }
            
        }
        pair<int,int> getBoxSize(){return this->BoxSize;}
        //=======================================
        //public interface
        //=======================================
        int debug_output(){
            for(int i = 0;i<BoxSize.first;i++){
                cout<<shape[i]<<endl;
            }

        }
};
class Spaceship:public Screen_object_base{
    public:
        //friend class Screen;
        // default shape
        Spaceship(char mark = '#'){
            this->BoxSize = make_pair(3,5);
            this->shape.push_back("  "+string(1,mark)+"  ");
            this->shape.push_back(" "+string(3,mark)+" ");
            this->shape.push_back(string(1,mark)+"   "+string(1,mark));
            
        }
        pair<int,int> getBoxSize(){return this->BoxSize;}
        //=======================================
        //public interface
        //=======================================
        int fire(Bullet& bullet){
            bullet.valid_mark = true;
            bullet.position = position;
            bullet.position.first += bullet.BoxSize.first;
			// speed of bullet
			bullet.velocity.first = -1;
			return 0;
        }
        int debug_output(){
            for(int i = 0;i<BoxSize.first;i++){
                cout<<shape[i]<<endl;
            }

        }
};
#endif
