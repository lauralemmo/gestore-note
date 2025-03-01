
#ifndef GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H
#define GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H

#include "NotesCollection.h"

class ImportantNotesCollection : public NotesCollection{
public:
    explicit ImportantNotesCollection(const string &nameImportantCollection);
    ~ImportantNotesCollection() override;

    virtual void addNote(Note &note) override;
    virtual bool removeNote(string &title) override;
};


#endif //GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H
