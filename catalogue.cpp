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

/**
 * @brief Catalogue::Catalogue
 */
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
    return str[strspn(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_.-:")] != 0;
}

/**
 * @brief Catalogue::createPhoto
 * @param n
 * @param pathname
 * @param lat
 * @param lon
 * Creates a new photo with smart pointers
 * Checks if there are other objects with the same name and shows error message
 * Checks for invalid characters
 */
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

/**
 * @brief Catalogue::createVideo
 * @param n
 * @param pathname
 * @param duree
 * Creates a new video with smart pointers
 * Checks if there are other objects with the same name and shows error message
 * Checks for invalid characters
 */
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

/**
 * @brief Catalogue::createFilm
 * @param n
 * @param pathname
 * @param duree
 * @param tab
 * @param num
 * Creates a new film with smart pointers
 * Checks if there are other objects with the same name and shows error message
 * Checks if the durees is zero or less and shows error message
 * Checks for invalid characters
 */
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

/**
 * @brief Catalogue::createGroup
 * @param n
 * Creates a new group with smart pointers
 * Checks if there are other objects with the same name and shows error message
 * Checks for invalid characters
 */

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

/**
 * @brief Catalogue::supprimerMultimedia
 * @param p
 * Shows error if Multimedia not found
 */
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

/**
 * @brief Catalogue::supprimerGroup
 * @param p
 * Shows error if Group not found
 */
void Catalogue::supprimerGroup(string p){
    if(groups.find(p) != groups.end()){
        groups.erase(p);
        cout << "Deleted Group: " << p << endl;
    }else{
        cerr << p << " Not Found" << endl;
    }
}

/**
 * @brief Catalogue::rechercherMultimedia
 * @param p
 * @param s
 * @return attributes of multimedia[p]
 * Shows error if multimedia not found
 */
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

/**
 * @brief Catalogue::rechercherGroup
 * @param p
 * @param s
 * @return attributes of Group[p]
 * Shows error if group not found
 */
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

/**
 * @brief Catalogue::jouer
 * @param p
 */
void Catalogue::jouer(string p){
    if(multimedia.find(p) != multimedia.end()){
        map<string, shared_ptr<Base> >::const_iterator m = this->multimedia.find(p);
        cout << "Opening "<< p << endl;
        (m->second)->openObject();
    }else{
        cerr << "Not Found" << endl;
    }
}


/**
 * @brief Catalogue::save
 * @param fileName
 * @return true if file saved successfully
 * Otherwise return false and error message
 */
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

/**
 * @brief Catalogue::load
 * @param fileName
 * @return true if file loaded successfuly
 * Error message if file not available
 */
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
            /*unsigned int d [count] = {};
            for(unsigned int i=0; i<count; i++){
                stringstream mem;
                unsigned int mem2;
                string mem1;
                getline(f, mem1);
                mem << mem1;
                mem >> mem2;
                d[i] = mem2;
            }*/
            cout << "aqui llega" << endl;
            //cout << name << " " << pathname << " " << duree << " " << d << " " << count << endl;
            //createFilm("film",pathname, duree, d,count);
            //createFilm(name, pathname,duree, p, count);
            cout << "created Film" << endl;
        }

    }
    return true;
}

/**
 * @brief Catalogue::~Catalogue
 */
Catalogue::~Catalogue(){
    cout << "Catalogue deleted" << endl;
}



