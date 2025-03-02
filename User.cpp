
#include "User.h"


User::User(NotesCollection *subject) {
    this->subject = subject;
    attach();
}

User::~User() {
    detach();
}


void User::update() {
    cout << "Note nella collezione " << subject->getNameCollection() << ": " << subject->countNotes() << endl;
}

void User::attach() {
    subject->subscribe(this);
}

void User::detach() {
    subject->unsubscribe(this);
}
