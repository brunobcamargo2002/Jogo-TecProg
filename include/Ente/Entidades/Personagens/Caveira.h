#ifndef INIM_TIPOA_H
#define INIM_TIPOA_H

#include "Inimigo.h"

namespace Entidades {
    class Caveira : public Inimigo {
    public:
        Caveira();

        virtual ~Caveira();

    private:
        void atualizarAnimacao();
    };

}

#endif // INIM_TIPOA_H
