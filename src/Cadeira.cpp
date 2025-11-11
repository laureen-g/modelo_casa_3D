#include "Cadeira.h"

Cadeira::Cadeira(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Cadeira::init() {
    // Assento
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.05f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.05f, 0.01f, 0.05f),
        0.0f
    ));

    // Encosto
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.085f, -0.02f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.05f, 0.07f, 0.01f),
        0.0f
    ));

    // Perna frontal esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.02f, 0.025f, 0.02f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.05f, 0.008f),
        0.0f
    ));

    // Perna frontal direita
    parts.push_back(new Cube(
        glm::vec3(0.02f, 0.025f, 0.02f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.05f, 0.008f),
        0.0f
    ));

    // Perna traseira esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.02f, 0.025f, -0.02f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.05f, 0.008f),
        0.0f
    ));

    // Perna traseira direita
    parts.push_back(new Cube(
        glm::vec3(0.02f, 0.025f, -0.02f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.05f, 0.008f),
        0.0f
    ));
}

void Cadeira::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i=0; i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i]->bind(0);
        parts[i]->draw(shader, model);
    }
}
