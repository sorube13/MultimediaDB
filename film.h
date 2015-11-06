#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>

using namespace std;

class Film : public Video
{
private:
    unsigned int count;
    unsigned int *durees;

public:
    /*
     * Constructor
    */
    Film() {}
    Film(string name, string pathname, int duree) : Video(name, pathname, duree) {}

    virtual void setDurees(unsigned int *tab, unsigned int num) {
        count = num;
        delete [] durees;
        durees = new unsigned int[num];
        for(unsigned int i=0; i<num; i++){
            durees[i] = tab[i];
        }
    }
    virtual unsigned const int *getDurees() const{
        return durees;
    }

    virtual int getNombreChapitres() const{
        return count;
    }


    virtual string affichage(ostream & s) override {
        s << "Film\nNOM: "<< getName() << " PATH:  "<< getPathname() << " DUREE: "<< getDuree() << " DUREES POINTER: " << getDurees() << endl;
        for(unsigned int i = 0; i< count; i++){
            s<< "Chapitre " << i+1 << ": " <<  durees[i]<<endl;
        }
        return "hola";
    }

    /*
    * modifier(arg time)
    */

    /*
     * Desctructor
    */
    virtual ~Film(){
        delete [] durees;
        durees = nullptr;
        //cout << "Film deleted" << endl;
    }
};
#endif // FILM_H
