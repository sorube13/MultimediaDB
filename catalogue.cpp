#include "catalogue.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include <memory>

using namespace std;

Catalogue::Catalogue(){}

void Catalogue::createPhoto(string n, string pathname, double lat, double lon){
    shared_ptr<Photo> p(new Photo(n, pathname, lat, lon));
    multimedia[n] = p.get();
    multimedia[n]->affichage(cout);
}

void Catalogue::createVideo(string n, string pathname, int duree){
    shared_ptr<Video> v(new Video(n, pathname, duree));
    multimedia[n] = v.get();
}

void Catalogue::createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num){
    shared_ptr<Film> f(new Film(n, pathname, duree));
    f.get()->setDurees(tab, num);
    multimedia[n] = f.get();

}

void Catalogue::createGroup(string n){
    shared_ptr<Group> g(new Group(n));
    groups[n] = g.get();
}

//void Catalogue::addToGroup(string m, string g){
//    groups[g]->push_back(multimedia[m]);

//    cout << "ADDED TO GROUP" << endl;
//}

void Catalogue::supprimer(string p){
    if(multimedia.find(p) != multimedia.end()){
       multimedia.erase(p);
       //cout << "Deleted multimedia" << endl;
//       for (map<string,Group*>::iterator it=groups.begin(); it!=groups.end(); ++it){
//           for (list<Base*>::const_iterator lit = (*it)->begin(); lit != (*it)->end(); lit++){
//               if((*lit)->getName() == p){
//                   (*it)->remove(p);
//                   cout << "Deleted multimedia" << endl;
//               }
//           }
//       }
    }
    else if(groups.find(p) != groups.end()){
        groups.erase(p);
        cout << "Deleted Group" << endl;
    }
}

void Catalogue::rechercher(string p){
    if(multimedia.find(p) != multimedia.end()){
        multimedia[p]->affichage(cout);
    }else if(groups.find(p) != groups.end()){
       groups[p]->affichage(cout);
    }else{
        cout << "Not Found" << endl;
    }
}

Catalogue::~Catalogue(){
    cout << "Catalogue deleted" << endl;
}


