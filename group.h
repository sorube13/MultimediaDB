#ifndef GROUP_H
#define GROUP_H
#include "base.h"
#include <list>

using namespace std;

class Group : public list<Base*>
{
private:

    string name;


public:
    /**
     * @brief Group
     */
    Group() {}
    /**
     * @brief Group
     * @param name
     */
    Group(string name){
        this->name = name;
    }

    /**
     * @brief setName
     * @param n
     */
    virtual void setName(string n){
        name = n;
    }

    /**
     * @brief getGroupName
     * @return group name
     */
    virtual string getGroupName(){
        return name;
    }

    /**
     * @brief affichage
     * @param s
     * @return attributes of group
     */
    virtual string affichage(ostream & s) {
        string msg;
        if(!this->empty()){
            msg = "Group: " + getGroupName();
            for (list<Base*>::const_iterator it = this->begin(); it != this->end(); it++){
                msg += "\n" + (*it)->affichage(s);
            }
        } else{
            msg = getGroupName() + " is empty";
        }
        s << msg << endl;
        return msg;
    }

    /**
     * @brief ~Group
     */
    virtual ~Group(){
        //cout << "Group deleted" << endl;
    }
};

#endif // GROUP_H
