#ifndef ABAJUR_H
#define ABAJUR_H

#include <Cube.h>
#include <Cylinder.h>
#include <Prism.h>
#include <Object.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>
#include <vector>

class Abajur {
public:
    Abajur(glm::vec3 pos = glm::vec3(0.0f), float rotation = 0.0f);
    void draw(Shader& shader, glm::mat4 model);

private:
    glm::vec3 position;
    float rotationAngle;
    std::vector<Object*> parts;
    void init();
};

#endif // ABAJUR_H
