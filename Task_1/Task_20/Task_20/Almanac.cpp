#include "Almanac.h"

Almanac::Almanac(const std::string& title, const std::vector<std::string>& works)
    : title(title), works(works) {}

std::string Almanac::GetTitle() const {
    return title;
}

void Almanac::PrintInfo() const {
    std::cout << "Almanac: " << title << std::endl;
    std::cout << "Works: ";
    for (const auto& work : works) {
        std::cout << work << "; ";
    }
    std::cout << std::endl;
}

void Almanac::Save(std::ostream& os) const {
    os << "Almanac\n" << title << std::endl;
    os << works.size() << std::endl;
    for (const auto& work : works) {
        os << work << std::endl;
    }
}

void Almanac::Load(std::istream& is) {
    std::getline(is, title);
    size_t works_count;
    is >> works_count;
    is.ignore();
    works.resize(works_count);
    for (size_t i = 0; i < works_count; ++i) {
        std::getline(is, works[i]);
    }
}
