
#include"Common.hpp"
using namespace std;

#ifndef EnemyClassDEF
#define EnemyClassDEF
class Enemy{
    private:
        pair<int,int> BoxSize;
        vector<string>shape;
    public:
        friend class Screen;
        Enemy(const vector<string>&shape_in):shape(shape_in){
            // get BoxSize
            BoxSize.first = shape.size();
            int mlen(0);
            for(auto str:shape)mlen = max(mlen,(int)str.size());
            BoxSize.second = mlen;
        }
        // default shape
        Enemy(int h = 3,int w = 3,char mark = '#'){
            BoxSize = make_pair(h,w);
            for(int i = 0;i<BoxSize.first;i++){
                string line(BoxSize.second,' ');
                for(int j = 0;j<BoxSize.second;j++){
                    if(j==BoxSize.second/2)line[j] = mark;
                    else if(i==BoxSize.first/2)line[j] = mark;
                }
                shape.push_back(line);
            }
            
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
#endif
