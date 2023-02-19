#include "../lib/Physics.hpp"
#include<iostream>
using namespace sf;
using namespace std;

void Physics::moveObj(Entity& player,bool IsUp,bool IsRight,bool IsLeft,bool IsJumping){
        if(IsUp){
                player.move({0,-jumpSpeed});
        }

        if(IsRight){
                player.move({moveSpeed, 0});
        }

        if(IsLeft){
                player.move({-moveSpeed, 0});
        }
        if(player.getY() < groundHeight && !IsJumping){
                player.move({0,jumpSpeed});
        }
}
