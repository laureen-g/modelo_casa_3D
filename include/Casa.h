#ifndef CASA_H
#define CASA_H

#include <Cube.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Shader.h>
#include <Texture.h>
#include <vector>

#include "Sofa.h"
#include "Mesa.h"
#include "Cadeira.h"
#include "Cama.h"
#include "VasoSanitario.h"
#include "Geladeira.h"
#include "Luminaria.h"
#include "Estante.h"
#include "Espelho.h"
#include "Abajur.h"

class Casa
{
    public:
        Casa();
        void draw(Shader& shader, glm::mat4 view,
          const std::vector<Texture*>& texCasa,
          const std::vector<Texture*>& texCama,
          const std::vector<Texture*>& texSofa,
          const std::vector<Texture*>& texEstante,
          const std::vector<Texture*>& texEspelho,
          const std::vector<Texture*>& texCadeira,
          const std::vector<Texture*>& texMesa,
          const std::vector<Texture*>& texGeladeira,
          const std::vector<Texture*>& texVaso,
          const std::vector<Texture*>& texLuminaria);

    private:
};

#endif // CASA_H
