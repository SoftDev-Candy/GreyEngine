//
// Created by Candy on 11/21/2025.
//

#include "EngineContext.hpp"
#include"../external/imgui/imgui.h"
#include"../external/imgui/imgui_impl_glfw.h"
#include"../external/imgui/imgui_impl_opengl3.h"

static void framebuffer_size_callback(GLFWwindow* , int w , int h)
{
    glViewport(0,0,w,h);
}

void EngineContext::init()
{
    //Initialize GLFW

    if(!glfwInit())
    {
        std::cout<<"Failed to Initialize GLFW"<<std::endl;
        return ;
    }

    //give hints on what version you are using
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //Create window here now if not created terminate that mfer
    window = glfwCreateWindow(800,800,"B_WEngine",nullptr,nullptr);
    if (window == NULL )
    {
        std::cout<<"Failed to create GLFW Window"<<std::endl;
        glfwTerminate();
        return ;
    }

    //making window the current context //
    glfwMakeContextCurrent(window);

    glfwSetFramebufferSizeCallback(window ,framebuffer_size_callback);
    //Initialize Glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        return ;
    }

    glViewport(0,0,800,800); //This is the viewport or the drawable size area

    //Depth test dont worry about until it throws error//
    glEnable(GL_DEPTH_TEST);

    //THIS IS IT FINALLY THE COSMIC CREATION OF THE MOTHERLAND STARDENBURDENHARDENBART DEAR IMGUI//
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; //Enabling Controller dont need it saw it sounds cool might keep it for now;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //Enabling Keyboard

ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(window,true);
    ImGui_ImplOpenGL3_Init("#version 330");



}

bool EngineContext::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void EngineContext::update()
{
    glfwPollEvents();

    //Start the frame for imgui
    ImGui_ImplGlfw_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();

    //Made the movement go up and down , side to side to like a rollercoaster
    if (glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.position.z -= 0.05f;
    }

    if (glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.position.z += 0.05f;
    }

    if (glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.position.x -= 0.05f;
    }

    if (glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.position.x += 0.05f;
    }

    if (glfwGetKey(window,GLFW_KEY_Q) == GLFW_PRESS)
    {
        camera.position.y -= 0.05f;
    }

    if (glfwGetKey(window,GLFW_KEY_E) == GLFW_PRESS)
    {
        camera.position.y += 0.05f;
    }

    float time = static_cast<float>(glfwGetTime());
    auto& obj = scene.GetObjects()[0];
    obj.transform.rotation.y = time;

//Grab my object and add it to the UI so I can manipulate it //

    ImGui::Begin("Object Transform");
    //This is how we change the position
    ImGui::DragFloat3("Position",&obj.transform.position.x);

    //This is how we change the Rotation
    ImGui::DragFloat3("Rotation",&obj.transform.rotation.x);

    //This is how we scale it yo//
    ImGui::DragFloat3("Scale",&obj.transform.scale.x);


    ImGui::End();
}

void EngineContext::Render()
{

    renderer.Begin();
    renderer.RenderScene(scene ,camera);
    //Rendering IMGUI honestly should make a UImanager right after this I might need it
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);//Swapping buffers to make colour come in front on the viewport.

}

void EngineContext::Terminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();

    //Destroy or Shut it down //
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void EngineContext::AddObject(Renderable *object)
{
    scene.CreateObject(object);
}

std::vector<SceneObject>& EngineContext::Getobject()
{
    return scene.GetObjects();
}
