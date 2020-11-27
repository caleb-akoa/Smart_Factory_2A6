#ifndef GESTION_H
#define GESTION_H
#include <QString>

class Gestion
{

public:

    QString NomUtilisateur;
    long MotDePasse;
    Gestion();
    Gestion(QString, long);

};

#endif // GESTION_H
