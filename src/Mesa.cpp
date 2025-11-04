#include "Mesa.h"

Mesa::Mesa(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Mesa::init() {
    // Tampo da mesa
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.075f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.15f, 0.01f, 0.1f),
        0.0f
    ));

    // Perna frontal esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.065f, 0.035f, 0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.07f, 0.01f),
        0.0f
    ));

    // Perna frontal direita
    parts.push_back(new Cube(
        glm::vec3(0.065f, 0.035f, 0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.07f, 0.01f),
        0.0f
    ));

    // Perna traseira esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.065f, 0.035f, -0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.07f, 0.01f),
        0.0f
    ));

    // Perna traseira direita
    parts.push_back(new Cube(
        glm::vec3(0.065f, 0.035f, -0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.07f, 0.01f),
        0.0f
    ));
}

void Mesa::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
