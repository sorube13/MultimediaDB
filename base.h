#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

using namespace std;

class Base
{
private:
    string name, pathname;

public:
    Base(string name, string pathname);
    Base();
    virtual void setName(string n);
    virtual void setPathname(string p);
    virtual string getName() const;
    virtual string getPathname() const;
    virtual void openObject();
    virtual void affichage(ostream & s);
    virtual ~Base();
};

#endif // BASE_H
