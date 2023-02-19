#include "../lib/Entity.hpp"
using namespace sf;

void Entity::drawPlayer(RenderWindow &window){
        window.draw(player);
        window.draw(object);
}

void Entity::move(Vector2f distance){
        player.move(distance);
}

void Entity::setPos(Vector2f newPos){
        player.setPosition(newPos);
}

int Entity::getY(){
        return player.getPosition().y;
}

int Entity::getX(){
        return player.getPosition().x;
}

void Entity::ScreenCollision(){
        //Big Jump
        if(getY()<450){
                player.setPosition(player.getPosition().x, 580.f);
        }

        //Left
        if(player.getPosition().x < 0.f){
                player.setPosition(0.f, player.getPosition().y);
        }
        //Top
        if(player.getPosition().y < 0.f){
                player.setPosition(player.getPosition().x, 0.f);

        }
        //Right                                                        //Window Width
        if(player.getPosition().x + player.getGlobalBounds().width > 700){
                player.setPosition(700 - player.getGlobalBounds().width, player.getPosition().y);

        }
        //Bottom                                                        //Window Heigth
        if(player.getPosition().y + player.getGlobalBounds().height > 634){
                player.setPosition(player.getPosition().x, 634 - player.getGlobalBounds().height);

        }
}
