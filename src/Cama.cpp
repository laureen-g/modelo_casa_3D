#include "Cama.h"

Cama::Cama(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Cama::init() {
    // Base da cama (estrutura)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.03f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.02f, 0.25f),
        0.0f
    ));

    // Colchão
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.055f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.19f, 0.03f, 0.24f),
        0.0f
    ));

    // Cabeceira
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.09f, -0.115f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.1f, 0.02f),
        0.0f
    ));

    // Pé da cama esquerdo
    parts.push_back(new Cube(
        glm::vec3(-0.085f, 0.015f, 0.115f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.015f, 0.03f, 0.015f),
        0.0f
    ));

    // Pé da cama direito
    parts.push_back(new Cube(
        glm::vec3(0.085f, 0.015f, 0.115f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.015f, 0.03f, 0.015f),
        0.0f
    ));
}

void Cama::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
