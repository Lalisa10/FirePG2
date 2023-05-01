#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include "utils.h"
#include "base_object.h"
#include "game_map.h"

class Explosion : public baseObject{
public:
       Explosion() {;}
       Explosion(SDL_Renderer* renderer, std::string fileName);
       ~Explosion();
       void draw(SDL_Renderer* renderer, gameMap* Map);
       bool isExploding() const {return _count_frame < 60;}
       void setPosition(const int &x, const int& y){_x_in_level = x, _y_in_level = y;}
private:
       SDL_Rect _frame_clip[10];
       int _count_frame, _x_in_level, _y_in_level;
       Mix_Chunk* _explosion_sound;
};

#endif // EXPLOSION_H_INCLUDED
