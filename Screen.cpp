#include"Common.hpp"
#include"Enemy.cpp"

using namespace std;

class Screen{
    private:
        const int width;
        int height;
        char **screenmat;
    public:
        Screen(int height_in):height(height_in),width(80){
            screenmat = new  char*[height]();
            for(int i = 0;i<height;i++){
                screenmat[i] = new char[width]();
            }
        }
        ~Screen(){
            for(int i = 0;i<height;i++){delete [] screenmat[i];}
            delete []screenmat;
            screenmat = NULL;
        }
        
        int draw_enemy(pair<int,int> position,const Enemy& enemy){
            int x = position.first;
            int y = position.second;
            pair<int,int> EnemyBox = enemy.BoxSize;
            for(int i = x;i<height&&i-x<EnemyBox.first;i++)
                for(int j = y;j<width&&j-y<EnemyBox.second;j++){
                    screenmat[i][j] = enemy.shape[i-x][j-y];
                }
        }
        int draw_obj(pair<int,int> position,Screen_object_base* obj){
            int x = position.first;
            int y = position.second;
            pair<int,int> EnemyBox = obj->BoxSize;
            for(int i = x;i<height&&i-x<EnemyBox.first;i++)
                for(int j = y;j<width&&j-y<EnemyBox.second;j++){
                    screenmat[i][j] = obj->shape[i-x][j-y];
                }
        }
        int draw_test(){
            for(int i = 0;i<height;i++)
                for(int j = 0;j<width;j++){
                    if(j%10==0){
                        screenmat[i][j] = '0'+j/10;
                    }else screenmat[i][j] = '.';
                }
        }
        int fill(char mark = ' '){
            for(int i = 0;i<height;i++)
                for(int j = 0;j<width;j++)
                    screenmat[i][j] = mark;
        }
        int disp(){
            system("cls");
            for(int i = 0;i<height;i++){
                for(int j = 0;j<width;j++){
                    printf("%c",screenmat[i][j]);
                }
                printf("\n");
            }
        }
        
};
