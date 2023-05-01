#ifndef HP_BUFF_H_INCLUDED
#define HP_BUFF_H_INCLUDED

#include "utils.h"
#include "base_object.h"
#include "game_map.h"

class HPBuff : public baseObject{
public:
       HPBuff(){;}
       HPBuff(SDL_Renderer* renderer, std::string fileName);
       ~HPBuff(){;}
       bool isExist() const {return ( _exist == true );}
       void Delete() {_exist = false;}
       void setBox(const int& x, const int& y, const int& w = TILE_SIZE, const int &h = TILE_SIZE);
       SDL_Rect getBox() const {return _hit_box;}
       void setRecuperation(const int r) {_recuperation = r;}
       int getRecuperation() const {return _recuperation;}
       void draw(SDL_Renderer* renderer, gameMap* Map);
private:
       int _recuperation;
       bool _exist;
       SDL_Rect _hit_box;
};

#endif // HP_BUFF_H_INCLUDED
