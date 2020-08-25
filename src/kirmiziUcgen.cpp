#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Shader compiler
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str(); // pointer to beginning of data
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);


    // Error Handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result); // i: integer v: vector

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char * message = (char*) _malloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed To Compile!  " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;

    }


    return id;
}
// Shader 
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER,vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /*K�t�phane eklenir. */
    if (!glfwInit())
        return -1;

    
       


    /* OpenGL ortam�nda pencere modunda pencere olu�turulur. */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Hata!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    float positions[6] = { -0.5f,-0.5f,
                            0.0f,0.5f,
                            0.5f,-0.5f };
    unsigned int buffer;
    /*Buffer olu�turma ve ID tan�mlama*/
    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    /*Buffer'a data atama*/
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float),positions,GL_STATIC_DRAW);

    /*Vertex'i aktif hale getirme*/ 
    glEnableVertexAttribArray(0);
    /*Vertex ve �zelliklerini tan�mlama*/
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,0);

    // Shader objesini olu�turma
    std::string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;"
        "\n"
        "void main()"
        "{\n"
        "   gl_Position = position;\n "
        "}\n";
    std::string fragmentShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;"
        "\n"
        "void main()"
        "{\n"
        "   color = vec4(1.0,0.0,0.0,1.0); \n"
        "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Kullan�c� pencereyi kapatana kadar devam edecek d�ng� */
    while (!glfwWindowShouldClose(window))
    {
        /* Render burada ba�lar */
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES,0,3);     
        /* �n-arka buffer de�i�tirme */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}