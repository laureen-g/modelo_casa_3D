#ifndef PRISM_H
#define PRISM_H

#include "Object.h"
#include <vector>

class Prism : public Object {
public:
    Prism(glm::vec3 position = glm::vec3(0.0f),
          glm::vec3 rotation = glm::vec3(0.0f),
          glm::vec3 scale = glm::vec3(1.0f),
          float angle = 0.0f,
          int sides = 3,
          float height = 2.0f);

    void draw(Shader& shader, glm::mat4 model) override;

private:
    int sides;
    float height;

    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    GLuint VAO, VBO, EBO;

    void generatePrism();
    void setupBuffers();
};

#endif // PRISM_H
