//
// Created by brunoborgescamargo on 10/22/22.

#include <iostream>

namespace Listas {

    template<class TL>
    class Lista {

    private:
        template<class TE>
        class Elemento {
        private:
            Elemento<TE> *pProx;
            TE *pInfo;

        public:
            Elemento() : pProx(NULL), pInfo(NULL) {}

            ~Elemento() {
                pProx = NULL;
                pInfo = NULL;
            }

        public:
            void setInfo(TE *info) {
                pInfo = info;
            }

            TE *getInfo() {
                return pInfo;
            }

            void setProx(Elemento<TE> *prox) {
                pProx = prox;
            }

            Elemento<TE> *getProx() {
                return pProx;
            }
        };

        Elemento<TL> *pPrimeiro;
        Elemento<TL> *pUltimo;

    public:
        void push_front(TL *conteudo);

        void push_back(TL *conteudo);

        TL *pop_front();

        TL *pop_back();

    public:
        Lista() {
            pPrimeiro = NULL;
            pUltimo = NULL;
        }

        ~Lista() {
            Elemento<TL> *aux1 = pPrimeiro, *aux2 = NULL;
            while (aux1 != NULL) {
                aux2 = aux1->getProx();
                delete (aux1);
                aux1 = aux2;
            }
            pPrimeiro = NULL;
            pUltimo = NULL;
        }
    };

    template<class TL>
    void Lista<TL>::push_front(TL *conteudo) {
        Elemento<TL> *elemento = new Elemento<TL>;

        if (elemento != NULL) {
            elemento->setInfo(conteudo);
            elemento->setProx(pPrimeiro);
            pPrimeiro = elemento;
            if (pUltimo == NULL)
                pUltimo = elemento;
        } else
            std::cerr << "O elemento não foi criado" << std::endl;

    }

    template<class TL>
    void Lista<TL>::push_back(TL *conteudo) {
        Elemento<TL> *elemento = new Elemento<TL>;

        if (elemento != NULL) {
            elemento->setInfo(conteudo);
            if (pUltimo != NULL)
                pUltimo->setProx(elemento);
            else
                pPrimeiro = elemento;
            pUltimo = elemento;
        } else
            std::cerr << "O elemento não foi criado" << std::endl;
    }

    template<class TL>
    TL *Lista<TL>::pop_front() {
        if (pPrimeiro != NULL) {
            TL *info = pPrimeiro->getInfo();
            Elemento<TL> *proximo = pPrimeiro->getProx();
            delete pPrimeiro;
            pPrimeiro = proximo;
            return info;
        } else
            return NULL;
    }

    template<class TL>
    TL *Lista<TL>::pop_back() {
        int i;
        if (pPrimeiro != NULL) {
            Elemento<TL> *ant = pPrimeiro;
            Elemento<TL> *prox = pPrimeiro->getProx();
            TL *conteudo = pUltimo->getInfo();
            if (prox == NULL) {
                delete ant;
                pPrimeiro = NULL;
                pUltimo = NULL;
                return conteudo;
            }
            while (prox->getProx() != NULL) {
                ant = prox;
                prox = prox->getProx();
            }
            ant->setProx(NULL);
            delete pUltimo;
            pUltimo = ant;
            return conteudo;
        }
    }

}





#ifndef UNTITLED_LENC_SIMPLES_H
#define UNTITLED_LENC_SIMPLES_H

#endif //UNTITLED_LENC_SIMPLES_H
