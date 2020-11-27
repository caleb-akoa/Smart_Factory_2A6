#include "gestion.h"
#include <QString>
Gestion::Gestion(): NomUtilisateur("admin"),MotDePasse(0)
{

}

Gestion::Gestion(QString user_name, long mot_pass):NomUtilisateur(user_name),MotDePasse(mot_pass)
{


}

