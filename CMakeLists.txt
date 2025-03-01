cmake_minimum_required(VERSION 3.24)
project(gestoreNoteLab)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES ImportantNotesCollection.cpp ImportantNotesCollection.h Note.cpp Note.h NotesCollection.cpp
        NotesCollection.h Observer.h Subject.h User.cpp User.h)

add_executable(gestoreNoteLab main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(gestoreNoteLab core)
