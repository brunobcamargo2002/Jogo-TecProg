cmake_minimum_required(VERSION 3.23)
project(Jogo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jogo main.cpp src/Jogo.cpp include/Jogo.h src/Menu.cpp include/Menu.h src/Listas/ListaEntidades.cpp include/Listas/ListaEntidades.h src/Gerenciadores/Gerenciador_Grafico.cpp include/Gerenciadores/Gerenciador_Grafico.h src/Gerenciadores/Gerenciador_Colisoes.cpp include/Gerenciadores/Gerenciador_Colisoes.h src/Ente/Ente.cpp include/Ente/Ente.h src/Menu.cpp include/Menu.h src/Ente/Menus/Main_Menu.cpp include/Ente/Menus/Main_Menu.h src/Ente/Fases/Fase.cpp include/Ente/Fases/Fase.h src/Ente/Fases/Primeira_Fase.cpp include/Ente/Fases/Primeira_Fase.h src/Ente/Fases/Segunda_Fase.cpp include/Ente/Fases/Segunda_Fase.h src/Ente/Entidades/Projetil.cpp include/Ente/Entidades/Projetil.h src/Ente/Entidades/Entidade.cpp include/Ente/Entidades/Entidade.h src/Ente/Entidades/Personagens/Personagem.cpp include/Ente/Entidades/Personagens/Personagem.h src/Ente/Entidades/Personagens/Jogador.cpp include/Ente/Entidades/Personagens/Jogador.h src/Ente/Entidades/Personagens/Inimigo.cpp include/Ente/Entidades/Personagens/Inimigo.h src/Ente/Entidades/Personagens/Inim_TipoA.cpp include/Ente/Entidades/Personagens/Inim_TipoA.h src/Ente/Entidades/Personagens/Inim_TipoB.cpp include/Ente/Entidades/Personagens/Inim_TipoB.h src/Ente/Entidades/Obstaculos/Obstaculo.cpp include/Ente/Entidades/Obstaculos/Obstaculo.h src/Ente/Entidades/Obstaculos/Plataforma.cpp include/Ente/Entidades/Obstaculos/Plataforma.h src/Ente/Entidades/Obstaculos/Obst_TipoB.cpp include/Ente/Entidades/Obstaculos/Obst_TipoB.h include/Animacao/Animacao.cpp include/Animacao/Animacao.h include/Animacao/Imagem.cpp include/Animacao/Imagem.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Jogo sfml-system sfml-window sfml-graphics sfml-audio)
