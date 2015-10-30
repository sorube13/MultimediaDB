#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

using namespace std;

class Video : public Base
{
private:
    int duree;
public:
    /*
     * Constructor
    */
    Video() {}
    Video(string name, string pathname, int duree) : Base(name, pathname), duree(duree){}
    /*
     * Setters and Getters
    */
    virtual void setDuree(int d){duree = d ; }
    virtual int getDuree() const { return duree; }

    /*
     * Opens multimedia object
    */
    virtual void openObject(){
        string s = "mpv "+ getPathname() + " &";
        system(s.c_str());
    }

    /*
     * Print Video attributes
    */
    virtual void affichage(ostream & s) override {s << getName() << " "<< getPathname() << " "<< getDuree() << endl;}
    /*
     * Desctructor
    */
    virtual ~Video(){
        cout << "Video deleted" << endl;
    }
};


#endif // VIDEO_H
