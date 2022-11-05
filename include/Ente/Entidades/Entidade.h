#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../Ente.h"


namespace Entidades {

    class Entidade : public Ente {
    public:
        Entidade();

        virtual ~Entidade();

        int Getx() { return x; }

        void Setx(int val) { x = val; }

        int Gety() { return y; }

        void Sety(int val) { y = val; }

        virtual void executar();

    protected:
        int x;
        int y;

    private:
    };

}

#endif // ENTIDADE_H
