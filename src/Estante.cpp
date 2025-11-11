#include "Estante.h"

Estante::Estante(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Estante::init() {
    // Lateral esquerda
    parts.push_back(new Cube(
        glm::vec3(-0.06f, 0.1f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.2f, 0.08f),
        0.0f
    ));

    // Lateral direita
    parts.push_back(new Cube(
        glm::vec3(0.06f, 0.1f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.2f, 0.08f),
        0.0f
    ));

    // Fundo da estante
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.1f, -0.04f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.12f, 0.2f, 0.005f),
        0.0f
    ));

    // Prateleiras (4 níveis)
    for (int i = 0; i < 4; i++) {
        parts.push_back(new Cube(
            glm::vec3(0.0f, 0.05f * i + 0.01f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.12f, 0.008f, 0.08f),
            0.0f
        ));
    }

    // Suporte triangular esquerdo
    parts.push_back(new Prism(
        glm::vec3(-0.06f, 0.01f, 0.04f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.015f, 0.02f, 0.015f),
        90.0f,
        3,
        1.0f
    ));

    // Suporte triangular direito
    parts.push_back(new Prism(
        glm::vec3(0.06f, 0.01f, 0.04f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(0.015f, 0.02f, 0.015f),
        90.0f,
        3,
        1.0f
    ));
}

void Estante::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (int i = 0; i < parts.size(); i++) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[i]->bind(0);
        parts[i]->draw(shader, model);
    }
}
