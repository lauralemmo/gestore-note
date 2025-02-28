cmake_minimum_required(VERSION 3.24)
project(gestoreNoteLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(gestoreNoteLab main.cpp Note.cpp Note.h Subject.h Observer.h NotesCollection.cpp NotesCollection.h)
