#include "Espelho.h"

Espelho::Espelho(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Espelho::init() {
    // Moldura esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.055f, 0.08f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.16f, 0.01f),
        0.0f
    ));

    // Moldura direita
    parts.push_back(new Cube(
        glm::vec3(0.055f, 0.08f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.16f, 0.01f),
        0.0f
    ));

    // Moldura superior
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.165f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.12f, 0.01f, 0.01f),
        0.0f
    ));

    // Moldura inferior
    parts.push_back(new Cube(
        glm::vec3(0.0f, -0.005f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.12f, 0.01f, 0.01f),
        0.0f
    ));

    // Vidro do espelho (cube translucido representado aqui)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.08f, -0.005f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.11f, 0.14f, 0.005f),
        0.0f
    ));

    // Decoracao - esfera no topo
    parts.push_back(new Sphere(
        glm::vec3(0.0f, 0.195f, 0.015f),
        glm::vec3(0.0f),
        glm::vec3(0.015f, 0.015f, 0.015f),
        0.0f,
        16,
        16
    ));
}

void Espelho::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i=0; i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i]->bind(0);
        parts[i]->draw(shader, model);
    }

}
