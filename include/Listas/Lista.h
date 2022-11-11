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
        unsigned int tam;

    public:
        Lista() {
            tam = 0;
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

        Elemento<TL>* getPrimeiro(){
            return pPrimeiro;
        }
        void push_front(TL *conteudo);
        void push_back(TL *conteudo);
        TL *pop_front();
        TL *pop_back();
        bool remover(TL* alvo);
        bool empty();
        unsigned int getTamanho(){
            return tam;
        }
        TL* operator[](int pos);

        class Iterador{
        private:
            Elemento<TL>* elemento;
        public:
            bool fim()
            {
                if(elemento == NULL)
                    return true;
                else
                    return false;
            }
            Elemento<TL*> getElemento()
            {
                return elemento;
            }
            TL* getConteudo()
            {
                return elemento->getInfo();
            }


            void operator = (Elemento<TL>* El)
            {
                elemento = El;
            }
            void operator ++()
            {
                elemento = elemento->getProx();
            }
        };



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
            tam++;
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
            tam++;
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
            tam--;
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
            tam--;
        }
        return NULL;
    }

    template<class TL>
    bool Lista<TL>::empty() {
        if(pPrimeiro==NULL)
            return true;
        else
            return false;
    }

    template<class TL>
    TL *Lista<TL>::operator[](int pos) {
        if(pos >= (int)tam || pos < 0){
            std::cout << "ERROR::Lista pos eh maior que o tamanho da lista" << std::endl;
            exit(1);
        }
        Elemento<TL>* aux = pPrimeiro;
        for(int i = 0; i < pos; i++){
            aux = aux->getProx();
        }
        return aux->getInfo();
    }

    template<class TL>
    bool Lista<TL>::remover(TL * alvo) {
        Elemento<TL>* aux1 = pPrimeiro, *aux2 = NULL;

        if(aux1!=NULL){
            if(aux1->getInfo()==alvo){
                pPrimeiro=pPrimeiro->getProx();
                delete aux1;
                tam--;
                return true;
            }
        }

        while(aux1!=NULL){
            aux2= aux1->getProx();
            if(aux2!=NULL){
                if(aux2->getInfo() == alvo){
                    Elemento<TL>* aux3 = aux2->getProx();
                    delete aux2;
                    aux1->setProx(aux3);
                    tam--;
                    return true;
                }
            }
            aux1 = aux2;
        }
        return false;
    }

}





#ifndef UNTITLED_LENC_SIMPLES_H
#define UNTITLED_LENC_SIMPLES_H

#endif //UNTITLED_LENC_SIMPLES_H
