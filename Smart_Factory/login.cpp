#include "login.h"

Login::Login(): NomUtilisateur("admin"),MotDePasse(0)
{

}


Login::Login(QString user_name, long mot_pass):NomUtilisateur(user_name),MotDePasse(mot_pass)
{


}
