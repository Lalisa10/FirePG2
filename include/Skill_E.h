#ifndef SKILL_E_H_INCLUDED
#define SKILL_E_H_INCLUDED

#include "utils.h"
#include "Skill.h"
#include "E_Rocket.h"

class game;

class Skill_E : public Skill{
public:
       Skill_E();
       Skill_E(SDL_Renderer* renderer, std::string fileName, game* g, int cd);
       ~Skill_E();
       void handleUserInput(SDL_Event e, SDL_Renderer* renderer);
       void update();
       void draw(SDL_Renderer* renderer, gameMap* Map);
private:
       game* _game;
       Mix_Chunk* _rocket_sound;
       std::vector<Rocket*> _rocket_list;
};

#endif // SKILL_E_H_INCLUDED
