
#include "gtest/gtest.h"
#include "../NotesCollection.h"

#include <iostream>
using namespace std;

TEST(NotesCollection, Constructor){
    string nameCollection = "name";
    NotesCollection notesCollection(nameCollection);
    ASSERT_EQ(nameCollection, notesCollection.getNameCollection());
}

TEST(NotesCollection, addNote){
    string nameCollection = "name";
    string title1 = "title1";
    string text1 = "text1";
    NotesCollection notesCollection(nameCollection);
    Note note1(title1, text1);
    notesCollection.addNote(note1);
    ASSERT_EQ(1, notesCollection.countNotes());
    string title2 = "title2";
    string text2 = "text2";
    Note note2(title2, text2);
    notesCollection.addNote(note2);
    ASSERT_EQ(2, notesCollection.countNotes());
}

TEST(NotesCollection, removeNote){
    string nameCollection = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(nameCollection);
    Note note(title, text);
    notesCollection.addNote(note);
    notesCollection.removeNote("title");
    ASSERT_EQ(0, notesCollection.countNotes());
    Note note2("title2", "text2");
    note2.setBlocked(true);
    notesCollection.addNote(note2);
    notesCollection.removeNote("title2");
    ASSERT_EQ(1, notesCollection.countNotes());
    notesCollection.removeNote("title3");
    ASSERT_EQ(1, notesCollection.countNotes());
}

TEST(NotesCollection, searchNotes){
    NotesCollection notesCollection("name");
    Note note1("title1 prova", "text1 prova");
    Note note2("title2", "text2 prova");
    Note note3("title3 prova", "text3 prova");
    notesCollection.addNote(note1);
    notesCollection.addNote(note2);
    notesCollection.addNote(note3);
    NotesCollection finalList("final list");
    finalList = notesCollection.searchNotes("prova");
    ASSERT_EQ(2, finalList.countNotes());
}

TEST(NotesCollection, countNotes){
    NotesCollection notesCollection("name");
    Note note1("title1", "text1");
    Note note2("title2", "text2");
    Note note3("title3", "text3");
    notesCollection.addNote(note1);
    notesCollection.addNote(note2);
    notesCollection.addNote(note3);
    ASSERT_EQ(3, notesCollection.countNotes());
    notesCollection.removeNote("title3");
    ASSERT_EQ(2, notesCollection.countNotes());
}


