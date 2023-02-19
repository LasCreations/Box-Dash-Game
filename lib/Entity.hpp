#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

using namespace sf;
using namespace std;

class Entity{
        private:
                // RectangleShape rectangle;
                Texture texture;
                // Sprite player;
                RectangleShape player;
                RectangleShape object;

        public:
                Entity(){
                        if(!texture.loadFromFile("/home/lascelle/DevEnv/GameDev/Box-Dash/assets/Player.png")){
                                cout<<"Not Found"<<endl;
                        }
                        // player.setTexture(texture);
                        // player.setScale(Vector2f(0.11f,0.11f));
                        // player.setPosition(Vector2f(10,570));
                        player.setOutlineColor(Color::Red);
                        player.setSize(Vector2f(50, 50));
                        player.setPosition(Vector2f(10,580));
                        player.setFillColor(Color::Red);
                        object.setSize(Vector2f(50, 50));
                        object.setPosition(Vector2f(700,580));
                }

                ~Entity(){}
                void drawPlayer(RenderWindow&);
                void move(Vector2f);
                void setPos(Vector2f);
                int getY();
                int getX();
                void ScreenCollision();
};
