#include "base.h"


using namespace std;

Base::Base(){}

Base::Base(string _name, string _pathname){
    name = _name;
    pathname = _pathname;
}


void Base::setName(string n){
    name = n;
}


void Base::setPathname(string p){
    pathname = p;
}


string Base::getName() const{
    return name;
}


string Base::getPathname() const{
    return pathname;
}

void Base::openObject(){}

string Base::affichage(ostream & s){
    string msg = "Base\n"+getName() + " " + getPathname();
    s << msg << endl;
    return msg;
}


Base::~Base(){}

