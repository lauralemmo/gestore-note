
#include "gtest/gtest.h"
#include "../ImportantNotesCollection.h"

#include <iostream>
using namespace std;

TEST(ImportantNotesCollection, Constructor){
    string nameCollection = "name";
    ImportantNotesCollection importantNotesCollection(nameCollection);
    ASSERT_EQ(nameCollection, importantNotesCollection.getNameCollection());
}

TEST(ImportantNotesCollection, addNote){
    string nameCollection = "name";
    string title = "title";
    string text = "text";
    ImportantNotesCollection importantNotesCollection(nameCollection);
    Note note(title, text);
    importantNotesCollection.addNote(note);
    ASSERT_EQ(0, importantNotesCollection.countNotes());
    note.setImportant(true);
    importantNotesCollection.addNote(note);
    ASSERT_EQ(1, importantNotesCollection.countNotes());
}

TEST(ImportantNotesCollection, removeNote){
    string nameCollection = "name";
    string title = "title";
    string text = "text";
    ImportantNotesCollection importantNotesCollection(nameCollection);
    Note note(title, text);
    note.setImportant(true);
    importantNotesCollection.addNote(note);
    importantNotesCollection.removeNote(title);
    ASSERT_EQ(0, importantNotesCollection.countNotes());
    Note note2("title2", "text2");
    note2.setImportant(true);
    note2.setBlocked(true);
    importantNotesCollection.addNote(note2);
    importantNotesCollection.removeNote("title2");
    ASSERT_EQ(1, importantNotesCollection.countNotes());
}
