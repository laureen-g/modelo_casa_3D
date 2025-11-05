#include "Luminaria.h"

Luminaria::Luminaria(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Luminaria::init() {
    // Base da luminária
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.005f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.05f, 0.01f, 0.05f),
        0.0f
    ));

    // Haste/poste
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.08f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.15f, 0.008f),
        0.0f
    ));

    // Cúpula/abajur (parte de cima)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.16f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.06f, 0.04f, 0.06f),
        0.0f
    ));

    // Lâmpada (parte interna)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.15f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.02f, 0.02f),
        0.0f
    ));
}

void Luminaria::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
