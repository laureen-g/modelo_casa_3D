#include "Casa.h"
#include <Cube.h>

#include <Shader.h>

Casa::Casa() {
}

void Casa::draw(Shader& shader, glm::mat4 view) {

    // CHÃO
    Cube chao(glm::vec3(0.0f, 0.05f, 0.0f),
                    glm::vec3(0.0f),
                    glm::vec3(2.0f, 0.03f, 2.0f));

    chao.draw(shader, view);

    // PAREDE DIREITA
    Cube paredeDireita(glm::vec3(1.0f, 0.265f, 0.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 2.0f));

    paredeDireita.draw(shader, view);

    //PAREDE ESQUERDA
    Cube paredeEsquerda(glm::vec3(-1.0f, 0.265f, 0.0f),
                        glm::vec3(0.0f),
                        glm::vec3(0.03f, 0.5f, 2.0f));

    paredeEsquerda.draw(shader, view);

    // PAREDE DA FRENTE
    Cube paredeFrente(glm::vec3(0.15f, 0.265f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(1.7f, 0.5f, 0.03f));

    paredeFrente.draw(shader, view);

    Cube paredeFrente2(glm::vec3(-0.95f, 0.265f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(0.1f, 0.5f, 0.03f));

    paredeFrente2.draw(shader, view);

    Cube paredeFrente3(glm::vec3(-0.8f, 0.44f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(0.2f, 0.15f, 0.03f));

    paredeFrente3.draw(shader, view);

    // PAREDE DO FUNDO
    Cube paredeFundo(glm::vec3(0.0f, 0.265f, -1.0f),
                     glm::vec3(0.0f),
                     glm::vec3(2.0f, 0.5f, 0.03f));

    paredeFundo.draw(shader, view);

    // DIVISORIA COMODOS
    Cube paredeDivisoria(glm::vec3(0.2f, 0.265f, 0.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 1.2f));

    paredeDivisoria.draw(shader, view);

    Cube paredeDivisoria2(glm::vec3(0.2f, 0.265f, -1.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 0.03f));

    paredeDivisoria2.draw(shader, view);






    Cube paredeDivisoria20(glm::vec3(0.6f, 0.265f, 0.2f),
                     glm::vec3(0.0f),
                     glm::vec3(0.8f, 0.5f, 0.03f));

    paredeDivisoria20.draw(shader, view);

}
