#include "Luminaria.h"

Luminaria::Luminaria(glm::vec3 pos, float rotation)
    : position(pos), rotationAngle(rotation) {
    init();
}

void Luminaria::init() {
    // Base da luminaria (cubo largo e achatado no chao)
    parts.push_back(new Cube(
        glm::vec3(0.0f, 0.008f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.04f, 0.016f, 0.04f),
        0.0f
    ));

    // Poste vertical (cilindro fino e alto)
    // Cylinder height=1.0, scale.y=0.16 → vai de -0.08 a +0.08 local
    // Em y=0.09: vai de 0.01 a 0.17 no mundo
    parts.push_back(new Cylinder(
        glm::vec3(0.0f, 0.09f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.008f, 0.16f, 0.008f),
        0.0f,
        16
    ));

    // Prism height=0.08 → halfHeight=0.04
    // Sem scale em Y, vai de -0.04 a +0.04 local
    // Em y=0.17: vai de 0.13 a 0.21 no mundo (conecta ao topo do cilindro em 0.17!)
    parts.push_back(new Prism(
        glm::vec3(0.0f, 0.17f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.035f, 1.0f, 0.035f),
        0.0f,
        8,
        0.08f
    ));
}

void Luminaria::draw(Shader& shader, glm::mat4 model) {
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));

    for (auto part : parts) {
        part->draw(shader, model);
    }
}
