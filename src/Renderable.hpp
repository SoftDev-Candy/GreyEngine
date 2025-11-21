//
// Created by Candy on 11/18/2025.
//

#ifndef B_WENGINE_RENDERABLE_HPP
#define B_WENGINE_RENDERABLE_HPP

class Renderable
{
public:
    virtual void Render() = 0;
    virtual ~Renderable() = default;

};


#endif //B_WENGINE_RENDERABLE_HPP