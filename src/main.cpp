#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 700), "Fractals");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    
    // A texture that fills the windows and that is rendered using a fragment shader that operates pixel per pixel
    sf::RectangleShape fillRect(sf::Vector2f(900, 700));
    fillRect.setPosition(0, 0);

    sf::Clock clock;

    sf::Shader shader;
    // the shader program will be executed for each pixel, and each pixel represents a complex nomber on the complex plane
    if (!shader.loadFromFile("../shaders/shader.frag", sf::Shader::Fragment)) {
       std::cout << "Failed to load shader file" << std::endl;
    }
    shader.setUniform("winSize", sf::Glsl::Vec2((float)window.getSize().x, (float)window.getSize().y));

    sf::Glsl::Vec3 divergenceColor = sf::Glsl::Vec3(1.0f, 0.0f, 0.0f);
    sf::Glsl::Vec3 convergenceColor = sf::Glsl::Vec3(1.0f, 0.0f, 0.0f);

    // an array that contains the picked color with the imgui color picker
    float divergenceColorPickedColor[] = {1.0f, 0.0f, 0.0f};
    // same for convergence color
    float convergenceColorPickedColor[] = {1.0f, 0.0f, 0.0f};

    // change the value of c for the julia fractals, this value affects the shape of the fractal
    float julia_c_value_x = 0.0f;  // the real part 
    float julia_c_value_y = 1.0f;  // the imaginary part
    
    float zoom = 1.0f;
    float zoomSpeed = 0.05f;
    int iterLimit = 20;

    bool isLeftMousePressed = false;

    sf::Glsl::Vec2 offset(0.0f, 0.0f);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::MouseWheelScrolled) {
                //zoom += event.mouseWheel.x/20000000; // adjust the sensitivity by dividing it because else it will be a gigantic number
                
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(zoom+zoomSpeed >= 0) {
                zoom+=zoomSpeed;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(zoom-zoomSpeed >= 0) {
                zoom-=zoomSpeed;
            }
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            offset.y += 5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            offset.x -= 5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            offset.y-=5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            offset.x+=5;
        }


        shader.setUniform("iterLimit", (float)iterLimit);

        shader.setUniform("divergenceColor", divergenceColor);
        shader.setUniform("convergenceColor", convergenceColor);

        shader.setUniform("julia_c", sf::Glsl::Vec2(julia_c_value_x, julia_c_value_y));
        shader.setUniform("zoom", zoom);

        shader.setUniform("offset", offset);
        

        ImGui::SFML::Update(window, clock.restart());
        ImGui::Begin("Change values");
        ImGui::ColorEdit3("Divergence color", divergenceColorPickedColor);
        ImGui::ColorEdit3("Convergence color", convergenceColorPickedColor);
        ImGui::SliderFloat("Julia c x", &julia_c_value_x ,-1.0f, 1.0f);
        ImGui::SliderFloat("Julia c y", &julia_c_value_y ,-1.0f, 1.0f);
        ImGui::SliderInt("Max iteration", &iterLimit, 1, 3000);
        //ImGui::Combo("Fractal", )
        ImGui::End();

        divergenceColor = sf::Glsl::Vec3(divergenceColorPickedColor[0], divergenceColorPickedColor[1], divergenceColorPickedColor[2]);
        convergenceColor = sf::Glsl::Vec3(convergenceColorPickedColor[0], convergenceColorPickedColor[1], convergenceColorPickedColor[2]);

        window.clear();
        window.draw(fillRect, &shader);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}