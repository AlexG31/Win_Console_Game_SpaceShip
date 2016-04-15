
#include"Common.hpp"
using namespace std;

#ifndef EnemyClassDEF
#define EnemyClassDEF
class Screen_object_base{
    public:
        pair<int,int> BoxSize;
        vector<string>shape;
    public:
        Screen_object_base():BoxSize(make_pair(0,0)){}
        Screen_object_base(const vector<string>&shape_in):shape(shape_in){
            // get BoxSize
            BoxSize.first = shape.size();
            int mlen(0);
            for(auto str:shape)mlen = max(mlen,(int)str.size());
            BoxSize.second = mlen;
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
        int debug_output(){
            for(int i = 0;i<BoxSize.first;i++){
                cout<<shape[i]<<endl;
            }

        }
};
#endif
