#include "Skill.h"

Skill::Skill(SDL_Renderer* renderer, std::string fileName, int key, int CD) : baseObject(renderer, fileName){
       _key_press = key;
       _cool_down = CD;
       _cool_down_timer = new LTimer();
       if(_cool_down_timer == NULL) CommonFunction::logSDLError(std::cout, "Load cool down timer", true);
       _cool_down_timer->start();
}

Skill::~Skill(){
       if(_cool_down_timer != NULL){
              delete _cool_down_timer;
              _cool_down_timer->start();
       }
}

void Skill::renderCoolDown(SDL_Renderer* renderer){
       if(_cool_down_timer->getTicks() < _cool_down) setColor(64, 64, 64);
       else setColor(255, 255, 255);
       render(renderer);
}
