#ifndef ALMANAC_H
#define ALMANAC_H

#include "LibraryItem.h"
#include <vector>

class Almanac : public LibraryItem {
private:
    std::string title;
    std::vector<std::string> works;

public:
    Almanac() {}
    Almanac(const std::string& title, const std::vector<std::string>& works);
    std::string GetTitle() const override;
    void PrintInfo() const override;
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};

#endif
