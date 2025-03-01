
#ifndef GESTORENOTELAB_NOTESCOLLECTION_H
#define GESTORENOTELAB_NOTESCOLLECTION_H

#include "Subject.h"
#include "Note.h"
#include <list>

class NotesCollection : public Subject{
public:
    explicit NotesCollection(const string &nameCollection);
    virtual ~NotesCollection();

    virtual void addNote(Note &note);
    virtual bool removeNote(string &title);

    void setNameCollection(const string &name);
    string getNameCollection();
    bool searchNote(const string &title);
    void printNotes();
    int countNotes();


    void subscribe(Observer * o) override;
    void unsubscribe(Observer * o) override;
    void notify() override;

protected:
    list<Note> collection;
    string nameCollection;
    list<Observer*> observers;
};


#endif //GESTORENOTELAB_NOTESCOLLECTION_H
