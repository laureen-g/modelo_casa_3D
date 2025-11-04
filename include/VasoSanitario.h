#ifndef VASOSANITARIO_H
#define VASOSANITARIO_H

#include <Cube.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>
#include <vector>

class VasoSanitario {
public:
    VasoSanitario(glm::vec3 pos = glm::vec3(0.0f), float rotation = 0.0f);
    void draw(Shader& shader, glm::mat4 model);

private:
    glm::vec3 position;
    float rotationAngle;
    std::vector<Cube*> parts;
    void init();
};

#endif // VASOSANITARIO_H
