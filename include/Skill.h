#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include "utils.h"
#include "base_object.h"
#include "timers.h"

class Skill : public baseObject{
public:
       Skill(){;}
       Skill(SDL_Renderer* renderer, std::string fileName, int key, int CD);
       ~Skill();
       void renderCoolDown(SDL_Renderer* renderer);
protected:
       LTimer* _cool_down_timer;
       int _key_press;
       int _cool_down;
};


#endif // SKILL_H_INCLUDED
