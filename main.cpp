    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>
    #include <Shader.h>
    #include <Application.h>
    #include <Cube.h>
    #include <Texture.h>
    #include <iostream>
    #include <stdio.h>
    #include <Cylinder.h>
    #include <Sphere.h>
    #include <Prism.h>
    #include <Casa.h>

    void processInput(GLFWwindow *window);
    void viraCamera(float x, float y);

    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    float angulo_visao = 45.0f;
    float near_plane = 0.1f;
    float far_plane = 100.0f;

    glm::mat4 view;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.8f, 5.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

    float sensitivity = 0.15f;
    float yaw = -90.0f;
    float pitch = 0.0f;

    int main() {
        // Cria janela e inicializa OpenGL
        Application app(1024, 768, "Casa 3D");
        if (!app.init()) return -1;

        // Shader
        Shader shader("vertex.glsl", "fragment.glsl");
        shader.use();

        // TEXTURAS
        std::vector<Texture*> texCasa;
        std::vector<Texture*> texCama;
        std::vector<Texture*> texSofa;
        std::vector<Texture*> texEstante;
        std::vector<Texture*> texEspelho;
        std::vector<Texture*> texCadeira;
        std::vector<Texture*> texMesa;
        std::vector<Texture*> texGeladeira;
        std::vector<Texture*> texVaso;
        std::vector<Texture*> texLuminaria;

        // TEXTURA DA CASA
        texCasa.push_back(new Texture("chao.jpg"));
        texCasa.push_back(new Texture("parede.jpg"));

        // TEXTURA DA CAMA
        texCama.push_back(new Texture("madeira_cama.jpg"));
        texCama.push_back(new Texture("madeira_cama.jpg"));
        texCama.push_back(new Texture("madeira_cama.jpg"));
        texCama.push_back(new Texture("madeira_cama.jpg"));
        texCama.push_back(new Texture("manta_cama.png"));
        texCama.push_back(new Texture("travesseiro.jpg"));
        texCama.push_back(new Texture("travesseiro.jpg"));

        // TEXTURA DO SOFA
        texSofa.push_back(new Texture("sofa_vermelho.png"));
        texSofa.push_back(new Texture("sofa_vermelho.png"));
        texSofa.push_back(new Texture("sofa_vermelho_escuro.png"));
        texSofa.push_back(new Texture("sofa_vermelho_escuro.png"));


        // TEXTURA DA ESTANTE
        texEstante.push_back(new Texture("madeira_estante.jpg"));
        texEstante.push_back(new Texture("madeira_estante.jpg"));
        texEstante.push_back(new Texture("madeira_estante.jpg"));
        texEstante.push_back(new Texture("prateleira_estante.jpg"));
        texEstante.push_back(new Texture("prateleira_estante.jpg"));
        texEstante.push_back(new Texture("prateleira_estante.jpg"));
        texEstante.push_back(new Texture("prateleira_estante.jpg"));
        texEstante.push_back(new Texture("madeira_estante.jpg"));
        texEstante.push_back(new Texture("madeira_estante.jpg"));

        // TEXTURA ESPELHO
        texEspelho.push_back(new Texture("prateleira_estante.jpg"));
        texEspelho.push_back(new Texture("prateleira_estante.jpg"));
        texEspelho.push_back(new Texture("prateleira_estante.jpg"));
        texEspelho.push_back(new Texture("prateleira_estante.jpg"));
        texEspelho.push_back(new Texture("espelho.png"));
        texEspelho.push_back(new Texture("sofa_vermelho.png"));

        // TEXTURA CADEIRA
        texCadeira.push_back(new Texture("amarelo_cadeira.png"));
        texCadeira.push_back(new Texture("amarelo_cadeira.png"));
        texCadeira.push_back(new Texture("prateleira_estante.jpg"));
        texCadeira.push_back(new Texture("prateleira_estante.jpg"));
        texCadeira.push_back(new Texture("prateleira_estante.jpg"));
        texCadeira.push_back(new Texture("prateleira_estante.jpg"));

        // TEXTURA MESAS
        texMesa.push_back(new Texture("madeira_estante.jpg"));
        texMesa.push_back(new Texture("espelho.png"));
        texMesa.push_back(new Texture("espelho.png"));
        texMesa.push_back(new Texture("espelho.png"));
        texMesa.push_back(new Texture("espelho.png"));

        // TEXTURA GELADEIRA
        texGeladeira.push_back(new Texture("geladeira_2.png"));
        texGeladeira.push_back(new Texture("geladeira.png"));
        texGeladeira.push_back(new Texture("geladeira.png"));
        texGeladeira.push_back(new Texture("prateleira_estante.jpg"));
        texGeladeira.push_back(new Texture("prateleira_estante.jpg"));

        // TEXTURA VASO
        texVaso.push_back(new Texture("vaso.png"));

        // TEXTURA LUMINARIA
        texLuminaria.push_back(new Texture("geladeira_2.png"));
        texLuminaria.push_back(new Texture("geladeira.png"));
        texLuminaria.push_back(new Texture("luminaria.jpg"));

        // Ativa depth test
        glEnable(GL_DEPTH_TEST);

        Casa casa;

        // Loop principal
        while (!glfwWindowShouldClose(app.getWindow())) {
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            // Processa input
            if (glfwGetKey(app.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(app.getWindow(), true);

            processInput(app.getWindow());

            // Limpa tela e depth buffer
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            shader.use();

            glm::mat4 model = glm::mat4(1.0f);
            float angle = 20.0f;
            //model = glm::rotate(model, (angle * (float) glfwGetTime()) / 20, glm::vec3(0.0f, 0.3f, 0.0f));
            //model = glm::rotate(model, -20.0f, glm::vec3(0.0f, 0.3f, 0.0f));

            shader.setMat4("model", model);

            // Configura view e projection
            glm::mat4 projection = glm::perspective(glm::radians(angulo_visao),
                                                    (float)SCR_WIDTH / (float)SCR_HEIGHT,
                                                    near_plane, far_plane);

            viraCamera(0.0f, 0.0f);
            view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
            shader.setMat4("projection", projection);
            shader.setMat4("view", view);

            shader.setMat4("model", model);

            casa.draw(shader, model, texCasa, texCama, texSofa, texEstante, texEspelho, texCadeira, texMesa, texGeladeira, texVaso, texLuminaria);

            // Swap buffers e eventos
            glfwSwapBuffers(app.getWindow());
            glfwPollEvents();
        }

        return 0;
    }

    // glfw: whenever the window size changed (by OS or user resize) this callback function executes
    // ---------------------------------------------------------------------------------------------
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }

    void viraCamera(float x, float y) {
        yaw += x * sensitivity;
        pitch += y * sensitivity;

        if(pitch > 89.0f) {
            pitch = 89.0f;
        }
        if(pitch < -89.0f) {
            pitch = -89.0f;
        }

        glm::vec3 direction;

        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

        cameraFront = glm::normalize(direction);
    }

    void processInput(GLFWwindow *window)
    {
        const float cameraSpeed = 2.5f * deltaTime;

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS)
            angulo_visao++;

        if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS)
            angulo_visao--;

        if (glfwGetKey(window, GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS)
            far_plane++;

        if (glfwGetKey(window, GLFW_KEY_KP_DIVIDE) == GLFW_PRESS)
            far_plane--;

        if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS) {
            near_plane+=0.1f;
            printf("%f\n", near_plane);
        }

        if (glfwGetKey(window, GLFW_KEY_KP_9) == GLFW_PRESS) {
            near_plane-=0.1f;
            printf("%f\n", near_plane);
        }

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            angulo_visao = 45.0f;
            near_plane=0.1f;
            far_plane=100;
            printf("%.2f %f %f\n", angulo_visao, near_plane, far_plane);
        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            cameraPos += cameraSpeed * cameraFront;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            cameraPos -= cameraSpeed * cameraFront;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            viraCamera(0.0f, 1.0f);
        }

        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            viraCamera(0.0f, -1.0f);
        }

        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            viraCamera(-1.0f, 0.0f);
        }

        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            viraCamera(1.0f, 0.0f);
        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
            cameraPos += glm::vec3(0.0f, 1.0f, 0.0f) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
            cameraPos += glm::vec3(0.0f, -1.0f, 0.0f) * cameraSpeed;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            cameraPos = glm::vec3(0.0f, 0.8f, 5.0f);
            yaw = -90.0f;
            pitch = 0.0f;
        }
    }
