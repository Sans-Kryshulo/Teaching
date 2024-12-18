#include "Book.h"

Book::Book(const std::string& author, const std::string& title, const std::string& genre, int pages)
    : author(author), title(title), genre(genre), pages(pages) {}

std::string Book::GetTitle() const {
    return title;
}

void Book::PrintInfo() const {
    std::cout << "Book: " << title << " by " << author << ", Genre: " << genre << ", Pages: " << pages << std::endl;
}

void Book::Save(std::ostream& os) const {
    os << "Book\n" << author << "\n" << title << "\n" << genre << "\n" << pages << std::endl;
}

void Book::Load(std::istream& is) {
    std::getline(is, author);
    std::getline(is, title);
    std::getline(is, genre);
    is >> pages;
    is.ignore();
}
