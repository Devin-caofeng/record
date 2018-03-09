#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>
#include "obeserver.h"
using namespace std;

class Subject {
public:
    Subject() { }
    virtual ~Subject() { }
    Obeserver *obeserver_;

    void Attach(Obeserver *obeserver) { obj_.push_back(obeserver); }
    void Detach(Obeserver *obeserver) {
        for (auto iter = obj_.begin(); iter != obj_.end(); ++iter) {
            if (*iter == obeserver) {
                obj_.erase(iter);
                return;
            }
        }
    }
    void Notify() {
        for (auto iter = obj_.begin(); iter != obj_.end(); ++iter) {
            (*iter)->Update(this);
        }
    }

    virtual int  GetState() = 0;
    virtual void SetState() = 0;

private:
    vector<Obeserver*> obj_;
};


#endif  // SUBJECT_H_
