#ifndef COMODA_H
#define COMODA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <Cube.h>
#include <Prism.h>
#include <Shader.h>
#include <Texture.h>

class Comoda {
private:
    glm::vec3 position;
    float rotationAngle;
    std::vector<Cube*> parts;

    void init();

public:
    Comoda(glm::vec3 pos, float rotation);
    void draw(Shader& shader, glm::mat4 model, const std::vector<Texture*>& textures);
};

#endif
