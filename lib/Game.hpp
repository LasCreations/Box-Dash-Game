#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include"SFML/System.hpp"
#include "../lib/Entity.hpp"
#include "../lib/Physics.hpp"
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace sf;

class Game{

        private:
                RenderWindow window;
                Texture BackgroundTexture; //image
                Sprite background;  //allows to easily display a texture
                Vector2u TextureSize;  //Added to store texture size.
                Vector2u WindowSize;   //Added to store window size.
                Event event;
                Keyboard::Key key;
                Entity player;
                Clock clock;
                Physics phy;
                View view;
                vector<RectangleShape> shape;

        public:
                Game(){
                        window.create(VideoMode(700, 634), "Box Dash", Style::Default);
                        window.setKeyRepeatEnabled(true);
                        window.setFramerateLimit(60);
                        this->BackgroundTexture.loadFromFile("/home/lascelle/DevEnv/GameDev/Box-Dash/assets/background.jpeg");
                        this->TextureSize = BackgroundTexture.getSize();
                        this->WindowSize = window.getSize();
                        view.setSize(700, 634);
                }

                ~Game(){}
                void render();
                void run();
                void processEvents();
};
