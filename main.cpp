#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "ImportantNotesCollection.h"
#include "User.h"

int main() {
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    Note note4("title4", "text4");
    Note note5("title5", "text5");
    Note note6("title6", "text6");

    NotesCollection* collection1 = new NotesCollection("collection1");
    NotesCollection* collection2 = new NotesCollection("collection2");

    ImportantNotesCollection* importantCollection1 = new ImportantNotesCollection("importantCollection1");

    User user1(collection1);
    User user2(collection2);
    User user3(importantCollection1);

    note1.setBlocked(true);
    note2.setImportant(true);


    collection1->addNote(note1);
    collection1->addNote(note2);
    collection2->addNote(note1);  //non funziona perchè è già in un'altra collezione
    collection2->addNote(note3);
    collection2->addNote(note4);
    collection1->addNote(note5);
    collection1->addNote(note6);
    importantCollection1->addNote(note2);
    importantCollection1->addNote(note3);  //non funziona perchè non importante
    cout << "Note nella " << collection1->getNameCollection() << ": " << collection1->countNotes() << endl;
    cout << "Note nella " << collection2->getNameCollection() << ": " << collection2->countNotes() << endl;
    cout << "Note nella " << importantCollection1->getNameCollection() << ": " << importantCollection1->countNotes() << endl;

    collection1->removeNote("title1");  //non funziona perchè bloccata
    collection1->removeNote("title5");
    cout << "Note nella " << collection1->getNameCollection() << ": " << collection1->countNotes() << endl;

    collection2->searchNote("title2");  //non funziona perchè nota non presente
    collection2->searchNote("title4");
    importantCollection1->searchNote("title2");

    collection2->printNotes();

    note6.setBlocked(true);
    note6.setImportant(true);  //non funziona perchè bloccata
    note6.setTitle("new title6");  //non funziona perchè bloccata
    note6.setText("new text6");  //non funziona perchè bloccata
}
