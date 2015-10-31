#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>

using namespace std;

class Photo : public Base
{
private:
    double lat, lon;

public:
    /*
     * Constructor
    */
    Photo() {}
    Photo(string name, string pathname, double lat, double lon) : Base(name, pathname), lat(lat), lon(lon){}
    /*
     * Setters and Getters
    */
    virtual void setLatitude(double la){ lat = la; }
    virtual void setLongitude(double lo){ lon= lo; }
    virtual int getLatitude() const{ return lat; }
    virtual int getLongitude() const { return lon; }

    /*
     * Opens multimedia object
    */
    virtual void openObject(){
        string s = "imagej "+ getPathname() + " &";
        system(s.c_str());
    }

    /*
     * Print Photo attributes
    */
    virtual void affichage(ostream & s) override {s << getName() << " "<< getPathname() << " " << getLatitude() << " " << getLongitude() << endl;}
    /*
     * Desctructor
    */
    virtual ~Photo(){
        //cout << "Photo deleted" << endl;
    }
};

#endif // PHOTO_H
