#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <map>
#include <string>
#include "base.h"
#include "group.h"
#include <memory>

using namespace std;

class Catalogue
{

private:
    map<string,shared_ptr<Base>> multimedia;
    map<string,shared_ptr<Group>> groups;
    //map<string, Base*> multimedia;
    //map<string, Group*> groups;

public:
    Catalogue();
    virtual void createPhoto(string n, string pathname, double lat, double lon);
    virtual void createVideo(string n, string pathname, int duree);
    virtual void createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num);
    virtual void createGroup(string n);
//    virtual void addToGroup(string m, string g);
    virtual void supprimer(string p);
    virtual void rechercher(string p);
    virtual void jouer(string p);
    virtual ~Catalogue();
};

#endif // CATALOGUE_H
