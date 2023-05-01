#ifndef E_ROCKET_H_INCLUDED
#define E_ROCKET_H_INCLUDED

#include "utils.h"
#include "base_object.h"
#include "game_map.h"

class enemyTank;

class Rocket : public baseObject{
public:
       Rocket(){;}
       Rocket(SDL_Renderer* renderer, std::string fileName, enemyTank *eTank);
       ~Rocket();
       void setPosition(const int& x, const int& y) {_current_pos_x = x, _current_pos_y = y;}
       void setDamage(int dame) {_damage = dame;}
       void move();
       void draw(SDL_Renderer* renderer, gameMap* Map);
       bool isExisting() const {return !_onTarget;}
       void setOnTarget() {_onTarget = true;}
       void updateDirection();
       void handleCollision();
       void update();
       void getCenter(int *x, int *y);
private:
       int _current_pos_x, _current_pos_y;
       int _damage;
       double _direction;
       bool _onTarget;
       enemyTank* _target;
};

#endif // E_ROCKET_H_INCLUDED
