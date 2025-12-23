//
// Created by Candy on 12/18/2025.
//

#ifndef B_WENGINE_UIMANAGER_HPP
#define B_WENGINE_UIMANAGER_HPP
#include "../Camera.hpp"
#include "../Scene.hpp"

class UIManager
{

public:
    void Draw(Scene& scene , Camera& camera , int& selectedIndex , std::function<Entity(const std::string&)>createCube);

private:

};

#endif //B_WENGINE_UIMANAGER_HPP