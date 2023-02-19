#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../lib/Entity.hpp"

using namespace sf;
class Physics{
        private:
                const int groundHeight = 570;
                const float gravitySpeed  = 0.2;
                const float moveSpeed = 10;
                const float jumpSpeed = 90;
        public:
                Physics(){
                }
                void moveObj(Entity&,bool,bool,bool,bool);
};
