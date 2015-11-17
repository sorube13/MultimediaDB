#include "catalogue.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdio.h>
#include <string.h>

using namespace std;


Catalogue::Catalogue(){}


/**
  * Exception InvalidCaracters that will be launched if there are any special characters
 **/
class InvalidCaracters: public exception
{
    const char* what() const noexcept {return "Incorrect characters\n";}
};

/**
 * @brief HasSpecialCharacters
 * @param str
 * @return 0 if str does not have special characters or 1 if it does
 */
bool HasSpecialCharacters(const char *str)
{
    return str[strspn(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.-:/")] != 0;
}


void Catalogue::createPhoto(string n, string pathname, double lat, double lon){
    try{
        if(multimedia[n]){
            cerr << "A photo with the name: " << n <<" already exists" << endl;
        }else if(HasSpecialCharacters(n.c_str())==1) throw InvalidCaracters();

        else{
            shared_ptr<Photo> p(new Photo(n, pathname, lat, lon));
            multimedia[n] = p;
        }
    }catch(exception& e){
        cerr<< e.what() << endl;
    }
}


void Catalogue::createVideo(string n, string pathname, int duree){
    try{
        if(multimedia[n]){
            cerr << "A video with the name " << n <<" already exists" << endl;
        }else if(HasSpecialCharacters(n.c_str())==1) throw InvalidCaracters();

        else{
            shared_ptr<Video> v(new Video(n, pathname, duree));
            multimedia[n] = v;
        }
    }catch(exception& e){
        cerr<< e.what() << endl;
    }
}


void Catalogue::createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num){
    try{
        if(multimedia[n]){
            cerr << "A film with the name " << n << " already exists" << endl;
        }else if((sizeof(tab) <= 0) || (num<=0)){
            cerr << "Incorrect film initialization of chapters for film: "<< n << endl;
        }
        else if (HasSpecialCharacters(n.c_str())==1) throw InvalidCaracters();

        else{
            shared_ptr<Film> f(new Film(n, pathname, duree));
            f.get()->setDurees(tab, num);
            multimedia[n] = f;
        }
    }catch(exception& e){
        cerr<< e.what() << endl;
    }
}


void Catalogue::createGroup(string n){
    try{
        if(groups[n]){
            cerr << "A Group with the name " << n << " already exists" << endl;
        }
        else if(HasSpecialCharacters(n.c_str())==1) throw InvalidCaracters();
        else{
            shared_ptr<Group> g(new Group(n));
            groups[n] = g;
        }
    }catch(exception& e){
        cerr<< e.what() << endl;
    }
}


void Catalogue::supprimerMultimedia(string p){
    if(multimedia.find(p) != multimedia.end()){
        map<string, shared_ptr<Base> >::const_iterator m = this->multimedia.find(p);
        for (map<string, shared_ptr<Group> >::const_iterator it = this->groups.begin(); it != this->groups.end(); ++it){
            (it->second)->remove((m->second).get());
        }
        this->multimedia.erase(p);
        cout << "Deleted Multimedia: "<< p << endl;
    }else{
        cerr << p << " Not Found" << endl;
    }
}


void Catalogue::supprimerGroup(string p){
    if(groups.find(p) != groups.end()){
        groups.erase(p);
        cout << "Deleted Group: " << p << endl;
    }else{
        cerr << p << " Not Found" << endl;
    }
}


string Catalogue::rechercherMultimedia(string p, ostream & s){
    if(multimedia.find(p) != multimedia.end()){
        map<string, shared_ptr<Base> >::const_iterator m = this->multimedia.find(p);
        cout << "Multimedia search result: " << endl;
        string resp = (m->second)->affichage(s);
        return resp;
    }else{
        cerr << p << " Not Found" << endl;
        return "Not Found";
    }
}


string Catalogue::rechercherGroup(string p, ostream &s){
    if(groups.find(p) != groups.end()){
        map<string, shared_ptr<Group> >::const_iterator m = this->groups.find(p);
        cout << "Group search result: " << endl;
        string resp = (m->second)->affichage(s);
        return resp;
    }else{
        cerr << p << "Not Found" << endl;
        return "Not Found";
    }
}


void Catalogue::jouer(string p){
    if(multimedia.find(p) != multimedia.end()){
        map<string, shared_ptr<Base> >::const_iterator m = this->multimedia.find(p);
        cout << "Opening "<< p << endl;
        (m->second)->openObject();
    }else{
        cerr << "Not Found" << endl;
    }
}



bool Catalogue::save(const string &fileName) {
    ofstream f;
    f.open(fileName);
    if (!f) {
        cerr << "Can't open file " << fileName << endl;
        return false;
    }
    for (map<string, shared_ptr<Base> >::const_iterator it = this->multimedia.begin(); it != this->multimedia.end(); ++it){
        (it->second)->affichage(f);
    }
    f.close();
    return true;
}


bool Catalogue::load(const string &fileName){
    ifstream f;
    string type;
    f.open(fileName);
    if(!f){
        cerr << "Can't open file " << fileName << endl;
        return false;
    }
    while(f.good()){
        getline(f,type);
        if(type=="Photo"){
            string arg;
            stringstream args;
            string name, pathname;
            int lat,lon;
            getline(f,arg);
            args << arg;
            args >> name >> pathname >> lat >> lon;
            createPhoto(name, pathname,lat, lon);
            cout << "created Photo" << endl;
        }
        if(type=="Video"){
            string arg;
            stringstream args;
            string name, pathname;
            int duree;
            getline(f,arg);
            args << arg;
            args >> name >> pathname >> duree;
            createVideo(name, pathname,duree);
            cout << "created Video" << endl;
        }
        if(type=="Film"){
            string arg;
            stringstream args;
            string name, pathname;
            int duree;
            unsigned int count;
            getline(f,arg);
            args << arg;
            args >> name >> pathname >> duree >> count;
            unsigned int d [count];
            for(unsigned int i=0; i<count; i++){
                string mem1;
                getline(f, mem1);
                d[i] = stoi(mem1);
            }
            createFilm(name, pathname,duree, d, count);
            cout << "created Film" << endl;
        }

    }
    return true;
}


Catalogue::~Catalogue(){
    cout << "Catalogue deleted" << endl;
}



