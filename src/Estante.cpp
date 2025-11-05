#include "Estante.h"

Estante::Estante(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Estante::init() {
    // Lateral esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.12f, 0.15f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.3f, 0.1f),
        0.0f
    ));

    // Lateral direita
    parts.push_back(new Cube(
        glm::vec3(0.12f, 0.15f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.3f, 0.1f),
        0.0f
    ));

    // Prateleiras (4 níveis)
    for (int i = 0; i < 4; i++) {
        parts.push_back(new Cube(
            glm::vec3(0.0f, 0.08f * i, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.25f, 0.01f, 0.1f),
            0.0f
        ));
    }

    // Fundo da estante
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.15f, -0.05f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.25f, 0.3f, 0.005f),
        0.0f
    ));
}

void Estante::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
