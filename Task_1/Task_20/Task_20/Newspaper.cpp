#include "Newspaper.h"

Newspaper::Newspaper(const std::string& title, const std::string& date, const std::vector<std::string>& headlines)
    : title(title), date(date), headlines(headlines) {}

std::string Newspaper::GetTitle() const {
    return title;
}

void Newspaper::PrintInfo() const {
    std::cout << "Newspaper: " << title << ", Date: " << date << std::endl;
    std::cout << "Headlines: ";
    for (const auto& headline : headlines) {
        std::cout << headline << "; ";
    }
    std::cout << std::endl;
}

void Newspaper::Save(std::ostream& os) const {
    os << "Newspaper\n" << title << "\n" << date << std::endl;
    os << headlines.size() << std::endl;
    for (const auto& headline : headlines) {
        os << headline << std::endl;
    }
}

void Newspaper::Load(std::istream& is) {
    std::getline(is, title);
    std::getline(is, date);
    size_t headlines_count;
    is >> headlines_count;
    is.ignore();
    headlines.resize(headlines_count);
    for (size_t i = 0; i < headlines_count; ++i) {
        std::getline(is, headlines[i]);
    }
}
