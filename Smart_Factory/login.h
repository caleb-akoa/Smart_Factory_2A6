#ifndef LOGIN_H
#define LOGIN_H
#include <QString>

class Login
{
public:
    QString NomUtilisateur;
    long MotDePasse;
    Login();
    Login(QString, long);

};

#endif // LOGIN_H
