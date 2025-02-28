
#ifndef GESTORENOTELAB_SUBJECT_H
#define GESTORENOTELAB_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() = default;
};


#endif //GESTORENOTELAB_SUBJECT_H
