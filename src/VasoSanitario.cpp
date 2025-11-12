#include "VasoSanitario.h"

VasoSanitario::VasoSanitario(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void VasoSanitario::init() {

    // Base/pedestal (cilindro curto e largo)
    parts.push_back(new Cylinder(
        glm::vec3(0.0f, 0.005f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.02f, 0.01f, 0.02f),
        0.0f,
        16
    ));

    // Bacia principal (cilindro mais proporcional)
    parts.push_back(new Cylinder(
        glm::vec3(0.0f, 0.025f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.022f, 0.04f, 0.022f),
        0.0f,
        20
    ));

    // Tampa/assento (cubo achatado em cima da bacia)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.052f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.025f, 0.004f, 0.027f),
        0.0f
    ));

    // Caixa acoplada atras (cubo vertical, menor e mais proporcional)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.045f, -0.025f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.028f, 0.04f, 0.016f),
        0.0f
    ));
}

void VasoSanitario::draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        shader.use();
        shader.setInt("texture1", 0);
        textures[0]->bind(0);
        part->draw(shader, model);
    }
}
