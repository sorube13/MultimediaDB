#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>

using namespace std;
/**
 * @brief The Video class
 * params:
 *      duree: int
 * methods:
 *      setDuree(int d)
 *      getDuree()
 *      openObject()
 *      affichage(ostream &s)
 */
class Video : public Base
{
private:
    int duree;
public:
    /**
     * @brief Video Constructor overcharge
     */
    Video() {}
    /**
     * @brief Video Constructor
     * @param name: string
     * @param pathname: string
     * @param duree: int
     */
    Video(string name, string pathname, int duree) : Base(name, pathname), duree(duree){}

    /**
     * @brief setDuree
     * @param d: int
     * Sets duree to the value of d
     */
    virtual void setDuree(int d){duree = d ; }

    /**
     * @brief getDuree
     * @return duree int (duration of video)
     */
    virtual int getDuree() const { return duree; }

    /**
     * @brief openObject
     * Plays video using xdg-open (opens with default program). As with Photo, there was a problem
     * using the & and did not weork properly, with this solution it seems to be solved
     */
    virtual void openObject(){
        string s = "xdg-open "+ getPathname() + " &";
        system(s.c_str());
    }

    /**
     * @brief affichage
     * @param s: ostream
     * @return string of attributes of video
     * Prints through s the returned string
     */
    virtual string affichage(ostream & s) override {
        string msg = "Video\n" + getName() + " "+ getPathname() + " "+ to_string(getDuree());
        s << msg << endl;
        return msg;
    }
    /**
     * @brief ~Video Destructor
     */
    virtual ~Video(){
        //cout << "Video deleted" << endl;
    }
};


#endif // VIDEO_H
