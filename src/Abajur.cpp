#include "Abajur.h"

Abajur::Abajur(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Abajur::init() {

    // Base quadrada e robusta
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.02f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.12f, 0.04f, 0.12f),
        0.0f
    ));

    // Haste cilíndrica central
    parts.push_back(new Cylinder(
        glm::vec3(0.0f, 0.09f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.015f, 0.14f, 0.015f),
        0.0f,
        16
    ));

    // Cúpula cônica (prism com 8 lados)
    parts.push_back(new Prism(
        glm::vec3(0.0f, 0.22f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.08f, 0.06f, 0.08f),
        0.0f,
        8,
        0.12f
    ));
}

void Abajur::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
