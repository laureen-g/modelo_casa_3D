#include "Geladeira.h"

Geladeira::Geladeira(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Geladeira::init() {

    // Corpo principal da geladeira
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.125f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.15f, 0.25f, 0.15f),
        0.0f
    ));

    // Porta superior
    parts.push_back(new Cube(
        glm::vec3(0.08f, 0.19f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.12f, 0.14f),
        0.0f
    ));

    // Porta inferior
    parts.push_back(new Cube(
        glm::vec3(0.08f, 0.06f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.01f, 0.12f, 0.14f),
        0.0f
    ));

    // Puxador superior
    parts.push_back(new Cube(
        glm::vec3(0.09f, 0.22f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.005f, 0.02f, 0.01f),
        0.0f
    ));

    // Puxador inferior
    parts.push_back(new Cube(
        glm::vec3(0.09f, 0.09f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.005f, 0.02f, 0.01f),
        0.0f
    ));
}

void Geladeira::draw(Shader& shader, glm::mat4 model,  const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i=0;i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i]->bind(0);
        parts[i]->draw(shader, model);
    }
}
