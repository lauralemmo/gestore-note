
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
    string nameCollection1 = "name1";
    string title1 = "title1";
    string text1 = "text1";
    NotesCollection notesCollection(nameCollection1);
    Note note1(title1, text1);
    notesCollection.addNote(note1);
    ASSERT_EQ(1, notesCollection.countNotes());
    NotesCollection notesCollection2("name2");
    string title2 = "title2";
    string text2 = "text2";
    Note note2(title2, text2);
    bool a = notesCollection2.addNote(note2);
    ASSERT_EQ(1, notesCollection2.countNotes());
    ASSERT_TRUE(a);
    bool b = notesCollection2.addNote(note1);
    ASSERT_EQ(1, notesCollection2.countNotes());
    ASSERT_FALSE(b);
}

TEST(NotesCollection, removeNote){
    string nameCollection = "name";
    string title = "title";
    string text = "text";
    NotesCollection notesCollection(nameCollection);
    Note note(title, text);
    notesCollection.addNote(note);
    bool c = notesCollection.removeNote("title");
    ASSERT_EQ(0, notesCollection.countNotes());
    ASSERT_TRUE(c);
    Note note2("title2", "text2");
    note2.setBlocked(true);
    notesCollection.addNote(note2);
    bool d = notesCollection.removeNote("title2");
    ASSERT_EQ(1, notesCollection.countNotes());
    ASSERT_FALSE(d);
    bool e = notesCollection.removeNote("title3");
    ASSERT_EQ(1, notesCollection.countNotes());
    ASSERT_FALSE(e);
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
    NotesCollection finalList2("final list 2");
    finalList2 = notesCollection.searchNotes("nota");
    ASSERT_EQ(0, finalList2.countNotes());
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


