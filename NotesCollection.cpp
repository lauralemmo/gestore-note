
#include "NotesCollection.h"

NotesCollection::NotesCollection(const string &nameCollection) : nameCollection(nameCollection) {}
NotesCollection::~NotesCollection() {}


void NotesCollection::addNote(Note &note) {
    if(note.isInCollection() == false){
        collection.push_back(note);
        note.setInCollection(true);
        notify();
    }
    else
        cout << "Nota già presente in una collezione, impossibile aggiungerla" << endl;
}


bool NotesCollection::removeNote(const string &title) {
    for(auto it = collection.begin(); it != collection.end(); it++){
        if((*it).getTitle() == title){
            if((*it).isBlocked() == false){
                collection.erase(it);
                cout << "Nota eliminata" << endl;
                (*it).setInCollection(false);
                notify();
                return true;
            }
            else{
                cout << "Nota bloccata, impossibile eliminarla" << endl;
                return false;
            }
        }
    }
    cout << "Nota non trovata" << endl;
    return false;
}


void NotesCollection::setNameCollection(const string &name) {
    nameCollection = name;
}


string NotesCollection::getNameCollection() {
    return nameCollection;
}


bool NotesCollection::searchNote(const string &title) {
    for(auto it = collection.begin(); it != collection.end(); it++){
        if((*it).getTitle() == title){
            cout << "Titolo nota: " << it->getTitle() << endl;
            cout << "Testo nota: " << it->getText() << endl;
            return true;
        }
    }
    cout << "Nota non trovata" << endl;
    return false;
}


void NotesCollection::printNotes() {
    for(auto it = collection.begin(); it != collection.end(); it++){
        cout << it->getTitle() << ", " << it->getText() << endl;
    }
}


int NotesCollection::countNotes() {
    return collection.size();
}


void NotesCollection::subscribe(Observer *o) {
    observers.push_back(o);
}


void NotesCollection::unsubscribe(Observer *o) {
    observers.remove(o);
}


void NotesCollection::notify() {
    for(auto it = observers.begin(); it != observers.end(); it++) {
        (*it)->update();
    }
}
