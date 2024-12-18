#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string author;
    std::string title;
    std::string genre;
    int pages;

public:
    Book() : pages(0) {}
    Book(const std::string& author, const std::string& title, const std::string& genre, int pages);
    std::string GetTitle() const override;
    void PrintInfo() const override;
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};

#endif
