#ifndef FILM_H
#define FILM_H
#include <string>
#include <iostream>

using namespace std;
/**
 * @brief The Film class
 * params:
 *      count: unsigned int
 *      *durees: unsigned int
 * methods:
 *      setDurees(unsigned int *tab, unsigned int num)
 *      getDurees()
 *      getNombreChapitres()
 *      affichage(ostream & s)
 */
class Film : public Video
{
private:
    unsigned int count;
    unsigned int *durees;

public:

    /**
     * @brief Film constructor overcharge
     */
    Film() {}
    /**
     * @brief Film Constructor
     * @param name: string
     * @param pathname: string
     * @param duree: int
     * Creates a film with the same parameters as a video
     */
    Film(string name, string pathname, int duree) : Video(name, pathname, duree) {}

    /**
     * @brief setDurees
     * @param tab: unsigned int
     * @param num: unsigned int
     * Sets the parameter durees to the film, copying the variable tab to durees.
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
     * @return count: number of chapters
     */
    virtual int getNombreChapitres() const{
        return count;
    }

    /**
     * @brief affichage
     * @param s: ostream
     * @return string of film attributes
     * Also prints in s the return string
     */
    virtual string affichage(ostream & s) override {
        string msg;
        msg = "Film\n" + getName() + " " + getPathname() + " " + to_string(getDuree()) + " " +to_string(getNombreChapitres());
        for(unsigned int i = 0; i< count; i++){
            msg = msg +  "\n" + to_string(durees[i]);
        }
        s << msg << endl;
        return msg;
    }


    /**
     * @brief ~Film Destructor
     */
    virtual ~Film(){
        delete [] durees;
        durees = nullptr;
        //cout << "Film deleted" << endl;
    }
};
#endif // FILM_H
