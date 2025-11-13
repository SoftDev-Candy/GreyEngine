#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main(void)
{

    //Initialise GLfW
if (!glfwInit())
{
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
}

    //give hints on what version you are using
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE , GLFW_OPENGL_CORE_PROFILE);

    //Create window here now if not created terminate that mfer
    GLFWwindow* window = glfwCreateWindow(800, 800, "B_WEngine", nullptr, nullptr);
    if (window == NULL)
    {
        std::cout<<"Failed to create GLFW Window"<<std::endl;
        glfwTerminate();
        return -1;
    }

    //making window the current context //
glfwMakeContextCurrent(window);

//Initialize Glad//
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }

    glViewport(0,0,800,800); //This is the viewport or the drawable size area

    //Its while loop to keep that window open//
while (!glfwWindowShouldClose(window))
{
    glfwPollEvents();
    glClearColor(.12f,0.13f,0.17f,1.0f); //The colour we want to give to the screen

    glClear(GL_COLOR_BUFFER_BIT);//Clearing the buffer to get the colour out.
    glfwSwapBuffers(window);//Swapping buffers to make colour come in front on the viewport.

}

    glfwDestroyWindow(window);
glfwTerminate();
}



