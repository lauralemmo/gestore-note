
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
    bool a = importantNotesCollection.addNote(note);
    ASSERT_EQ(0, importantNotesCollection.countNotes());
    ASSERT_FALSE(a);
    note.setImportant(true);
    NotesCollection notesCollection("name collection");
    notesCollection.addNote(note);
    bool b = importantNotesCollection.addNote(note);
    ASSERT_EQ(1, importantNotesCollection.countNotes());
    ASSERT_TRUE(b);
}

TEST(ImportantNotesCollection, removeNote){
    string nameCollection = "name";
    string title = "title";
    string text = "text";
    ImportantNotesCollection importantNotesCollection(nameCollection);
    Note note(title, text);
    note.setImportant(true);
    NotesCollection notesCollection("name collection");
    notesCollection.addNote(note);
    importantNotesCollection.addNote(note);
    bool c = importantNotesCollection.removeNote(title);
    ASSERT_EQ(0, importantNotesCollection.countNotes());
    ASSERT_TRUE(c);
    Note note2("title2", "text2");
    note2.setImportant(true);
    note2.setBlocked(true);
    notesCollection.addNote(note2);
    importantNotesCollection.addNote(note2);
    bool d = importantNotesCollection.removeNote("title2");
    ASSERT_EQ(1, importantNotesCollection.countNotes());
    ASSERT_FALSE(d);
}
