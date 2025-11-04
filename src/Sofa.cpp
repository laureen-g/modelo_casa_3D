#include "Sofa.h"

Sofa::Sofa(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Sofa::init() {
    // Base do sofá (assento)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.03f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.04f, 0.1f),
        0.0f
    ));

    // Encosto do sofá
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.08f, -0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.1f, 0.02f),
        0.0f
    ));

    // Braço esquerdo
    parts.push_back(new Cube(
        glm::vec3(-0.09f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.08f, 0.1f),
        0.0f
    ));

    // Braço direito
    parts.push_back(new Cube(
        glm::vec3(0.09f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.08f, 0.1f),
        0.0f
    ));
}

void Sofa::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
