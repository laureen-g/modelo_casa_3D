#include "VasoSanitario.h"

VasoSanitario::VasoSanitario(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void VasoSanitario::init() {
    // Base do vaso
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.015f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.05f, 0.03f, 0.06f),
        0.0f
    ));

    // Parte principal do vaso (bacia)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.035f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.045f, 0.02f, 0.055f),
        0.0f
    ));

    // Tampa do vaso
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.048f, 0.005f, 0.058f),
        0.0f
    ));

    // Caixa acoplada (parte de trás)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.065f, -0.025f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.045f, 0.05f, 0.02f),
        0.0f
    ));
}

void VasoSanitario::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
