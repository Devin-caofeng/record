#ifndef CONCRETE_OBESERVER_H_
#define CONCRETE_OBESERVER_H_

#include <iostream>
#include <string>
#include <vector>
#include "obeserver.h"
#include "subject.h"
using namespace std;

class ConcreteObeserver : public Obeserver {
public:
    ConcreteObeserver(string name) { obj_name = name; }
    virtual ~ConcreteObeserver() { }
    virtual void Update(Subject *sub) {
        obeserver_state = sub->GetState();
        cout << "update obeserver[" << obj_name << "] state:"
             << obeserver_state << endl;
    }

private:
    string obj_name;
    int    obeserver_state;
};


#endif  // CONCRETE_OBESERVER_H_
