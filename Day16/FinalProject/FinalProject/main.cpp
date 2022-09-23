
#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    
    srand(static_cast<unsigned>(time(0)));
    Game MyGame;
    
    //The Game loop
    while (MyGame.getWindowIsOpen()) {
        
        //Update
        MyGame.update();
        
        //Render
        MyGame.render();
    }

    return 0;
}
