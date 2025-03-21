//
// Created by Laura Lemmo on 28/02/25.
//

#include "ImportantNotesCollection.h"

ImportantNotesCollection::ImportantNotesCollection(const string &nameImportantCollection) : NotesCollection(
        nameImportantCollection) {}

ImportantNotesCollection::~ImportantNotesCollection() {}


bool ImportantNotesCollection::addNote(Note &note) {
    if(note.isImportant() == true){
        if(note.isInCollection() == true){
            collection.push_back(note);
            notify();
            return true;
        }
        else{
            cout << "Nota non presente in una collezione, impossibile aggiungerla fra quelle importanti" << endl;
            return false;
        }
    }
    else{
        cout << "Nota non importante, impossibile aggiungerla" << endl;
        return false;
    }
}


bool ImportantNotesCollection::removeNote(const string &title) {
    for(auto it = collection.begin(); it != collection.end(); it++){
        if((*it).getTitle() == title){
            if((*it).isBlocked() == false){
                collection.erase(it);
                cout << "Nota importante eliminata" << endl;
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
