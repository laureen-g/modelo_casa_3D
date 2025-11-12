#include "Prism.h"
#include <cmath>
#include <glm/gtc/type_ptr.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Prism::Prism(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, float angle, int sides, float height)
    : Object(position, rotation, scale, angle), sides(sides), height(height)
{
    generatePrism();
}

void Prism::generatePrism()
{
    vertices.clear();
    indices.clear();

    float radius = 1.0f;
    float halfHeight = height / 2.0f;

    // Gerar vrtices da base inferior e superior
    for (int i = 0; i <= sides; ++i)
    {
        float angle = (float)i * 2.0f * M_PI / sides;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Vrtice da base inferior
        vertices.push_back(x);
        vertices.push_back(-halfHeight);
        vertices.push_back(z);
        // Normal apontando para baixo
        vertices.push_back(0.0f);
        vertices.push_back(-1.0f);
        vertices.push_back(0.0f);
        // Coordenadas de textura
        vertices.push_back((float)i / sides);
        vertices.push_back(0.0f);

        // Vrtice da base superior
        vertices.push_back(x);
        vertices.push_back(halfHeight);
        vertices.push_back(z);
        // Normal apontando para cima
        vertices.push_back(0.0f);
        vertices.push_back(1.0f);
        vertices.push_back(0.0f);
        // Coordenadas de textura
        vertices.push_back((float)i / sides);
        vertices.push_back(1.0f);
    }

    // Vrtices para as faces laterais (com normais corretas)
    int lateralStart = (sides + 1) * 2;
    for (int i = 0; i <= sides; ++i)
    {
        float angle = (float)i * 2.0f * M_PI / sides;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        // Normal da face lateral (perpendicular face)
        float nx = cos(angle);
        float nz = sin(angle);

        // Vrtice inferior da face lateral
        vertices.push_back(x);
        vertices.push_back(-halfHeight);
        vertices.push_back(z);
        vertices.push_back(nx);
        vertices.push_back(0.0f);
        vertices.push_back(nz);
        vertices.push_back((float)i / sides);
        vertices.push_back(0.0f);

        // Vrtice superior da face lateral
        vertices.push_back(x);
        vertices.push_back(halfHeight);
        vertices.push_back(z);
        vertices.push_back(nx);
        vertices.push_back(0.0f);
        vertices.push_back(nz);
        vertices.push_back((float)i / sides);
        vertices.push_back(1.0f);
    }

    // Gerarndices para as faces laterais
    for (int i = 0; i < sides; ++i)
    {
        int base = lateralStart + i * 2;

        // Primeiro tringulo da face lateral
        indices.push_back(base);
        indices.push_back(base + 2);
        indices.push_back(base + 1);

        // Segundo tringulo da face lateral
        indices.push_back(base + 1);
        indices.push_back(base + 2);
        indices.push_back(base + 3);
    }

    // Gerarndices para a base inferior (tringulos em leque)
    for (int i = 1; i < sides; ++i)
    {
        indices.push_back(0);           // Centro da base inferior
        indices.push_back(i * 2 + 2);   // Prximo vrtice
        indices.push_back(i * 2);       // Vrtice atual
    }

    // Gerarndices para a base superior (tringulos em leque)
    for (int i = 1; i < sides; ++i)
    {
        indices.push_back(1);           // Centro da base superior
        indices.push_back(i * 2 + 1);   // Vrtice atual
        indices.push_back(i * 2 + 3);   // Prximo vrtice
    }

    setupBuffers();
}

void Prism::setupBuffers()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Posio (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // Normal (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    // Coordenadas de textura (location = 2)
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Prism::draw(Shader& shader, glm::mat4 model)
{
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(angle), rotation);
    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
