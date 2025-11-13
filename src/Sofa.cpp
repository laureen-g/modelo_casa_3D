#include "Sofa.h"

Sofa::Sofa(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Sofa::init() {
    // Base do sofa (assento)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.03f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.04f, 0.1f),
        0.0f
    ));

    // Encosto do sofa
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.08f, -0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.2f, 0.1f, 0.02f),
        0.0f
    ));

    // Braco esquerdo
    parts.push_back(new Cube(
        glm::vec3(-0.1f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.08f, 0.1f),
        0.0f
    ));

    // Braco direito
    parts.push_back(new Cube(
        glm::vec3(0.1f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.08f, 0.1f),
        0.0f
    ));

    // Almofada esquerda - flatter and wider
    parts.push_back(new Cube(
        glm::vec3(-0.05f, 0.065f, 0.015f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.03f, 0.02f, 0.03f),
        0.0f
    ));

    // Almofada direita - flatter and wider
    parts.push_back(new Cube(
        glm::vec3(0.05f, 0.065f, 0.015f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.03f, 0.02f, 0.03f),
        0.0f
    ));
}

void Sofa::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i = 0; i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i]->bind(0);
        parts[i]->draw(shader, model);
    }
}
