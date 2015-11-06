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
    /**
     * @brief Photo
     */
    Photo() {}
    /**
     * @brief Photo
     * @param name
     * @param pathname
     * @param lat
     * @param lon
     */
    Photo(string name, string pathname, double lat, double lon) : Base(name, pathname), lat(lat), lon(lon){}

    /**
     * @brief setLatitude
     * @param la
     */
    virtual void setLatitude(double la){ lat = la; }

    /**
     * @brief setLongitude
     * @param lo
     */
    virtual void setLongitude(double lo){ lon= lo; }

    /**
     * @brief getLatitude
     * @return latitude
     */
    virtual int getLatitude() const{ return lat; }

    /**
     * @brief getLongitude
     * @return longitude
     */
    virtual int getLongitude() const { return lon; }

    /**
     * @brief openObject
     * Opens image with imagej
     */
    virtual void openObject(){
        string s = "imagej "+ getPathname();
        system(s.c_str());
    }

    /**
     * @brief affichage
     * @param s
     * @return photo attributes
     */
    virtual string affichage(ostream & s) override {
        string msg = "Photo\n" + getName() + " "+ getPathname() + " " + to_string(getLatitude()) + " " + to_string(getLongitude());
        s << msg << endl;
        return msg;
    }
    /**
     * @brief ~Photo
     */
    virtual ~Photo(){
        //cout << "Photo deleted" << endl;
    }
};

#endif // PHOTO_H
