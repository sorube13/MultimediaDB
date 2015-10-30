#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <map>
#include <string>

using namespace std;

class Catalogue
{

private:
    map<string,Base*> multimedia;
    map<string,Group*> groups;

public:
    Catalogue();
    virtual void createPhoto(string n, string pathname, double lat, double lon);
    virtual void createVideo(string n, string pathname, int duree);
    virtual void createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num);
    virtual void createGroup(string n);
//    virtual void addToGroup(string m, string g);
    virtual void supprimer(string p);
    virtual void rechercher(string p);
    virtual ~Catalogue();
};

#endif // CATALOGUE_H
