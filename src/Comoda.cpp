#include "Comoda.h"

Comoda::Comoda(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Comoda::init() {
    // Base/corpo principal da cômoda
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.04f, 0.0f),
        glm::vec3(0.0f),
        glm::vec3(0.1f, 0.08f, 0.06f)
    ));

    // Gaveta superior
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.06f, 0.031f),
        glm::vec3(0.0f),
        glm::vec3(0.09f, 0.02f, 0.002f)
    ));

    // Gaveta do meio
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.04f, 0.031f),
        glm::vec3(0.0f),
        glm::vec3(0.09f, 0.02f, 0.002f)
    ));

    // Gaveta inferior
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.02f, 0.031f),
        glm::vec3(0.0f),
        glm::vec3(0.09f, 0.02f, 0.002f)
    ));

    // Pés (4 cantos)
    parts.push_back(new Cube(
        glm::vec3(-0.04f, 0.005f, -0.025f),
        glm::vec3(0.0f),
        glm::vec3(0.01f, 0.01f, 0.01f)
    ));

    parts.push_back(new Cube(
        glm::vec3(0.04f, 0.005f, -0.025f),
        glm::vec3(0.0f),
        glm::vec3(0.01f, 0.01f, 0.01f)
    ));

    parts.push_back(new Cube(
        glm::vec3(-0.04f, 0.005f, 0.025f),
        glm::vec3(0.0f),
        glm::vec3(0.01f, 0.01f, 0.01f)
    ));

    parts.push_back(new Cube(
        glm::vec3(0.04f, 0.005f, 0.025f),
        glm::vec3(0.0f),
        glm::vec3(0.01f, 0.01f, 0.01f)
    ));
}

void Comoda::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i = 0; i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i % textures.size()]->bind(0);
        parts[i]->draw(shader, model);
    }
}
