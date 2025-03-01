
#ifndef GESTORENOTELAB_NOTESCOLLECTION_H
#define GESTORENOTELAB_NOTESCOLLECTION_H

#include "Subject.h"
#include "Note.h"
#include <list>

class NotesCollection : public Subject{
public:
    explicit NotesCollection(const string &nameCollection);
    ~NotesCollection() override;

    virtual void addNote(Note &note);
    virtual bool removeNote(const string &title);

    void setNameCollection(const string &name);
    string getNameCollection();
    bool searchNote(const string &title);
    void printNotes();
    int countNotes();


    virtual void subscribe(Observer * o) override;
    virtual void unsubscribe(Observer * o) override;
    virtual void notify() override;

protected:
    list<Note> collection;
    string nameCollection;
    list<Observer*> observers;
};


#endif //GESTORENOTELAB_NOTESCOLLECTION_H
