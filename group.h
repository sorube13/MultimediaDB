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
    /*
     * Constructor
    */
    Group() {}
    Group(string name){
        this->name = name;
    }

    virtual void setName(string n){
        name = n;
    }

    virtual string getGroupName(){
        return name;
    }

    virtual void affichage(ostream & s) {
        if(!this->empty()){
            s << "Group: " << getGroupName() << endl;
            for (list<Base*>::const_iterator it = this->begin(); it != this->end(); it++){
                (*it)->affichage(s);
            }
        } else{
            s << "Group is empty" << endl;
        }
    }

    virtual ~Group(){
        cout << "Group deleted" << endl;
    }
};

#endif // GROUP_H
