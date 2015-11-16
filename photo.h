#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>

using namespace std;
/**
 * @brief The Photo class
 * params:
 *      lat: double
 *      lon: double
 * methods:
 *      setLatitude(double la)
 *      setLongitude(double lo)
 *      getLatitude()
 *      getLongitude()
 *      openObject()
 *      affichage(ostream &s)
 */
class Photo : public Base
{
private:
    double lat, lon;

public:
    /**
     * @brief Photo Constructor Overcharge
     */
    Photo() {}
    /**
     * @brief Photo
     * @param name: string
     * @param pathname: string
     * @param lat: double
     * @param lon: double
     */
    Photo(string name, string pathname, double lat, double lon) : Base(name, pathname), lat(lat), lon(lon){}

    /**
     * @brief setLatitude
     * @param la: double
     * sets lat to the value of la
     */
    virtual void setLatitude(double la){ lat = la; }

    /**
     * @brief setLongitude
     * @param lo: double
     * sets lon  to the value of lo
     */
    virtual void setLongitude(double lo){ lon= lo; }

    /**
     * @brief getLatitude
     * @return lat double
     */
    virtual int getLatitude() const{ return lat; }

    /**
     * @brief getLongitude
     * @return lon double
     */
    virtual int getLongitude() const { return lon; }

    /**
     * @brief openObject
     * Opens image with xdg-open (default program) due to the fact that with imagej, it would not work
     * properly without the "&", and this solution worked better
     */
    virtual void openObject(){
        string s = "xdg-open " + getPathname() + " &" ;
        system(s.c_str());
    }

    /**
     * @brief affichage
     * @param s: ostream
     * @return string of all photo attributes
     * Prints through s the returned string
     */
    virtual string affichage(ostream & s) override {
        string msg = "Photo\n" + getName() + " "+ getPathname() + " " + to_string(getLatitude()) + " " + to_string(getLongitude());
        s << msg << endl;
        return msg;
    }
    /**
     * @brief ~Photo Destructor
     */
    virtual ~Photo(){
        //cout << "Photo deleted" << endl;
    }
};

#endif // PHOTO_H
