#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "LibraryItem.h"
#include <vector>

class Newspaper : public LibraryItem {
private:
    std::string title;
    std::string date;
    std::vector<std::string> headlines;

public:
    Newspaper() {}
    Newspaper(const std::string& title, const std::string& date, const std::vector<std::string>& headlines);
    std::string GetTitle() const override;
    void PrintInfo() const override;
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};

#endif
