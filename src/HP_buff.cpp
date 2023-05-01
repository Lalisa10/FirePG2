#include "HP_buff.h"

HPBuff::HPBuff(SDL_Renderer* renderer, std::string fileName) : baseObject(renderer, fileName){
       _exist = true;
}

void HPBuff::setBox(const int& x, const int &y, const int &w, const int &h){
      _hit_box = {x, y, w, h};
}

void HPBuff::draw(SDL_Renderer* renderer, gameMap* Map){
       setRect(_hit_box.x - Map->getCurrentCameraX(), _hit_box.y - Map->getCurrentCameraY());
       render(renderer);
}
