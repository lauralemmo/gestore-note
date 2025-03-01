
#ifndef GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H
#define GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H

#include "NotesCollection.h"

class ImportantNotesCollection : public NotesCollection{
public:
    explicit ImportantNotesCollection(const string &nameImportantCollection);
    ~ImportantNotesCollection() override;

    void addNote(Note &note) override;
    bool removeNote(string &title) override;
};


#endif //GESTORENOTELAB_IMPORTANTNOTESCOLLECTION_H
