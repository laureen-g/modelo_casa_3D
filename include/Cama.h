#ifndef CAMA_H
#define CAMA_H

#include <Cube.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>
#include <vector>

class Cama {
public:
    Cama(glm::vec3 pos = glm::vec3(0.0f), float rotation = 0.0f);
    void draw(Shader& shader, glm::mat4 model);

private:
    glm::vec3 position;
    float rotationAngle;
    std::vector<Cube*> parts;
    void init();
};

#endif // CAMA_H
