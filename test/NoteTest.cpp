
#include "gtest/gtest.h"
#include "../Note.h"

#include <iostream>
using namespace std;

TEST(Note, Constructor){
string title = "title";
string text = "text";
Note note(title, text);
ASSERT_FALSE(note.isImportant());
ASSERT_FALSE(note.isBlocked());
}

TEST(Note, getTitle){
string title = "title";
string text = "text";
Note note(title, text);
ASSERT_EQ(title, note.getTitle());
}

TEST(Note, setTitle){
string title = "title";
string text = "text";
Note note(title,text);
note.setBlocked(true);
note.setTitle("new title");
ASSERT_EQ("title", note.getTitle());
note.setBlocked(false);
note.setTitle("new title");
ASSERT_EQ("new title",note.getTitle());
}

TEST(Note, getText){
string title = "title";
string text = "text";
Note note(title, text);
ASSERT_EQ(text, note.getText());
}

TEST(Note, setText){
string title = "title";
string text = "text";
Note note(title,text);
note.setBlocked(true);
note.setText("new text");
ASSERT_EQ("text", note.getText());
note.setBlocked(false);
note.setText("new text");
ASSERT_EQ("new text",note.getText());
}

TEST(Note, isImportant){
string title = "title";
string text = "text";
Note note(title, text);
ASSERT_FALSE(note.isImportant());
}

TEST(Note, setImportant){
string title = "title";
string text = "text";
Note note(title,text);
note.setBlocked(true);
note.setImportant(true);
ASSERT_FALSE(note.isImportant());
note.setBlocked(false);
note.setImportant(true);
ASSERT_TRUE(note.isImportant());
}

TEST(Note, isBlocked){
string title = "title";
string text = "text";
Note note(title, text);
ASSERT_FALSE(note.isBlocked());
}

TEST(Note, setBlocked){
string title = "title";
string text = "text";
Note note(title,text);
note.setBlocked(true);
ASSERT_TRUE(note.isBlocked());
}