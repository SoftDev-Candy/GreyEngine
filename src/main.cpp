#include<iostream>

#include "Cube.hpp"
#include "EngineContext.hpp"
#include "Triangle.hpp"

static void framebuffer_size_callback(GLFWwindow* , int w , int h)
{
    glViewport(0,0,w,h);
}

int main(void)
{

EngineContext EngineObject;
EngineObject.init();
EngineObject.AddObject(new Cube());
    EngineObject.AddObject(new Cube());
    auto& obj1 = EngineObject.Getobject()[0];
    auto& obj2 = EngineObject.Getobject()[1];
 obj1.transform.position = glm ::vec3(0.0f, 0.0f,0.0f);
obj2.transform.position = glm ::vec3(1.0f, 0.0f,0.0f);

    //Its while loop to keep that window open//we
while (!EngineObject.ShouldClose())
{



EngineObject.update();
EngineObject.Render();

}
EngineObject.Terminate();

}



