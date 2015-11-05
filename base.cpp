#include "base.h"


using namespace std;
/*
 * Constructor for Base without arguments
*/
Base::Base(){}

/*
* Constructor for Base with file name (name) and path (pathname)
*/
Base::Base(string _name, string _pathname){
    name = _name;
    pathname = _pathname;
}

/*
 * Base name setter
*/
void Base::setName(string n){
    name = n;
}

/*
 * Base pathname setter
*/
void Base::setPathname(string p){
    pathname = p;
}

/*
 * Base name getter
 * returns name
*/
string Base::getName() const{
    return name;
}

/*
 * Base path getter
 * returns pathname
*/
string Base::getPathname() const{
    return pathname;
}

void Base::openObject(){}

/*
 * Method affichage
 * Prints name and pathname
*/
string Base::affichage(ostream & s){
    string msg = getName() + " " + getPathname();
    s << msg << endl;
    return msg;
}

/*
 * Base destructeur
*/
Base::~Base(){}

