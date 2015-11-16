#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

using namespace std;
/**
 * @brief The Base class
 * params:
 *      name: name of file including extension
 *      pathname: complete path to file
 * methods:
 *      setName(string n)
 *      setPathname(string p)
 *      getName()
 *      getPathname()
 *      openObject()
 *      affichage(ostream &s)
 */
class Base
{
private:
    string name, pathname;

public:
    /**
     * @brief Base constructor
     * @param name
     * @param pathname
     */
    Base(string name, string pathname);
    /**
     * @brief Base overcharge constructor
     */
    Base();
    /**
     * @brief setName
     * @param n: string
     * Sets the name of the file (with extension) to the string n
     */
    virtual void setName(string n);
    /**
     * @brief setPathname
     * @param p: string
     * Sets the pathname of the file to the string p
     */
    virtual void setPathname(string p);
    /**
     * @brief getName
     * @return string with name of the file (including extension)
     */
    virtual string getName() const;
    /**
     * @brief getPathname
     * @return string with path to the file
     */
    virtual string getPathname() const;
    /**
     * @brief openObject
     * opens the object with the default program
     */
    virtual void openObject();
    /**
     * @brief affichage
     * @param s: ostream
     * @return string with the attributes of the object
     * Also prints through s the string
     */
    virtual string affichage(ostream & s);
    /**
     * @brief ~Base destructor
     */
    virtual ~Base();
};

#endif // BASE_H
