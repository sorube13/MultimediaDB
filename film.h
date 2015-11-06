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

    /**
     * @brief Film
     */
    Film() {}
    /**
     * @brief Film
     * @param name
     * @param pathname
     * @param duree
     */
    Film(string name, string pathname, int duree) : Video(name, pathname, duree) {}

    /**
     * @brief setDurees
     * @param tab
     * @param num
     */
    virtual void setDurees(unsigned int *tab, unsigned int num) {
        count = num;
        delete [] durees;
        durees = new unsigned int[num];
        for(unsigned int i=0; i<num; i++){
            durees[i] = tab[i];
        }
    }

    /**
     * @brief getDurees
     * @return pointer to array of durees
     */
    virtual unsigned const int *getDurees() const{
        return durees;
    }

    /**
     * @brief getNombreChapitres
     * @return number of chapters
     */
    virtual int getNombreChapitres() const{
        return count;
    }

    /**
     * @brief affichage
     * @param s
     * @return film attributes
     */
    virtual string affichage(ostream & s) override {
        s << "Film\n"<< getName() << " "<< getPathname() << " "<< getDuree() << " " << getNombreChapitres()<< endl;
        for(unsigned int i = 0; i< count; i++){
            s <<  durees[i]<< endl;
        }
        return "hola";
    }


    /**
     * @brief ~Film
     */
    virtual ~Film(){
        delete [] durees;
        durees = nullptr;
        //cout << "Film deleted" << endl;
    }
};
#endif // FILM_H
