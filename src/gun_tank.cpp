#include "gun_tank.h"

gunTank::gunTank(SDL_Renderer* renderer, std::string fileName) : baseObject(renderer, fileName){
       _angle = M_PI / 2;
}

void gunTank::draw(SDL_Renderer* renderer){
       render(renderer, NULL, getAngle(), NULL, SDL_FLIP_NONE);
}
