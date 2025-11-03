#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include <vector>

class Sphere : public Object {
public:
    Sphere(glm::vec3 position = glm::vec3(0.0f),
           glm::vec3 rotation = glm::vec3(0.0f),
           glm::vec3 scale = glm::vec3(1.0f),
           float angle = 0.0f,
           int latSegments = 32,
           int lonSegments = 32);

    void draw(Shader& shader, glm::mat4 view) override;

private:
    int latSegments;
    int lonSegments;

    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    GLuint VAO, VBO, EBO;

    void generateSphere();
    void setupBuffers();
};

#endif // SPHERE_H
