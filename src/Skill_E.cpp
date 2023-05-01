#include "Skill_E.h"
#include "game.h"

Skill_E::Skill_E(SDL_Renderer* renderer, std::string fileName, game* _g, int cd) :  Skill(renderer, fileName, SDLK_e, cd), _game(_g){
       setRect(400, 600 - 63);
       _rocket_sound = Mix_LoadWAV("data/sound/rocket_sound.wav");
       if(_rocket_sound == NULL) CommonFunction::logSDLError(std::cout, "Load rocket sound");
}

Skill_E::~Skill_E(){
       for(Rocket* rocket : _rocket_list){
              delete rocket;
              rocket = NULL;
       }
       if(_rocket_sound != NULL){
              Mix_FreeChunk(_rocket_sound);
              _rocket_sound = NULL;
       }
       _rocket_list.clear();
}

void Skill_E::handleUserInput(SDL_Event e, SDL_Renderer* renderer){
       if(e.key.keysym.sym == _key_press){

              if(_cool_down_timer->getTicks() > _cool_down){

                     int x = 0, y = 0;
                     _game->getMouseState(&x, &y);

                     std::vector<enemyTank*> e_tank_list = _game->getEnemyTankList();

                     mainTank* mTank = _game->getMainTank();
                     int mx = 0, my = 0;
                     mTank->getCenter(&mx, &my);
                     double angle = atan2(my - y, mx - x);

                     for(enemyTank* eTank : e_tank_list){

                            if(CommonFunction::checkPointInsideRect(x, y, eTank->getRect())){

                                   Rocket* new_rocket = new Rocket(renderer, "rocket.png", eTank);
                                   new_rocket->setPosition(mx + 40 * cos(angle), my + 40 * sin(angle));
                                   new_rocket->setDamage(100);
                                   _rocket_list.push_back(new_rocket);
                                   _cool_down_timer->restart();

                                   Mix_PlayChannel(-1, _rocket_sound, 0);

                                   break;
                            }

                     }

              }
       }
}

void Skill_E::update(){

       for(Rocket* rocket : _rocket_list){

              rocket->updateDirection();
              rocket->move();
              rocket->handleCollision();

       }
       std::vector<Rocket*> new_rocket_list;

       for(Rocket* rocket : _rocket_list){

              if(rocket->isExisting()) new_rocket_list.push_back(rocket);
              else{
                     delete rocket;
                     rocket = NULL;
              }

       }
       _rocket_list = new_rocket_list;

}

void Skill_E::draw(SDL_Renderer* renderer, gameMap* Map){

       for(Rocket* rocket : _rocket_list){
              rocket->draw(renderer, Map);
       }
       renderCoolDown(renderer);

}
