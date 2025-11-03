#include "Cylinder.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Cylinder::Cylinder(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl, float angle, int segs)
    : position(pos), rotation(rot), scale(scl), angle(angle), segments(segs) {
    generateCylinderGeometry();
    init();
}

Cylinder::~Cylinder() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cylinder::generateCylinderGeometry() {
    float radius = 0.5f;
    float height = 1.0f;
    float halfHeight = height / 2.0f;

    vertices.clear();
    indices.clear();

    // Gerar vértices para o corpo do cilindro
    for (int i = 0; i <= segments; ++i) {
        float theta = (float)i / (float)segments * 2.0f * M_PI;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        float u = (float)i / (float)segments;

        // Vértice superior
        vertices.push_back(x);           // posição x
        vertices.push_back(halfHeight);  // posição y
        vertices.push_back(z);           // posição z
        vertices.push_back(u);           // tex coord u
        vertices.push_back(1.0f);        // tex coord v

        // Vértice inferior
        vertices.push_back(x);           // posição x
        vertices.push_back(-halfHeight); // posição y
        vertices.push_back(z);           // posição z
        vertices.push_back(u);           // tex coord u
        vertices.push_back(0.0f);        // tex coord v
    }

    // Índices para o corpo do cilindro
    for (int i = 0; i < segments; ++i) {
        int top1 = i * 2;
        int bottom1 = i * 2 + 1;
        int top2 = (i + 1) * 2;
        int bottom2 = (i + 1) * 2 + 1;

        // Primeiro triângulo
        indices.push_back(top1);
        indices.push_back(bottom1);
        indices.push_back(top2);

        // Segundo triângulo
        indices.push_back(top2);
        indices.push_back(bottom1);
        indices.push_back(bottom2);
    }

    // Centro da tampa superior
    int topCenterIndex = vertices.size() / 5;
    vertices.push_back(0.0f);        // x
    vertices.push_back(halfHeight);  // y
    vertices.push_back(0.0f);        // z
    vertices.push_back(0.5f);        // u
    vertices.push_back(0.5f);        // v

    // Centro da tampa inferior
    int bottomCenterIndex = topCenterIndex + 1;
    vertices.push_back(0.0f);        // x
    vertices.push_back(-halfHeight); // y
    vertices.push_back(0.0f);        // z
    vertices.push_back(0.5f);        // u
    vertices.push_back(0.5f);        // v

    // Vértices da borda para as tampas
    for (int i = 0; i <= segments; ++i) {
        float theta = (float)i / (float)segments * 2.0f * M_PI;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        float u = (cos(theta) + 1.0f) * 0.5f;
        float v = (sin(theta) + 1.0f) * 0.5f;

        // Tampa superior
        vertices.push_back(x);
        vertices.push_back(halfHeight);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(v);

        // Tampa inferior
        vertices.push_back(x);
        vertices.push_back(-halfHeight);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(v);
    }

    int capStartIndex = bottomCenterIndex + 1;

    // Índices para tampa superior
    for (int i = 0; i < segments; ++i) {
        indices.push_back(topCenterIndex);
        indices.push_back(capStartIndex + i * 2);
        indices.push_back(capStartIndex + (i + 1) * 2);
    }

    // Índices para tampa inferior
    for (int i = 0; i < segments; ++i) {
        indices.push_back(bottomCenterIndex);
        indices.push_back(capStartIndex + (i + 1) * 2 + 1);
        indices.push_back(capStartIndex + i * 2 + 1);
    }
}

void Cylinder::init() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // tex coords
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Cylinder::draw(Shader &shader, glm::mat4 model) {

    model = glm::translate(model, position);

    if (glm::length(rotation) > 0.0f)
        model = glm::rotate(model, glm::radians(angle), glm::normalize(rotation));

    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
