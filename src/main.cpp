#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
static void framebuffer_size_callback(GLFWwindow* , int w , int h)
{
    glViewport(0,0,w,h);
}

//This is like tiny C functions the language is called GLSL
const char* VertexShader = R"(
#version 330 core

layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
}

)";

const char* FragmentShader = R"(
#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.5, 0.2, 1.0); // orange
}

)";

//Create a helper function to read shaders //
unsigned int compileShader(unsigned int type, const char* source)
{
unsigned int shader = glCreateShader(type);
    glShaderSource(shader,1,&source,NULL);
glCompileShader(shader);

int success;

    char infoLog [512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader compilation error:\n" << infoLog << std::endl;
    }


    return shader;
}

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

    //Call the function to resize the viewport
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

//Initialize Glad//
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }

    glViewport(0,0,800,800); //This is the viewport or the drawable size area

    //MAKE A TRIANGLE HERE NOW //
    float vertices[] = {
        -0.5f,-0.5f,0.0f,
         0.5f,-0.5f,0.0f,
         0.0f,0.5f,0.0f,
        };

    //Initialize the VBO - Vertex Buffer Object
    unsigned int VBO;
    glGenBuffers(1,&VBO); //Assigns a id to the buffer and creates it .
    glBindBuffer(GL_ARRAY_BUFFER,VBO); //Anything I upload will go into this buffer
    glBufferData(GL_ARRAY_BUFFER ,sizeof(vertices) , vertices , GL_STATIC_DRAW);//Take my floats and add it to GPU memory.

    //Initialize VAO - Vertex Array Object
    unsigned int VAO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    //lets openGl how to read to our data//
    glVertexAttribPointer(
     0,                // attribute location 0 in shader
     3,                // 3 components per vertex
     GL_FLOAT,         // type
     GL_FALSE,         // no normalization
     3 * sizeof(float),// stride (size of each vertex)
     (void*)0          // offset (start of buffer)
 );
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    //VAO IS COMPLETELY SETUP HERE//
unsigned int vertexshader = compileShader(GL_VERTEX_SHADER, VertexShader);
    unsigned int fragmentshader = compileShader(GL_FRAGMENT_SHADER, FragmentShader);

unsigned int shaderprogram = glCreateProgram();
    glAttachShader(shaderprogram , vertexshader);
    glAttachShader(shaderprogram , fragmentshader);
    glLinkProgram(shaderprogram);

    //Delete the seprated objects from memory//
    glDeleteShader(vertexshader);
    glDeleteShader(fragmentshader);

//TRIANGLE SETUP ENDS HERE PUTA//

    //Its while loop to keep that window open//
while (!glfwWindowShouldClose(window))
{
    glClearColor(.12f,0.13f,0.17f,1.0f); //The colour we want to give to the screen
    glClear(GL_COLOR_BUFFER_BIT);//Clearing the buffer to get the colour out.

    glUseProgram(shaderprogram);

    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES , 0 ,3);

    glfwSwapBuffers(window);//Swapping buffers to make colour come in front on the viewport.
    glfwPollEvents();


}

    glfwDestroyWindow(window);
glfwTerminate();

}



