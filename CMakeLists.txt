cmake_minimum_required(VERSION 3.23)
project(Jogo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Jogo main.cpp src/Jogo.cpp include/Jogo.h src/Ente/Fases/Pantano.cpp include/Ente/Fases/Pantano.h src/Ente/Fases/Floresta.cpp include/Ente/Fases/Floresta.h  src/Ente/Menus/Menu.cpp include/Ente/Menus/Menu.h src/Listas/ListaEntidades.cpp include/Listas/ListaEntidades.h src/Gerenciadores/Gerenciador_Grafico.cpp include/Gerenciadores/Gerenciador_Grafico.h src/Gerenciadores/Gerenciador_Colisoes.cpp include/Gerenciadores/Gerenciador_Colisoes.h src/Ente/Ente.cpp include/Ente/Ente.h src/Ente/Fases/Fase.cpp include/Ente/Fases/Fase.h src/Ente/Entidades/Projetil.cpp include/Ente/Entidades/Projetil.h src/Ente/Entidades/Entidade.cpp include/Ente/Entidades/Entidade.h src/Ente/Entidades/Personagens/Personagem.cpp include/Ente/Entidades/Personagens/Personagem.h src/Ente/Entidades/Personagens/Jogador.cpp include/Ente/Entidades/Personagens/Jogador.h src/Ente/Entidades/Personagens/Inimigo.cpp include/Ente/Entidades/Personagens/Inimigo.h src/Ente/Entidades/Personagens/Caveira.cpp include/Ente/Entidades/Personagens/Caveira.h src/Ente/Entidades/Personagens/Boitata.cpp include/Ente/Entidades/Personagens/Boitata.h src/Ente/Entidades/Obstaculos/Obstaculo.cpp include/Ente/Entidades/Obstaculos/Obstaculo.h src/Ente/Entidades/Obstaculos/Plataforma.cpp include/Ente/Entidades/Obstaculos/Plataforma.h src/Ente/Entidades/Obstaculos/Espinhos.cpp include/Ente/Entidades/Obstaculos/Espinhos.h include/Ente/Entidades/Obstaculos/Ninho.h src/Ente/Entidades/Obstaculos/Ninho.cpp include/Ente/Entidades/Obstaculos/Piso.h src/Ente/Entidades/Obstaculos/Piso.cpp src/Animacao/Animacao.cpp include/Animacao/Animacao.h src/Animacao/Imagem.cpp include/Animacao/Imagem.h include/Ente/Fases/Fase.h src/Ente/Fases/Fase.cpp src/Ente/Entidades/Personagens/Jogador1.cpp include/Ente/Entidades/Personagens/Jogador1.h src/Ente/Entidades/Personagens/Jogador2.cpp include/Ente/Entidades/Personagens/Jogador2.h src/Ente/Entidades/Personagens/Cogumalefico.cpp include/Ente/Entidades/Personagens/Cogumalefico.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Jogo sfml-system sfml-window sfml-graphics sfml-audio)
