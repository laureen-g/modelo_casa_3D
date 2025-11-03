#include "Sphere.h"
#include <cmath>
#include <glm/gtc/type_ptr.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Sphere::Sphere(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, float angle, int latSegments, int lonSegments)
    : Object(position, rotation, scale, angle), latSegments(latSegments), lonSegments(lonSegments)
{
    generateSphere();
}

void Sphere::generateSphere()
{
    vertices.clear();

    // Gerar vértices da esfera usando coordenadas esféricas
    for (int lat = 0; lat <= latSegments; ++lat)
    {
        float theta = lat * M_PI / latSegments; // 0 a PI (polo norte a polo sul)
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);

        for (int lon = 0; lon <= lonSegments; ++lon)
        {
            float phi = lon * 2.0f * M_PI / lonSegments; // 0 a 2PI (volta completa)
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);

            // Posição do vértice (coordenadas cartesianas)
            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;

            // Normal (para iluminação) - aponta para fora da esfera
            float nx = x;
            float ny = y;
            float nz = z;

            // Coordenadas de textura
            float u = (float)lon / lonSegments;
            float v = (float)lat / latSegments;

            // Adicionar vértice: posição (3) + normal (3) + texCoord (2)
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
            vertices.push_back(nx);
            vertices.push_back(ny);
            vertices.push_back(nz);
            vertices.push_back(u);
            vertices.push_back(v);
        }
    }

    // Gerar índices para os triângulos
    indices.clear();
    for (int lat = 0; lat < latSegments; ++lat)
    {
        for (int lon = 0; lon < lonSegments; ++lon)
        {
            int first = lat * (lonSegments + 1) + lon;
            int second = first + lonSegments + 1;

            // Primeiro triângulo
            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            // Segundo triângulo
            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    setupBuffers();
}

void Sphere::setupBuffers()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    // Posição (location = 0)
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

void Sphere::draw(Shader& shader, glm::mat4 view)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(angle), rotation);
    model = glm::scale(model, scale);

    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
