#include "LibraryCatalog.h"
#include "Book.h"
#include "Newspaper.h"
#include "Almanac.h"
#include <fstream>

void LibraryCatalog::AddItem(const std::shared_ptr<LibraryItem>& item) {
    items.push_back(item);
}

void LibraryCatalog::PrintCatalog() const {
    for (const auto& item : items) {
        item->PrintInfo();
    }
}

void LibraryCatalog::FindByTitle(const std::string& title) const {
    for (const auto& item : items) {
        if (item->GetTitle() == title) {
            item->PrintInfo();
        }
    }
}

void LibraryCatalog::FindByAuthor(const std::string& author) const {
    for (const auto& item : items) {
        const Book* book = dynamic_cast<const Book*>(item.get());
        if (book && book->GetTitle() == author) {
            book->PrintInfo();
        }
    }
}

void LibraryCatalog::SaveCatalog(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& item : items) {
        item->Save(ofs);
    }
}

void LibraryCatalog::LoadCatalog(const std::string& filename) {
    std::ifstream ifs(filename);
    std::string type;
    while (std::getline(ifs, type)) {
        std::shared_ptr<LibraryItem> item;
        if (type == "Book") {
            item = std::make_shared<Book>();
        }
        else if (type == "Newspaper") {
            item = std::make_shared<Newspaper>();
        }
        else if (type == "Almanac") {
            item = std::make_shared<Almanac>();
        }
        if (item) {
            item->Load(ifs);
            items.push_back(item);
        }
    }
}
