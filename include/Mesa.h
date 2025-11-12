#ifndef MESA_H
#define MESA_H

#include <Object.h>
#include <Cube.h>
#include <Cylinder.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>
#include <vector>
#include <Texture.h>

class Mesa {
public:
    Mesa(glm::vec3 pos = glm::vec3(0.0f), float rotation = 0.0f);
    void draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures);

private:
    glm::vec3 position;
    float rotationAngle;
    std::vector<Object*> parts;
    void init();
};

#endif // MESA_H
