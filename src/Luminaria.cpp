#include "Luminaria.h"

Luminaria::Luminaria(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Luminaria::init() {

    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.008f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.04f, 0.016f, 0.04f),
        0.0f
    ));

    parts.push_back(new Cylinder(
        glm::vec3(0.0f, 0.1f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.19f, 0.008f),
        0.0f,
        16
    ));

    parts.push_back(new Prism(
        glm::vec3(0.0f, 0.20f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.06f, 0.06f, 0.06f),
        0.0f,
        8,
        0.22f
    ));
}

void Luminaria::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i=0; i < 3; i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i % textures.size()]->bind(0);
        parts[i]->draw(shader, model);
    }
}
