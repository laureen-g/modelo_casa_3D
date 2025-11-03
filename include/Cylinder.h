#ifndef CYLINDER_H
#define CYLINDER_H


#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Object.h>
#include <vector>

class Cylinder : public Object {
public:

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    float angle;
    int segments; // número de segmentos ao redor do cilindro

    Cylinder(glm::vec3 pos = glm::vec3(0.0f),
             glm::vec3 rot = glm::vec3(0.0f),
             glm::vec3 scl = glm::vec3(1.0f),
             float ang = 0.0f,
             int segs = 32);

    void draw(Shader &shader, glm::mat4 model);
    ~Cylinder();

private:
    unsigned int VAO, VBO, EBO;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    void init();
    void generateCylinderGeometry();
};

#endif // CYLINDER_H
