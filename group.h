#ifndef GROUP_H
#define GROUP_H
#include "base.h"
#include <list>

using namespace std;
/**
 * @brief The Group class
 * params:
 *      name: string
 * methods:
 *      setName(string n)
 *      getGroupName()
 *      affichage(ostream & s)
 */
class Group : public list<Base*>
{
private:

    string name;


public:
    /**
     * @brief Group Constructor overcharge
     */
    Group() {}
    /**
     * @brief Group
     * @param name: string
     */
    Group(string name){
        this->name = name;
    }

    /**
     * @brief setName
     * @param n: string
     * Sets the name of the group to n
     */
    virtual void setName(string n){
        name = n;
    }

    /**
     * @brief getGroupName
     * @return string of group name
     */
    virtual string getGroupName(){
        return name;
    }

    /**
     * @brief affichage
     * @param s: ostream
     * @return string of attributes of group
     * Prints through s the returned string
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
     * @brief ~Group Destructor
     */
    virtual ~Group(){
        //cout << "Group deleted" << endl;
    }
};

#endif // GROUP_H
