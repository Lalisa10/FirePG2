#include "explosion.h"

Explosion::Explosion(SDL_Renderer* renderer, std::string fileName) : baseObject(renderer, fileName){

       for(int i = 0; i < 10; i ++){
              _frame_clip[i] = {i * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
       }

       _explosion_sound = Mix_LoadWAV("data/sound/death_explosion.wav");
       Mix_PlayChannel(-1 , _explosion_sound, 0);
       _count_frame = 0;

}

Explosion::~Explosion(){

       if(_explosion_sound != NULL){
              Mix_FreeChunk(_explosion_sound);
              _explosion_sound = NULL;
       }

}

void Explosion::draw(SDL_Renderer* renderer, gameMap* Map){

       setRect(_x_in_level - Map->getCurrentCameraX(), _y_in_level - Map->getCurrentCameraY());
       render(renderer, &_frame_clip[_count_frame / 6]);
       _count_frame ++;

}
