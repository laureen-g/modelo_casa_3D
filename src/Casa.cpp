#include "Casa.h"
#include <Cube.h>
#include <Sofa.h>
#include <Mesa.h>
#include <Cadeira.h>
#include <Cama.h>
#include <VasoSanitario.h>
#include <Geladeira.h>
#include <Luminaria.h>
#include <Estante.h>
#include <Espelho.h>
#include <Comoda.h>
#include <Shader.h>
#include <Texture.h>

Casa::Casa()
    : chao(glm::vec3(0.0f, 0.05f, 0.0f), glm::vec3(0.0f), glm::vec3(2.0f, 0.03f, 2.0f)),
      paredeDireita(glm::vec3(1.0f, 0.265f, 0.0f), glm::vec3(0.0f), glm::vec3(0.03f, 0.5f, 2.0f)),
      paredeEsquerda(glm::vec3(-1.0f, 0.265f, 0.0f), glm::vec3(0.0f), glm::vec3(0.03f, 0.5f, 2.0f)),
      paredeFrente(glm::vec3(0.15f, 0.265f, 1.0f), glm::vec3(0.0f), glm::vec3(1.7f, 0.5f, 0.03f)),
      paredeFrente2(glm::vec3(-0.95f, 0.265f, 1.0f), glm::vec3(0.0f), glm::vec3(0.1f, 0.5f, 0.03f)),
      paredeFrente3(glm::vec3(-0.8f, 0.44f, 1.0f), glm::vec3(0.0f), glm::vec3(0.2f, 0.15f, 0.03f)),
      paredeFundo(glm::vec3(0.0f, 0.265f, -1.0f), glm::vec3(0.0f), glm::vec3(2.0f, 0.5f, 0.03f)),
      paredeDivisoria(glm::vec3(0.2f, 0.265f, 0.0f), glm::vec3(0.0f), glm::vec3(0.03f, 0.5f, 1.2f)),
      paredeDivisoria2(glm::vec3(0.2f, 0.265f, -1.0f), glm::vec3(0.0f), glm::vec3(0.03f, 0.5f, 0.03f)),
      paredeDivisoria20(glm::vec3(0.6f, 0.265f, 0.2f), glm::vec3(0.0f), glm::vec3(0.8f, 0.5f, 0.03f)),

      // Objetos da casa
      sofa(glm::vec3(-0.5f, 0.05f, 0.5f), 180.0f),
      mesaSala(glm::vec3(-0.5f, 0.05f, 0.3f), 0.0f),
      estante(glm::vec3(-0.95f, 0.05f, 0.4f), 90.0f),
      espelho(glm::vec3(-0.2f, 0.05f, 0.95f), 0.0f),
      luminaria(glm::vec3(-0.6f, 0.05f, 0.2f), 0.0f),
      cama(glm::vec3(0.6f, 0.05f, -0.5f), 270.0f),
      comoda(glm::vec3(0.70f, 0.05f, -0.35f), 270.0f),
      mesaCozinha(glm::vec3(0.6f, 0.05f, 0.6f), 0.0f),
      cadeira(glm::vec3(0.6f, 0.05f, 0.45f), 0.0f),
      geladeira(glm::vec3(0.95f, 0.05f, 0.7f), 0.0f),
      vaso(glm::vec3(-0.7f, 0.05f, -0.6f), 0.0f)
{}

void Casa::draw(Shader& shader, glm::mat4 view,
                const std::vector<Texture*>& texCasa,
                const std::vector<Texture*>& texCama,
                const std::vector<Texture*>& texSofa,
                const std::vector<Texture*>& texEstante,
                const std::vector<Texture*>& texEspelho,
                const std::vector<Texture*>& texCadeira,
                const std::vector<Texture*>& texMesa,
                const std::vector<Texture*>& texGeladeira,
                const std::vector<Texture*>& texVaso,
                const std::vector<Texture*>& texLuminaria) {

    shader.use();
    shader.setInt("texture1", 0);

    // Textura e desenho do chão
    texCasa[0]->bind(0);
    chao.draw(shader, view);

    // Paredes
    texCasa[1]->bind(0);
    paredeDireita.draw(shader, view);
    paredeEsquerda.draw(shader, view);
    paredeFrente.draw(shader, view);
    paredeFrente2.draw(shader, view);
    paredeFrente3.draw(shader, view);
    paredeFundo.draw(shader, view);
    paredeDivisoria.draw(shader, view);
    paredeDivisoria2.draw(shader, view);
    paredeDivisoria20.draw(shader, view);

    // Objetos (cada um com sua textura)
    sofa.draw(shader, view, texSofa);
    mesaSala.draw(shader, view, texMesa);
    estante.draw(shader, view, texEstante);
    espelho.draw(shader, view, texEspelho);
    luminaria.draw(shader, view, texLuminaria);
    cama.draw(shader, view, texCama);
    comoda.draw(shader, view, texEstante);
    mesaCozinha.draw(shader, view, texMesa);
    cadeira.draw(shader, view, texCadeira);
    geladeira.draw(shader, view, texGeladeira);
    vaso.draw(shader, view, texVaso);

}
