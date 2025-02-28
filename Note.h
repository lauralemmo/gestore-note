
#ifndef GESTORENOTELAB_NOTE_H
#define GESTORENOTELAB_NOTE_H

#include <string>
#include <iostream>
using namespace std;

class Note {
public:
    Note(string title, string text);
    virtual ~Note();

    const string &getTitle() const;
    void setTitle(const string &title);

    const string &getText() const;
    void setText(const string &text);

    bool isBlocked() const;
    void setBlocked(bool blocked);

    bool isImportant() const;
    void setImportant(bool important);

    bool isInCollection() const;
    void setInCollection(bool inCollection);


private:
    string title;
    string text;
    bool blocked = false;
    bool important = false;
    bool inCollection = false;
};


#endif //GESTORENOTELAB_NOTE_H
