#ifndef LIBRARYCATALOG_H
#define LIBRARYCATALOG_H

#include "LibraryItem.h"
#include <vector>
#include <memory>

class LibraryCatalog {
private:
    std::vector<std::shared_ptr<LibraryItem>> items;

public:
    void AddItem(const std::shared_ptr<LibraryItem>& item);
    void PrintCatalog() const;
    void FindByTitle(const std::string& title) const;
    void FindByAuthor(const std::string& author) const;
    void SaveCatalog(const std::string& filename) const;
    void LoadCatalog(const std::string& filename);
};

#endif 
