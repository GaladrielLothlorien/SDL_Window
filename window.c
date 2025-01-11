#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
    //Inicializar o SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        SDL_Log("SDL nao pode inicializar! %s", SDL_GetError());

        return 1;
    }

    //Criar janela
    SDL_Window* window = SDL_CreateWindow("Janela SDL", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if(!window){
        SDL_Log("Falha ao criar janela! %s", SDL_GetError());

        return 1;
    }

    //Main Loop
    bool quit = false;

    while(!quit){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    //Limpar e sair
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
