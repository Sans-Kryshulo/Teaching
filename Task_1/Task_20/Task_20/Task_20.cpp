#include "LibraryCatalog.h"
#include "Book.h"
#include "Newspaper.h"
#include "Almanac.h"

int main() {
    LibraryCatalog catalog;

    catalog.AddItem(std::make_shared<Book>("Author1", "Book1", "Genre1", 100));
    catalog.AddItem(std::make_shared<Newspaper>("Newspaper1", "2023-05-30", std::vector<std::string>{"Headline1", "Headline2"}));
    catalog.AddItem(std::make_shared<Almanac>("Almanac1", std::vector<std::string>{"Work1", "Work2"}));
    catalog.PrintCatalog();

    std::cout << "\nSearch by title 'Book1':" << std::endl;
    catalog.FindByTitle("Book1");
    std::cout << "\nSearch by author 'Author1':" << std::endl;
    catalog.FindByAuthor("Author1");
    catalog.SaveCatalog("catalog.txt");

    LibraryCatalog newCatalog;
    newCatalog.LoadCatalog("catalog.txt");
    std::cout << "\nLoaded catalog:" << std::endl;
    newCatalog.PrintCatalog();

    return 0;
}