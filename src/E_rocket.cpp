#include "E_Rocket.h"
#include "enemy_tank.h"

Rocket::Rocket(SDL_Renderer* renderer, std::string fileName, enemyTank* eTank) : baseObject(renderer, fileName), _target(eTank){
       _onTarget = false;
}

Rocket::~Rocket(){
       _target = NULL;
}

void Rocket::move(){

       _current_pos_x += ROCKET_VELOCITY * cos(_direction);
       _current_pos_y += ROCKET_VELOCITY * sin(_direction);

}

void Rocket::draw(SDL_Renderer* renderer, gameMap* Map){

       setRect(_current_pos_x - Map->getCurrentCameraX(), _current_pos_y - Map->getCurrentCameraY());
       render(renderer, NULL, _direction * 180 / M_PI + 90, NULL, SDL_FLIP_NONE);

}

void Rocket::updateDirection(){

       int x = 0, y = 0;
       getCenter(&x, &y);

       int tx = 0, ty = 0;
       _target->getCenter(&tx, &ty);

       _direction = atan2(ty - y, tx - x);

}

void Rocket::handleCollision(){

       int x = 0, y = 0;
       getCenter(&x, &y);

       int &headX = x, &headY = y;
       headX = x + cos(_direction) * 20;
       headY = y + sin(_direction) * 20;

       SDL_Rect target_box = _target->getBox();
       target_box.x = _target->getX();
       target_box.y = _target->getY();

       if(CommonFunction::checkPointInsideRect(headX, headY, target_box)){
              setOnTarget();
              _target->changeHealth(-_damage);
       }

}

void Rocket::getCenter(int *x, int *y){

       *x = _current_pos_x + 10;
       *y = _current_pos_y + 20;

}

void Rocket::update(){

       move();
       updateDirection();
       handleCollision();

}

