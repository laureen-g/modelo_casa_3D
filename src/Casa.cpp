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
#include <Abajur.h>
#include <Shader.h>
#include <Texture.h>

Casa::Casa() {
}

void Casa::draw(Shader& shader, glm::mat4 view,
                const std::vector<Texture*>& texCasa,
                const std::vector<Texture*>& texCama,
                const std::vector<Texture*>& texSofa,
                const std::vector<Texture*>& texEstante) {

    shader.use();
    shader.setInt("texture1", 0);
    texCasa[0]->bind(0);

    // CHÃO
    Cube chao(glm::vec3(0.0f, 0.05f, 0.0f),
                    glm::vec3(0.0f),
                    glm::vec3(2.0f, 0.03f, 2.0f));

    chao.draw(shader, view);

    shader.use();
    shader.setInt("texture1", 0);
    texCasa[1]->bind(0);

    // PAREDE DIREITA
    Cube paredeDireita(glm::vec3(1.0f, 0.265f, 0.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 2.0f));

    paredeDireita.draw(shader, view);

    //PAREDE ESQUERDA
    Cube paredeEsquerda(glm::vec3(-1.0f, 0.265f, 0.0f),
                        glm::vec3(0.0f),
                        glm::vec3(0.03f, 0.5f, 2.0f));

    paredeEsquerda.draw(shader, view);

    // PAREDE DA FRENTE
    Cube paredeFrente(glm::vec3(0.15f, 0.265f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(1.7f, 0.5f, 0.03f));

    paredeFrente.draw(shader, view);

    Cube paredeFrente2(glm::vec3(-0.95f, 0.265f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(0.1f, 0.5f, 0.03f));

    paredeFrente2.draw(shader, view);

    Cube paredeFrente3(glm::vec3(-0.8f, 0.44f, 1.0f),
                      glm::vec3(0.0f),
                      glm::vec3(0.2f, 0.15f, 0.03f));

    paredeFrente3.draw(shader, view);

    // PAREDE DO FUNDO
    Cube paredeFundo(glm::vec3(0.0f, 0.265f, -1.0f),
                     glm::vec3(0.0f),
                     glm::vec3(2.0f, 0.5f, 0.03f));

    paredeFundo.draw(shader, view);

    // DIVISORIA COMODOS
    Cube paredeDivisoria(glm::vec3(0.2f, 0.265f, 0.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 1.2f));

    paredeDivisoria.draw(shader, view);

    Cube paredeDivisoria2(glm::vec3(0.2f, 0.265f, -1.0f),
                       glm::vec3(0.0f),
                       glm::vec3(0.03f, 0.5f, 0.03f));

    paredeDivisoria2.draw(shader, view);

    Cube paredeDivisoria20(glm::vec3(0.6f, 0.265f, 0.2f),
                     glm::vec3(0.0f),
                     glm::vec3(0.8f, 0.5f, 0.03f));

    paredeDivisoria20.draw(shader, view);
/*
    // SALA - Sofá, Mesa, Estante e Luminária
    Sofa sofa(glm::vec3(-0.5f, 0.1f, 0.5f), 0.0f);
    sofa.draw(shader, view, texSofa);

    //Mesa mesaSala(glm::vec3(-0.5f, 0.1f, 0.0f), 0.0f);
    //mesaSala.draw(shader, view);

    //Estante estante(glm::vec3(-0.8f, 0.1f, 0.7f), 0.0f);
    //estante.draw(shader, view);

    //Luminaria luminariaLiving(glm::vec3(-0.3f, 0.1f, 0.3f), 0.0f);
    //luminariaLiving.draw(shader, view);

    //Espelho espelho(glm::vec3(-0.2f, 0.1f, 0.7f), 0.0f);
    //espelho.draw(shader, view);
*/
    // QUARTO - Cama
    Cama cama(glm::vec3(0.6f, 0.1f, -0.5f), 90.0f);
    cama.draw(shader, view, texCama);

    //Abajur abajur(glm::vec3(0.8f, 0.1f, -0.3f), 0.0f);
    //abajur.draw(shader, view);

    // COZINHA/SALA DE JANTAR - Mesa, Cadeira e Geladeira
    //Mesa mesaCozinha(glm::vec3(0.6f, 0.1f, 0.6f), 0.0f);
    //mesaCozinha.draw(shader, view);

    //Cadeira cadeira(glm::vec3(0.4f, 0.1f, 0.5f), 0.0f);
    //cadeira.draw(shader, view);

    //Geladeira geladeira(glm::vec3(0.85f, 0.1f, 0.7f), 270.0f);
    //geladeira.draw(shader, view);

    // BANHEIRO - Vaso Sanitário
    //VasoSanitario vaso(glm::vec3(-0.7f, 0.1f, -0.6f), 0.0f);
    //vaso.draw(shader, view);

}
