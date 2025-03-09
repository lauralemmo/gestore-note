
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

void NotesCollection::modifyNote(Note &note, const string &text) {
    note.setText(text);
    cout << note.getText() << endl;
}


void NotesCollection::setNameCollection(const string &name) {
    nameCollection = name;
}


string NotesCollection::getNameCollection() {
    return nameCollection;
}


NotesCollection NotesCollection::searchNotes(const string &word) {
    NotesCollection notesWithWord("name collection");
    cout << "Lista delle note contenenti '" << word << "' :" << endl;
    for(auto it = collection.begin(); it != collection.end(); it++){
        if((*it).getTitle().find(word) != string::npos && (*it).getText().find(word) != string::npos){
            cout << it->getTitle() << ", " << it->getText() << endl;
            notesWithWord.addNote(*it);
        }
    }
    return notesWithWord;
}


void NotesCollection::printNotes() {
    cout << "Lista delle note contenute nella collezione: " << endl;
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


