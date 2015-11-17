#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <map>
#include <string>
#include "base.h"
#include "group.h"
#include <memory>

using namespace std;
/**
 * @brief The Catalogue class
 * Class containing a catalogue of multimedia and of groups.
 * params:
 *      multimedia: map with a string as key and a Base object
 *      groups: map with a string as key and a Group object
 * methods:
 *      createPhoto(string n, string pathname, double lat, double lon)
 *      createVideo(string n, string pathname, int duree)
 *      createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num)
 *      createGroup(string n)
 *      supprimerMultimedia(string p)
 *      supprimerGroup(string p)
 *      rechercherMultimedia(string p, ostream &s)
 *      rechercherGroup(string p, ostream &s)
 *      jouer(string p)
 *      save(const string & fileName)
 *      load(const string & fileName)
 */
class Catalogue
{

private:
    map<string,shared_ptr<Base>> multimedia;
    map<string,shared_ptr<Group>> groups;

public:
    /**
     * @brief Catalogue Constructor
     */
    Catalogue();
    /**
     * @brief createPhoto
     * @param n: string
     * @param pathname: string
     * @param lat: double
     * @param lon: double
     * Creates a new photo with the attributes given
     * Must not repeat already existing n, and n must have valid characters
     */
    virtual void createPhoto(string n, string pathname, double lat, double lon);
    /**
     * @brief createVideo
     * @param n: string
     * @param pathname: string
     * @param duree: int
     * creates a video with the attributes given
     * Must not repeat already existing n, and n must have valid characters
     */
    virtual void createVideo(string n, string pathname, int duree);
    /**
     * @brief createFilm
     * @param n: string
     * @param pathname: string
     * @param duree: int
     * @param tab: unsigned int
     * @param num: unsigned int
     * Creates a film with the parameters given
     * Must not repeat already existing n, and n must have valid characters
     */
    virtual void createFilm(string n, string pathname, int duree, unsigned int *tab, unsigned int num);
    /**
     * @brief createGroup
     * @param n: string
     * Creates a group with the parameters given
     * Must not repeat already existing n, and n must have valid characters
     */
    virtual void createGroup(string n);
    /**
     * @brief supprimerMultimedia
     * @param p: string
     * Deletes multimedia with name p from catalogue and from groups containing them
     */
    virtual void supprimerMultimedia(string p);
    /**
     * @brief supprimerGroup
     * @param p: string
     * Deletes group with name p from catalogue
     */
    virtual void supprimerGroup(string p);
    /**
     * @brief rechercherMultimedia
     * @param p: string
     * @param s: ostream
     * @return string with multimedia (named p) attributes
     * prints in s the return string
     */
    virtual string rechercherMultimedia(string p, ostream & s);
    /**
     * @brief rechercherGroup
     * @param p : string
     * @param s: ostream
     * @return string with group (named p) attributes
     * prints in s the string
     */
    virtual string rechercherGroup(string p, ostream & s);
    /**
     * @brief jouer
     * @param p: string
     * opens object named p with default program
     */
    virtual void jouer(string p);
    /**
     * @brief save
     * @param fileName: string
     * @return operation result (true if completed succesfully and false otherwise)
     * Saves the object into the file with pathname p
     */
    bool save(const string & fileName);
    /**
     * @brief load
     * @param fileName: string
     * @return operation result (true if completed succesfully and false otherwise)
     * Loads the content from the path fileName to the catalogue, creating objects of
     * their type
     */
    bool load(const string & fileName);
    /**
     * @brief ~Catalogue Destructor
     */
    virtual ~Catalogue();
};


#endif // CATALOGUE_H
