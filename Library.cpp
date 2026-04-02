#include <iostream>
#include <vector>

struct Book
{
    std::string genre;
    std::string title;
    std::string author;
    bool isBorrowed = false;
};

void pause()
{
    std::cout << "Press any key to return.";
    std::cin.ignore();
    std::cin.get();
}

void cinfail()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void menu(int &choice, int quit)
{
    bool isvalid = false;
    do
    {
        std::cout << "----------" << '\n';
        std::cout << "1.Add Book" << '\n'
                  << "2.View Books" << '\n'
                  << "3.Search Book" << '\n'
                  << "4.Borrow book" << '\n'
                  << "5.Return book" << '\n'
                  << "6.Quit" << '\n';
        std::cout << "----------" << '\n';
        std::cout << "Enter Choice: ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            cinfail();
        }
        else if (choice > quit || choice < 1)
        {
            std::cout << "Must be between 1-6." << '\n';
        }
        else
        {
            isvalid = true;
        }
    } while (!isvalid);
}

void addbook(std::vector<Book> &Library)
{
    std::string title;
    std::string genre;
    std::string author;
    char addmore;
    do
    {
        std::cout << "----------" << '\n';
        std::cout << "Enter Title: ";
        std::cin >> title;
        std::cout << "Enter Genre: ";
        std::cin >> genre;
        std::cout << "Enter Author: ";
        std::cin >> author;
        std::cout << "----------" << '\n';

        Book book;
        book.genre = genre;
        book.title = title;
        book.author = author;
        Library.push_back(book);

        std::cout << "Add more book? (Y/N): ";
        std::cin >> addmore;
    } while (addmore == 'Y' || addmore == 'y');
}

void viewbook(const std::vector<Book> &library)
{
    for (const Book &book : library)
    {
        std::cout << "----------" << '\n';
        std::cout << book.title << '\n'
                  << book.genre << '\n'
                  << book.author << '\n'
                  << (book.isBorrowed ? "Borrowed" : "Available") << '\n';
        std::cout << "----------" << '\n';
    }
    pause();
}

void searchbook(const std::vector<Book> &library)
{
    bool found = false;
    std::string booktitle;
    std::cout << "----------" << '\n';
    std::cout << "Enter title: ";
    std::cin >> booktitle;
    for (const Book &book : library)
    {

        if (booktitle == book.title)
        {
            std::cout << "----------" << '\n'
                      << book.title << '\n'
                      << book.genre << '\n'
                      << book.author << '\n'
                      << "----------" << '\n';
            found = true;

            pause();
        }
    }
    if (!found)
    {
        std::cout << "Book not found." << '\n';
        pause();
    }
}

void borrowbook(std::vector<Book> &library)
{
    bool found = false;
    std::string booktitle;
    std::cout << "----------" << '\n';
    std::cout << "Enter title: ";
    std::cin >> booktitle;
    std::cout << "----------" << '\n';
    for (Book &book : library)
    {

        if (booktitle == book.title)
        {
            std::cout << "----------" << '\n';
            std::cout << book.title << '\n'
                      << book.genre << '\n'
                      << book.author << '\n';
            found = true;
            std::cout << "Borrow Status: " << std::boolalpha << book.isBorrowed << '\n';
            if (!book.isBorrowed)
            {
                book.isBorrowed = true;
                std::cout << "Successfully borrowed." << '\n';
            }
            else
            {
                std::cout << "Book is not avaliable." << '\n';
            }
            std::cout << "----------" << '\n';
            pause();
        }
    }
    if (!found)
    {
        std::cout << "----------" << '\n';
        std::cout << "Book not found." << '\n';
        std::cout << "----------" << '\n';
        pause();
    }
}

void returnbook(std::vector<Book> &library)
{
    bool found = false;
    std::string booktitle;
    std::cout << "----------" << '\n';
    std::cout << "Enter title: ";
    std::cin >> booktitle;
    std::cout << "----------" << '\n';
    for (Book &book : library)
    {

        if (booktitle == book.title)
        {
            std::cout << "----------" << '\n';
            std::cout << book.title << '\n'
                      << book.genre << '\n'
                      << book.author << '\n';
            found = true;
            std::cout << "Borrow Status: " << std::boolalpha << book.isBorrowed << '\n';
            if (book.isBorrowed)
            {
                book.isBorrowed = false;
                std::cout << "Book is returned." << '\n';
            }
            else
            {
                std::cout << "Book is not borrowed." << '\n';
            }
            std::cout << "----------" << '\n';
            pause();
        }
    }
    if (!found)
    {
        std::cout << "----------" << '\n';
        std::cout << "Book not found." << '\n';
        std::cout << "----------" << '\n';
        pause();
    }
}

int main()
{
    std::vector<Book> library;
    int choice;
    const int quit = 6;
    do
    {
        menu(choice, quit);
        switch (choice)
        {
        case 1:
        {
            addbook(library);
        }
        break;
        case 2:
        {
            viewbook(library);
        }
        break;
        case 3:
        {
            searchbook(library);
        }
        break;
        case 4:
        {
            borrowbook(library);
        }
        break;
        case 5:
        {
            returnbook(library);
        }
        break;
        case 6:
        {
            std::cout << "----------" << '\n';
            std::cout << "Goodbye." << '\n';
            std::cout << "----------" << '\n';
        }
        break;
        default:
        {
            std::cout << "Invalid.";
        }
        break;
        }
    } while (choice != quit);
    return 0;
}