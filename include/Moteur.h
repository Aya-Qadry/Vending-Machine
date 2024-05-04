#ifndef MOTEUR_H
#define MOTEUR_H


class Moteur
{
    public:
        Moteur();
        Moteur(int) ;
        virtual ~Moteur();
        void Trigger() ;

    protected:

    private:
        int id ;

};

#endif // MOTEUR_H
