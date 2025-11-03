#ifndef CASA_H
#define CASA_H

#include <Cube.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>


class Casa
{
    public:
        Casa();
        void draw(Shader& shader, glm::mat4 view);

    private:
};

#endif // CASA_H
