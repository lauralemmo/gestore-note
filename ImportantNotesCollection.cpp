//
// Created by Laura Lemmo on 28/02/25.
//

#include "ImportantNotesCollection.h"

ImportantNotesCollection::ImportantNotesCollection(const string &nameImportantCollection) : NotesCollection(
        nameImportantCollection) {}

ImportantNotesCollection::~ImportantNotesCollection() {}


void ImportantNotesCollection::addNote(Note &note) {
    if(note.isImportant() == true){
        if(note.isInImportantCollection() == false){
            collection.push_back(note);
            note.setInImportantCollection(true);
            notify();
        }
        else
            cout << "Nota già presente in una collezione importante" << endl;
    }
    else
        cout << "Nota non importante" << endl;
}


bool ImportantNotesCollection::removeNote(const string &title) {
    for(auto it = collection.begin(); it != collection.end(); it++){
        if((*it).getTitle() == title){
            if((*it).isBlocked() == false){
                collection.erase(it);
                cout << "Nota importante eliminata" << endl;
                (*it).setInImportantCollection(false);
                notify();
                return true;
            }
            else{
                cout << "Nota importante bloccata, impossibile eliminarla" << endl;
                return false;
            }
        }
    }
    cout << "Nota importante non trovata" << endl;
    return false;
}
