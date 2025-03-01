
#ifndef GESTORENOTELAB_USER_H
#define GESTORENOTELAB_USER_H

#include "NotesCollection.h"
#include "Observer.h"

class User : public Observer{
public:
    explicit User(NotesCollection* subject);
    ~User() override;

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    NotesCollection* subject;
};


#endif //GESTORENOTELAB_USER_H
