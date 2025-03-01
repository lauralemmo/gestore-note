
#include "Note.h"

Note::Note(string title, string text) : title(title), text(text) {}

Note::~Note() {}

const string &Note::getTitle() const {
    return title;
}

void Note::setTitle(const string &title) {
    if(!blocked)
        Note::title = title;
    else
        cout << "Errore: Impossibile modificare il titolo" << endl;
}

const string &Note::getText() const {
    return text;
}

void Note::setText(const string &text) {
    if(!blocked)
        Note::text = text;
    else
        cout << "Errore: Impossibile modificare il testo" << endl;
}

bool Note::isBlocked() const {
    return blocked;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}

bool Note::isImportant() const {
    return important;
}

void Note::setImportant(bool important) {
    if(!blocked)
        Note::important = important;
    else
        cout << "Errore: Impossibile modificare" << endl;
}

bool Note::isInCollection() const {
    return inCollection;
}

void Note::setInCollection(bool inCollection) {
    Note::inCollection = inCollection;
}

bool Note::isInImportantCollection() const {
    return inImportantCollection;
}

void Note::setInImportantCollection(bool inImportantCollection) {
    Note::inImportantCollection = inImportantCollection;
}
