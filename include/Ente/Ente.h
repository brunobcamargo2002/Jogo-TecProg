#ifndef ENTE_H
#define ENTE_H


class Ente
{
    private:
        static unsigned int geraId;

    protected:
            unsigned int id;
    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        void imprimir_se();
};




#endif // ENTE_H
