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
    /**
     * @brief Video
     */
    Video() {}
    /**
     * @brief Video
     * @param name
     * @param pathname
     * @param duree
     */
    Video(string name, string pathname, int duree) : Base(name, pathname), duree(duree){}

    /**
     * @brief setDuree
     * @param d
     */
    virtual void setDuree(int d){duree = d ; }

    /**
     * @brief getDuree
     * @return duration of video
     */
    virtual int getDuree() const { return duree; }

    /**
     * @brief openObject
     * Plays video using mpv
     */
    virtual void openObject(){
        string s = "mpv "+ getPathname() + " &";
        system(s.c_str());
    }

    /**
     * @brief affichage
     * @param s
     * @return attributes of video
     */
    virtual string affichage(ostream & s) override {
        string msg = "Video\n" + getName() + " "+ getPathname() + " "+ to_string(getDuree());
        s << msg << endl;
        return msg;
    }
    /**
     * @brief ~Video
     */
    virtual ~Video(){
        //cout << "Video deleted" << endl;
    }
};


#endif // VIDEO_H
