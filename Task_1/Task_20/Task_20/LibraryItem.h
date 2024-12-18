#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

class LibraryItem {
public:
    virtual ~LibraryItem() {}
    virtual std::string GetTitle() const = 0;
    virtual void PrintInfo() const = 0;
    virtual void Save(std::ostream& os) const = 0;
    virtual void Load(std::istream& is) = 0;
};

#endif
