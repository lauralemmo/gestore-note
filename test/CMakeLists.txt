add_subdirectory(./googletest)
set(GTEST_SRC_DIR ./googletest-master/)
include_directories(${GTEST_SRC_DIR}/include ${GTEST_SRC_DIR})

set(TEST RunAllTest.cpp NoteTest.cpp NotesCollectionTest.cpp ImportantNotesCollectionTest.cpp)
add_executable(runAllTest ${TEST})
target_link_libraries(runAllTest gtest gtest_main core)