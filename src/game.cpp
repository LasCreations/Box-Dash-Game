#include "../lib/Game.hpp"
using namespace sf;

void Game::render(){
         float ScaleX = (float) WindowSize.x / TextureSize.x;
         float ScaleY = (float) WindowSize.y / TextureSize.y;
         background.setTexture(BackgroundTexture);
         background.setScale(ScaleX, ScaleY);
         window.clear();
         window.setView(window.getDefaultView());
         window.draw(background);
         for(long unsigned int i = 0; i<shape.size(); i++){
                shape[i].move(-1.5f, 0.f);
                window.draw(shape[i]);
         }
         //
         // window.setView(view);
         player.drawPlayer(window);
         window.display();
 }

void Game::processEvents(){
         while (window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                        window.close();

                if (Keyboard::isKeyPressed(Keyboard::Up)){
                        phy.moveObj(player, true, false, false,true);
                }

                if (Keyboard::isKeyPressed(Keyboard::Left)){
                        phy.moveObj(player, false, false, true,false);
                }

                if (Keyboard::isKeyPressed(Keyboard::Right)){
                        phy.moveObj(player, false, true, false,false);
                }

                if(event.type == sf::Event::KeyReleased)
                        phy.moveObj(player, false, false, false,false);

                player.ScreenCollision();
        }
}

void Game::run(){
        while (window.isOpen()){
                //erase object if out of screen
                for(long unsigned int i = 0; i<shape.size(); i++){
                        if(shape[i].getPosition().x < 0.f){
                                shape.erase(shape.begin() + i); //memory address of the first element
                        }
                }
                if(clock.getElapsedTime().asSeconds() > (3 +(rand()%(5-3+1)))){
                        shape.push_back(RectangleShape());
                        shape.back().setSize(Vector2f(50, 50));
                        shape.back().setPosition(Vector2f(600,580));
                        clock.restart();
                }

                processEvents();
                render();
        }
}
